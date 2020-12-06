#include"huffman_tree.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void  HuffmanCoding(HuffmanTree  &HT,HuffmanCode  &HC, unsigned int *w,  int  n)
{
    
     int  m,i,s1 = 1 ,s2 = 1 ,f,c,start;
     char   * cd;
    HuffmanTree p;
     if (n <= 1 )  return ;
    m = 2 * n - 1 ;
    HT = (HuffmanTree)malloc((m + 1 ) * sizeof (HTNode));    // 0号单元未用
     for (p = HT + 1 ,i = 1 ;i <= n; ++ i, ++ p, ++ w)
        {
             // *p={*w,0,0,0};
            p -> weight =* w;      
            ( * p).parent = 0 ;      
            ( * p).lchild = 0 ;
            ( * p).rchild = 0 ;
        }            
     for (;i <= m; ++ i)
        {
             // *p={0,0,0,0};
            ( * p).weight =* w;
            ( * p).parent = 0 ;
            ( * p).lchild = 0 ;
            ( * p).rchild = 0 ;
        }
        
     for (i = n + 1 ;i <= m; ++ i)
    {
        Select(HT,i - 1 ,s1,s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild = s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }
    
    HC = (HuffmanCode)malloc((n + 1 ) * sizeof ( char * ));
    cd = ( char * )malloc(n * sizeof ( char ));             // 这里开辟一个较大的空间，因为长度不可能超过n
    cd[n - 1 ] = '\0' ;
     for (i = 1 ;i <= n; ++ i)
    {
        start = n - 1 ;
         for (c = i,f = HT[i].parent;f != 0 ;c = f,f = HT[f].parent)
             if (HT[f].lchild == c)
                cd[ -- start] = '0' ;
             else if(HT[f].rchild == c)
                cd[ -- start] = '1' ;
        HC[i] = ( char * )malloc((n - start) * sizeof ( char ));          //这里开辟编码长度的空间
        strcpy(HC[i], & cd[start]);                     //这里从cd数组的中间已经编码的元素开始拷贝
    }
    free(cd);
}


void  Select(HuffmanTree HT, int  i,  int   & s1,  int   & s2)
{
     int  j;
     int  min = 1000;
     for (j = 1 ;j < i;j ++ )
    {
         if (HT[j].weight <= min && HT[j].parent == 0 )
        {    min = HT[j].weight;
            s1 = j;
        }
    }
    
    min = 1000;
     for (j = 1 ;j < i;j ++ )
    {
         if ((HT[j].weight <= min) && (j != s1) && HT[j].parent == 0 )
        {
            min = HT[j].weight;
            s2 = j;
        }
    }
}