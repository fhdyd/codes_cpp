#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 40                       	 //班级总人数
int idinformation[N+1]= {0};          //用于判断学生id是否重复的数组
int currentnum=0;                           //现在系统里共有多少人
class student					//名为student的类 
{
public:
    student()                           //默认构造函数
    {
        score=0;
        finalscore=0;
        id=-1;
        mark=0;
        char a[32]="";
        strcpy(name,a);
    }
    void kill()
    {
        idinformation[id]=0;    //删除信息
        score=0;
        finalscore=0;
        id=-1;
        char a[32]="";
        strcpy(name,a);
        mark=0;
        currentnum--;
    }
    void inputid()                      //输入学号
    {
        int num;
        while(1)
        {
            cout<<"请输入学号(1-40): ";


            cin>>num;
            if(idinformation[num]==1)
            {
                cout<<"该学号已经存在！"<<endl;
                continue;
            }
            if(num>=1&&num<=N)
            {
                id=num;
                idinformation[num]=1;
                break;
            }
            cout<<"error！"<<endl;
        }
    }
    void inputscore()                   //输入平时成绩
    {
        double num;
        while(1)
        {
            cout<<"请输入平时成绩(0-100): ";


            cin>>num;
            if(num>=0&&num<=100)
                break;
            cout<<"error！"<<endl;
        }
        score=num;
       //mark=finalscore*0.5+score*0.5;              //计算总评 
    }
    void inputfinalscore()                  //输入期末成绩
    {
        double num;
        while(1)
        {
            cout<<"请输入期末成绩(0-100): ";

            cin>>num;
            if(num>=0&&num<=100)
                break;
            cout<<"error！"<<endl;
        }
        finalscore=num;
        mark=finalscore*0.5+score*0.5;      //计算总评 
    }
    void inputname()                //输入学生姓名
    {
        char a[32];
        cout<<"请输入姓名：";
        cin>>a;
        strcpy(name,a);
    }
    void outid()                    //输出学号
    {
        cout<<setw(10)<<id;
    }
    void outscore()                 //输出平时成绩
    {
        cout<<setw(10)<<fixed<<setprecision(1)<<score;
    }
    void outfinalscore()            //输出期末成绩
    {
        cout<<setw(10)<<fixed<<setprecision(1)<<finalscore;
    }
    void outname()              //输出姓名
    {
        cout<<setw(10)<<name;
    }
    double outmark()                //输出总成绩
    {
        cout<<setw(10)<<fixed<<setprecision(1)<<(score*0.5+finalscore*0.5);
    }
    double mark;
    double score;
    double finalscore;
    int id;
    char name[32];
};
student stu[N];         //创立一个班（40人）大小的对象数组
bool compare(const student &a,const student &b) //对象数组排序用函数
{
    if(a.score==b.score)
        return a.id>b.id;
    if(a.finalscore==b.finalscore)
        return a.score>b.score;
    if(a.mark==b.mark)
        return a.finalscore>b.finalscore;
    return a.mark>b.mark;
}
void showmenu()
{
    cout<<endl;
    cout<<"1=录入学生                   2=显示信息"<<endl;
    cout<<"3=排序总评                   4=查找学生"<<endl;
    cout<<"5=插入学生                   6=删除学生"<<endl;
    cout<<"7=统计人数                   0=退出    "<<endl;
   
    cout<<endl<<"请选择:"<<endl;
}
void case1()						//录入信息 
{
    char keepgoing;
    while(1)
    {
        if(currentnum>=N)
        {
            cout<<"error！"<<endl;
            break;
        }
        stu[currentnum].inputid();
        stu[currentnum].inputname();
        stu[currentnum].inputscore();
        stu[currentnum++].inputfinalscore();
        cout<<endl<<"请选择（输入y或Y继续输入数据 否则跳出）:"<<endl;
        cin>>keepgoing;
        if(keepgoing!='y'&&keepgoing!='Y')
        {
            break;
        }
    }
}
void case2()					//显示所有信息 
{
    int temp;
    temp=1;
    for(int e=0; e<N; e++)
        if(strcmp(stu[e].name,"")!=0)
        {
            temp=0;
            break;
        }
    if(temp==0)
    {
        cout<<"              学号                  姓名              平时                期末               总评"<<endl;
        for(int e=0; e<N; e++)
            if(strcmp(stu[e].name,"")!=0)
            {
                cout<<"        ";
                stu[e].outid();
                cout<<"           ";
                stu[e].outname();
                cout<<"          ";
                stu[e].outscore();
                cout<<"         ";
                stu[e].outfinalscore();
                cout<<"         ";
                stu[e].outmark();
                cout<<endl;
            }
    }
    else
        cout<<"error！"<<endl;
}
void case3()				//排序 
{
    int temp;
    temp=1;
    for(int e=0; e<N; e++)
        if(strcmp(stu[e].name,"")!=0)
        {
            temp=0;
            break;
        }
    if(temp==0)
    {
        student *p;
        p=new student[N];
        p=(student*)calloc(N,sizeof(student));

        for(int e=0; e<N; e++)
            p[e]=stu[e];                        //为保护原对象数组，这里的排序输出使用一个新对象数组

        sort(p+0,p+N,compare);
        cout<<"              学号                  姓名              平时                期末               总评"<<endl;
        for(int e=0; e<N; e++)
            if(p[e].score!=0)
            {
                cout<<"        ";
                p[e].outid();
                cout<<"           ";
                p[e].outname();
                cout<<"          ";
                p[e].outscore();
                cout<<"         ";
                p[e].outfinalscore();
                cout<<"         ";
                p[e].outmark();
                cout<<endl;
            }
        delete[] p;
    }
    else
        cout<<"error！"<<endl;
}
void case4()								//查找 
{
    char keepgoing;
    while(1)
    {
        cout<<"请输入您要查找的学号：";
        int temp;
        int temp2=1;
      
        cin>>temp;
        for(int e=0; e<N; e++)
            if(stu[e].id==temp)
            {
                cout<<"              学号                  姓名              平时                期末               总评"<<endl;
                cout<<"        ";
                stu[e].outid();
                cout<<"           ";
                stu[e].outname();
                cout<<"          ";
                stu[e].outscore();
                cout<<"         ";
                stu[e].outfinalscore();
                cout<<"         ";
                stu[e].outmark();
                cout<<endl;
                temp2=0;
                break;
            }
        if(temp2)								//两个if函数只会同时执行一个 
            cout<<"error！"<<endl;
        cout<<endl<<"请选择（输入y或Y继续输入数据 否则跳出）:"<<endl;
        cin>>keepgoing;
        if(keepgoing!='y'&&keepgoing!='Y')
        {
            break;
        }
    }
}
void case6()									//删除 
{
    char keepgoing;
    while(1)
    {
        cout<<"请输入要删除信息的学生学号：";
        int temp;
        int temp2=1;
        cin>>temp;
        for(int e=0; e<N; e++)
        {
            if(stu[e].id==temp)
            {
                stu[e].outid();
                cout<<"号删除学生信息成功！";
                stu[e].kill();
                temp2=0;
                break;
            }
        }
        if(temp2)						//两个if函数只会同时执行一个 
            cout<<"error！"<<endl;
        cout<<endl<<"请选择（输入y或Y继续删除数据 否则跳出）:"<<endl;
        cin>>keepgoing;
        if(keepgoing!='y'&&keepgoing!='Y')
        {
            break;
        }
    }
}
void case7()
{
    int people[5];
    for(int e=0; e<5; e++)
        people[e]=0;
    for(int e=0; e<N; e++)
        if(strcmp(stu[e].name,"")!=0)
        {
            if(stu[e].mark>=90)
                people[0]++;
            else if(stu[e].mark>=80)
                people[1]++;
            else if(stu[e].mark>=70)
                people[2]++;
            else if(stu[e].mark>=60)
                people[3]++;
            else
                people[4]++;
        }
    cout<<"      [90,100]      [80,90)      [70,80)    [60,70)     [0,60)"<<endl;
    cout<<setw(12)<<people[0]<<setw(12)<<people[1]<<setw(12)<<people[2]<<setw(12)<<people[3]<<setw(12)<<people[4];
}
int main(void)
{
    int choice;
    while(1)
    {
        showmenu();
        while(1)
        {
            cin>>choice;
            if(choice>=0&&choice<8)
                break;
            cout<<"error！"<<endl;
            showmenu();
        }
        switch(choice)					//跳转 
        {
        case 1:
            cout<<"您选择了1=录入学生"<<endl;
            case1();
            break;
        case 2:
            cout<<"您选择了2=显示信息"<<endl;
            case2();
            break;

        case 3:
            cout<<"您选择了3=排序总评"<<endl;
            case3();
            break;

        case 4:
            cout<<"您选择了4=查找学生"<<endl;
            case4();
            break;

        case 5:						//输入5和1都跳转到case1 
            cout<<"您选择了5=插入学生"<<endl;
            case1();
            break;

        case 6:
            cout<<"您选择了6=删除学生"<<endl;
            case6();
            break;
        case 7:
            cout<<"您选择了7=统计人数"<<endl;
            case7();
            break;
        case 0:

            break;
        }
    }
    return 0;
}
