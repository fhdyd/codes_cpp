
#include "func.cpp"

int main(){
    BiTree T;
    CreateTree_Preorder(T);
    cout << "递归中序遍历：" << endl;
    InOrderTraverse_recur(T, PrintElement);
    cout << endl;
    cout << "递归先序遍历：" << endl;
    PreOrderTraverse(T, PrintElement);
    cout << endl;
    cout << "非递归中序遍历：" << endl;
    InOrderTraverse2(T, PrintElement);
    cout << endl;
    InOrderTraverse3(T, PrintElement);
    cout << endl;
    deleteTree(T);
    cout << "树已销毁！";
}