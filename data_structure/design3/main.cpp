//main.cpp
#include"head.h"

int main()
{
	ALGraph G;
	CreateUDG(G);
	printGraph(G);
    TopologicalSort(G, topo);
	//关键路径
	CriticalPath(G);
	cout << "最短开发周期为：" << vl[G.vexnum - 1] << endl;
    cout << "每条弧的最早发生时间：" << endl;
	for (int i = 0; i <G.vexnum; i++)
	{
		ArcNode *p = G.vertices[i].firstarc;
		while(p){
			cout << G.vertices[i].data << "->" << G.vertices[p->adjvex].data << ":" ;
			cout << ve[i] << endl;
			p = p->nextarc;
		}
	}
	cout << "每条弧的最晚发生时间：" << endl;
	for (int i = 0; i <G.vexnum; i++)
	{
		ArcNode *p = G.vertices[i].firstarc;
		while(p){
			int rear;
			rear = LocateVex(G, G.vertices[p->adjvex].data);
			cout << G.vertices[i].data << "->" << G.vertices[p->adjvex].data << ":" ;
			cout << vl[rear] - p->weight << endl;
			p = p->nextarc;
		}
	}
}