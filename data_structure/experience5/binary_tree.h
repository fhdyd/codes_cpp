//
// binary_tree.h
// Created by finn33 on 2020/10/28.
//

#ifndef LST_BINARY_TREE_BINARY_TREE_H
#define LST_BINARY_TREE_BINARY_TREE_H
typedef int Status;
typedef char TElemType;
#define OK 1
#define ERROR 0

typedef struct BiTNode{ // 结点结构
    TElemType      data;
    struct BiTNode  *leftchild, *rightchild;
    // 左右孩子指针
} BiTNode, *BiTree;

Status CreateTree_Preorder(BiTree &T);
//先序遍历形式创造树

Status PrintElement( TElemType e );
//打印元素

Status InOrderTraverse_recur(BiTree T, Status (*Visit)(TElemType));
//中序遍历二叉树，对每个结点采用visit操作

Status PreOrderTraverse(BiTree T, Status (*Visit)(TElemType));
//先序遍历二叉树

Status InOrderTraverse2(BiTree T, Status (*Visit)(TElemType));
//利用栈来进行中序遍历

Status InOrderTraverse3(BiTree T, Status (*Visit)(TElemType));

Status deleteTree(BiTree &t);
//后序遍历销毁树

#endif //LST_BINARY_TREE_BINARY_TREE_H