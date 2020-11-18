//
// func.cpp
// Created by finn33 on 2020/10/28.
//
#include "iostream"
#include "binary_tree.h"
#include "stdlib.h"
#include "stack.h"
using namespace std;


Status CreateTree_Preorder(BiTree &T){
    TElemType ch;
    cin >> ch;
    if(ch == '#'){
        T = NULL;
    }
    else{
        T = (BiTNode*)malloc(sizeof(struct BiTNode));
        if(!T){
            return ERROR;
        }
        //内存申请失败
        T->leftchild = T->rightchild = NULL;
        T->data = ch;
        CreateTree_Preorder(T->leftchild);
        CreateTree_Preorder(T->rightchild);
    }
    return OK;
}
//如果不传T的地址即指针的指针，函数改变的只是形参的值，实参并未被修改


Status PrintElement(TElemType ch){
    cout << ch << ' ';
    return OK;
}


Status InOrderTraverse_recur(BiTree T, Status (*Visit)(TElemType)){
    if(!T)return OK;
    else{
        InOrderTraverse_recur(T->leftchild, Visit);
        Visit(T->data);
        InOrderTraverse_recur(T->rightchild, Visit);
    }
    return OK;
}
//递归方式遍历树，对于每个节点来说，先遍历左子树再访问该节点，最后遍历右子树


Status PreOrderTraverse(BiTree T, Status (*Visit)(TElemType)){
    if(!T)return OK;
    else{
        Visit(T->data);
        PreOrderTraverse(T->leftchild, Visit);
        PreOrderTraverse(T->rightchild, Visit);
    }
    return OK;
}


Status InOrderTraverse2(BiTree T, Status (*Visit)(TElemType)){
    Stack s;
    initStack(s);
    BiTree temp;
    push(s, T);
    while(!isEmpty(s)){
        while(temp = top(s)){
            push(s, temp->leftchild);
            }//进到树最左边
        pop(s);//空指针出栈，现在栈顶是最左边的叶子节点
        if(!isEmpty(s)){
            temp = top(s);
            pop(s);
            Visit(temp->data);//访问栈顶节点
            push(s, temp->rightchild);//栈顶节点的右儿子入栈
        }
    }
    free(s.base);
    return OK;
}


Status InOrderTraverse3(BiTree T, Status (*Visit)(TElemType)){
    BiTree temp = T;
    Stack s;
    initStack(s);
    while(temp || !isEmpty(s)){//如果栈非空或者待判断指针不是空指针
        if(temp){
            push(s, temp);
            temp = temp->leftchild;
        }
        else{//栈非空
            temp = top(s);
            pop(s);
            Visit(temp->data);
            temp = temp->rightchild;
        }
    }
    free(s.base);
    return OK;
}


Status deleteTree(BiTree &t){
    if(!t)return OK;
    else{
        deleteTree(t->leftchild);
        deleteTree(t->rightchild);
        free(t);
    }
    return OK;
}//删除节点只能后序遍历