//
// stack.h
// Created by finn33 on 2020/10/31.
//
#ifndef LST_BINARY_TREE_STACK_H
#define LST_BINARY_TREE_STACK_H
#include "binary_tree.h"
#include <stdlib.h>


typedef struct {
    BiTree* top,*base;
    int size;
}Stack;


Status initStack(Stack &S){
    S.base = (BiTree*)malloc(sizeof(BiTNode) * 100);
    if(!S.base)return ERROR;
    S.top = S.base;
    S.size = 100;
    return OK;
}


bool isEmpty(Stack S){
    if(S.base == S.top)return true;
    return false;
}


void push(Stack &S, BiTree T){
    *S.top = T;
    S.top++;
}


void pop(Stack &S){
    S.top--;
}


BiTree top(Stack &S){
    BiTree* ptr = S.top;
    ptr--;
    return *ptr;
}


#endif //LST_BINARY_TREE_STACK_H