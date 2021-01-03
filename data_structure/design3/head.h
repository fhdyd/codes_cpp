#include<stdio.h>
#include<iostream>
using namespace std;
#define MVNum 100
typedef char OtherInfo;
typedef char elemtype;

//图的邻接表存储结构
typedef struct ArcNode			//边结点
{
	int adjvex;//邻接点域 
	struct ArcNode *nextarc;//链域
	OtherInfo info;//数据域
	int weight;	//权值
}ArcNode;
typedef struct VNode			//顶点信息
{
	elemtype data;//数据域
	ArcNode *firstarc;//链域
}VNode, AdjList[MVNum];
typedef struct                  //邻接表
{
	AdjList vertices;
	int vexnum, arcnum;
}ALGraph;

//函数声明
int LocateVex(ALGraph G, char v);
void LinkAL(ALGraph &G, int i, int j, int weight);
void FindInDegree(ALGraph G, int indegree[]);
void printTopo(int topo[], int m);


//邻接表创建有向图
void CreateUDG(ALGraph &G)
{
    cout << "请输入图的顶点数：" << endl;
    cin >> G.vexnum;
    cout << "请输入图的边数：" << endl;
    cin >> G.arcnum;
    int i;
    for(i = 0; i < G.vexnum; i++){
        G.vertices[i].data = 'A' + i;
        G.vertices[i].firstarc = NULL;
    }
    cout << "请输入每边的两个顶点和边的权值：" << endl;
    for(i = 0; i < G.arcnum; i++){
        int p, q, weight;
        elemtype P,Q;
        cin >> P >> Q >> weight;
        p = LocateVex(G, P);
        q = LocateVex(G, Q);
        LinkAL(G, p, q, weight);
    }
}

//建立边
void LinkAL(ALGraph &G, int i, int j, int weight)
{

	ArcNode *p1;
	p1 = new ArcNode;
	p1->adjvex = j;
	p1->nextarc = G.vertices[i].firstarc;						  //头插法
	G.vertices[i].firstarc = p1;

	p1->weight = weight;
}

//返回顶点位置下标
int LocateVex(ALGraph G, char v)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		if (G.vertices[i].data == v)
		{
			return i;
		}
	}
}

//打印输出图
void printGraph(ALGraph G)
{
	cout << "输出邻接表：" << endl;
	for (int i = 0; i < G.vexnum; i++)
	{
		printf("%d :", i);
        cout << G.vertices[i].data << "->";

		ArcNode *p;
		p = G.vertices[i].firstarc;
		while (p != NULL)
		{
			printf("%c->", G.vertices[p->adjvex].data);
			p = p->nextarc;
		}
		cout << endl;
	}
}



//定义栈
#define MAXSIZE 100
typedef struct
{
	int base[MAXSIZE];
	int *top;
	int stacksize;
}SqStack;
//初始化
int InitStack(SqStack &S)
{
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return 1;
}
//入栈
int Push(SqStack &S, int e)
{
	if (S.top - S.base == S.stacksize) return 0;
	*S.top++ = e;
	return 1;
}
//出栈
int Pop(SqStack &S, int &e)
{
	if (S.top == S.base) return 0;
	e = *--S.top;
	return 1;
}


//拓扑排序
int indegree[MVNum];		//存放各顶点入度
int topo[MVNum];			//存放拓扑序列的顶点序号
SqStack S;					//暂存入度为0的顶点
int TopologicalSort(ALGraph G, int topo[])
{
	ArcNode *p;
	int i, m = 0;				//m用来计数
	FindInDegree(G, indegree);	//求各顶点的入度存入indegree数组
	InitStack(S);
	for (i = 0; i < G.vexnum; i++)
	{
		if (!indegree[i])
		{
			Push(S, i);			//入度为0的入栈
		}
	}

	while (S.base != S.top)
	{
		Pop(S, i);
		topo[m] = i;		//入度为0的出栈并存入topo数组中
		m++;				//计数加一
		p = G.vertices[i].firstarc;		//p指向后继边结点
		while (p != NULL)
		{
			int k = p->adjvex;			//k为顶点下标值
			--indegree[k];				//顶点的入度减1来代替删除边的操作
			if (indegree[k] == 0)		//如果减1后为0 则入栈
			{
				Push(S, k);
			}
			p = p->nextarc;				//继续下一个后继边结点
		}
	}

	if (m < G.vexnum)  return 0;		//输出的顶点数小千有向图中的顶点数，则说明有向图中存在环
	else return m;						//否则投拓扑排序成功，无环
}

//求各顶点的入度
void FindInDegree(ALGraph G, int indegree[])
{
	//初始化
	for (int i = 0; i < G.vexnum; i++)
	{
		indegree[i] = 0;
	}

	ArcNode *p;
	//遍历整个邻接表求出入度
	for (int j = 0; j < G.vexnum; j++)
	{
		p = G.vertices[j].firstarc;
		while (p != NULL)
		{
			indegree[p->adjvex]++;
			p = p->nextarc;
		}
	}
}


//关键路径算法
int ve[MVNum];				//事件最早发生时间
int vl[MVNum];				//事件最晚发生时间
int CriticalPath(ALGraph G)
{
	//初始化最早发生时间为最小
	int n, i;
	if (!TopologicalSort(G, topo))   return 0;		//拓扑排序失败，有环！
	n = G.vexnum;
	for (i = 0; i < n; i++)
	{
		ve[i] = 0;
	}

	//求每个事件最早发生时间
	ArcNode *p;
	int k, j;
	for (i = 0; i < n; i++)
	{
		k = topo[i];
		p = G.vertices[k].firstarc;
		while (p != NULL)
		{
			j = p->adjvex;
			if (ve[j]<ve[k] + p->weight)		//更新顶点的最早方式时间即最大的weight活动
			{
				ve[j] = ve[k] + p->weight;		//第一个顶点的最早发生时间ve[0]==0；
			}
			p = p->nextarc;
		}
	}

	//初始化最晚发生时间为最大
	for (i = 0; i < n; i++)
	{
		vl[i] = ve[n - 1];
	}

	//逆拓扑排序求最迟发生时间
	for (i = n - 1; i >= 0; i--)				//从倒数第二个顶点开始
	{
		k = topo[i];
		p = G.vertices[k].firstarc;
		while (p != NULL)
		{
			j = p->adjvex;
			if (vl[k]>vl[j] - p->weight)
			{
				vl[k] = vl[j] - p->weight;
			}
			p = p->nextarc;
		}
	}


	//判断是否为关键路径
	printf("\n一旦延期将影响开发进度的全部路径：");
	int e, l;
	for (i = 0; i < n; i++)
	{
		p = G.vertices[i].firstarc;
		while (p != NULL)
		{
			j = p->adjvex;
			e = ve[i];
			l = vl[j] - p->weight;
			if (e == l)		//相等则为关键活动，输出对应的关键路径
			{
				printf("\n%c->%c ", G.vertices[i].data, G.vertices[j].data);
			}
			p = p->nextarc;
		}
	}
	cout << endl;
}