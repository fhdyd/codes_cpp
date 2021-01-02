//main.cpp
#include"head.h"

int main(){
    Graph G;
    CreateGraph(&G);
    printf("Depth First Search:\n");
    DFSTraverse(G);
    printf("\nBreadth First Search:\n");
    BFSTraverse(G);
    printf("\n");
}