#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef char * *HuffmanCode;


typedef struct //字符频度表 
{
	int weight; //权值 
	char c; //对应字符 
}F_W;
F_W w[100];//字符频度存放数组


typedef struct
{ int weight; //权值 
  int parent,lchild,rchild;//双亲及左右孩子	
  char c; //对应字符 
 }HTNode,*HuffmanTree;
char S1[1000];


int char_count(string s,char a);//计算字符频度
void create_w(string s); //创建字符频度表w 
void Select(HuffmanTree HT,int j,int &s1,int &s2); //在所有的字符节点中挑选两个权值最小的赋值给s1,s2
int Init(HuffmanTree &HT,F_W *w,int n); //初始化赫夫曼树 
int CreateTable(HuffmanCode &HC,HuffmanTree HT,int n);  //创建编码表 对每个字符进行编码