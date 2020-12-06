#include"huffman_tree.h"


void Select(HuffmanTree HT,int j,int &s1,int &s2) //在所有的字符节点中挑选两个权值最小的赋值给s1,s2 
{ int i,k,min1=0,min2=0;
  for(i=1;i<=j;i++)
  { if(HT[i].parent!=0) //如果节点已经有双亲则不算在比较范围内 
    continue;
    if(HT[min1].weight>HT[i].weight)
     min1=i; 
	}
  for(k=1;k<=j;k++)
    { if(HT[k].parent!=0) //如果节点已经有双亲则不算在比较范围内 
      continue;
	  if(k==min1)  //如果循环到min1直接跳到下一个，不能让min1的值与min2的值相等 
         continue;
       if(HT[min2].weight>HT[k].weight)
       {
         min2=k;
	   }
	}
	s1=min1;
	s2=min2;
}


int Init(HuffmanTree &HT,F_W *w,int n) //初始化赫夫曼树 
{ if(n<=1)
    return 0;
  int m=2*n-1,i; //m表示总结点数
  int s1,s2; //存储最小两节点的变量
  HuffmanTree p; 
  HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));//0号不启用 
  HT[0].weight=999;//默认0号为最大权值，为上面的min1,min2的默认值 
  for(p=HT+1,i=1;i<=n;i++,p++,w++)  //将n个字符所对应的单个根节点赋予权值 
  {  p->lchild=p->rchild=p->parent=0;
     p->weight=w->weight;
     p->c=w->c;
  }
  for(;i<=m;i++) //将剩下的分支节点置为空 
  p->lchild=p->rchild=p->parent=p->weight=0;
  for(i=n+1;i<=m;i++) //建立赫夫曼树
  { Select(HT,i-1,s1,s2); //选出两个最小的节点 
    HT[s1].parent=HT[s2].parent=i;
	HT[i].lchild=s1;HT[i].rchild=s2;
	HT[i].weight=HT[s1].weight+HT[s2].weight;   //权值合并为一个新节点 
	HT[i].parent=0;	
   } 
  return 1; 
 } 


 int CreateTable(HuffmanCode &HC,HuffmanTree HT,int n)  //创建编码表 对每个字符进行编码
{ HC=(HuffmanCode)malloc((n+1)*sizeof(char *));
  char *cd=(char *)malloc(n*sizeof(char));
  cd[n-1]='\0';
  int start,c,i,f;
  for(i=1;i<=n;++i)
  {  start=n-1; //编码结束符位置
     for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
	   if(HT[f].lchild==c) cd[--start]='0';  //左分支设置0右分支设置1 
	   else cd[--start]='1'; 
	HC[i]=(char *)malloc((n-start)*sizeof(char)); 
    strcpy(HC[i],&cd[start]);
   } 
	free(cd);
	return 1;
 } 

