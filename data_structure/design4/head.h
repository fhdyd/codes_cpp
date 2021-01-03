#include<iostream>
using namespace std;
#define MAXSUM 100
typedef char elemtype;
typedef struct{
    int no;//编号
    elemtype from, to;//起始节点
    int weight;//权值
}ArcCell, ArcList[MAXSUM];

//输入弧信息,返回边数
int create(ArcCell *A){
    cout << "请输入图的边数：" << endl;
    int arcsum;
    cin >> arcsum;
    cout << "请输入每条边的起始点和边的权值：" << endl;
    for(int i = 0; i < arcsum; i++){
        cin >> A[i].from >> A[i].to >> A[i].weight;
        A[i].no = i + 1;
    }
    return arcsum;
}

//从0开始
void HeapAdjust(ArcCell *a,int i,int len, int model)//model模式选择 0从小到大1从大到小
{
    while( 2*i+1 < len )// 有左儿子
    {
        int maxindex=2*i+1; //将最大的下标初始化为左儿子下标
        if(2*i+2<len)//有右儿子
        {
            if(model){
                if(a[2*i+1].weight<a[2*i+2].weight)
                {
                    maxindex=2*i+2;
                }
            }
            else
            {
                if(a[2*i+1].weight>a[2*i+2].weight)
                maxindex=2*i+2;
            }
            
        }
        if(model){
            if(a[i].weight<a[maxindex].weight)
            {
                ArcCell temp;
                temp = a[i];
                a[i] = a[maxindex];
                a[maxindex] = temp;
                //交换i与maxindex的数据
                i=maxindex;
            }
            else
            {
                //比较左右孩子均大则堆未破坏，不再需要调整 
                break;
            }
            }
        else{
            if(a[i].weight>a[maxindex].weight)
            {
                ArcCell temp;
                temp = a[i];
                a[i] = a[maxindex];
                a[maxindex] = temp;
                //交换i与maxindex的数据
                i=maxindex;
            }
            else
            {
                //比较左右孩子均大则堆未破坏，不再需要调整 
                break;
            }
        }
    }
    return;
}
//堆排序
void HeapSort(ArcCell *a,int len)
{
    int i=0;
    int model;
    cout << "输入查找模式：(0查找最小, 1查找最大)";
    cin >> model;
    cout << "输入要输出前几个数：" ;
    int num;
    cin >> num;
    for(i=len/2-1;i>=0;i--)//从后起第一个有儿子的节点开始
    {
        //调用构建大顶堆函数
        HeapAdjust(a, i, len, model);
    }
    //只需做n-1趟排序
    int record =0;
    for(i=len-1;i>0&&record < num;i--,record++)
    {
        //将字最大的记录a[0](即堆顶)和无序区的最后一个记录a[n]交换
        ArcCell temp;
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        //将a[0..i]重新调整为大顶堆
        HeapAdjust(a, 0, i, model);
    }
    for(i = len - 1; i > len - 1 - num; i--){
        cout << a[i].no << " " << a[i].from << "->" << a[i].to << " " << a[i].weight << endl;
    }
    return;
}