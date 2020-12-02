#include"huffman_tree.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int n){
    //w为存放各字符权值的数组
    if(n <= 1)return ;
    int m;
    m = 2 * n - 1;
    int i;
    HuffmanTree p = HT;
    HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));//+1因为0号不使用
    for(p = HT, i = 1; i <= n; i++, p++, w++){
        *p = {*w, 0, 0, 0};
    }
    for(; i <= m; i++, p++){
        *p = {0, 0, 0, 0};
    }
    for(i = n + 1; i <= m; i++){
        int s1, s2;
        Select(HT, i - 1, s1, s2);
        HT[s1].parent = i;
        HT[s2].parent = i;
        HT[i].lchild = s1;
        HT[i].rchild =s2;
        HT[i].weight = HT[s1].weight + HT[s2].weight;
    }//建树
    HC = (HuffmanCode)malloc(sizeof(char*) * (n + 1));
    char* cd;
    cd = (char *)malloc(n * sizeof(char));
    cd[n - 1] = '\0';
    for(i = 1; i <= n; i++){
        int start = n - 1;
        int c;
        unsigned int f;
        for(c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent){
            if(HT[f].lchild == c)cd[--start] = '0';
            else cd[--start] = '1';
        }
        HC[i] = (char*)malloc((n - start) * sizeof(char));
        strcpy(HC[i], &cd[start]);
    }
    free(cd);
}


void Select(HuffmanTree HT, int n, int &s1, int &s2){
    int i;
    s1 = s2 = 1;
    for(i = 1; i <= n; i++){
        if(HT[i].parent == 0){
            if(HT[i].weight < HT[s1].weight){
                s2 = s1;
                s1 = i;
            }
            else if(HT[i].weight >= HT[s1].weight && HT[i].weight < HT[s2].weight)s2 = i;
        }   
    }
}