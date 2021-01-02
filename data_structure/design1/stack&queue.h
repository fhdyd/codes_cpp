//stackqueue.h
#include<iostream>
using namespace std;
#define stacksize 100
#define queuesize 100
typedef char datatype;


//定义队列
typedef struct
{
    char data[100];
    int front,rear;
}seqqueue;

//定义栈
typedef struct
{
    datatype data[100];
    int top;
}seqstack;

//初始化队列
void initqueue(seqqueue *q)
{
    q->front=0;
    q->rear=0;
}

//队列是否为空
int queueempty(seqqueue *q)
{
    if(q->front==q->rear)
        return 1;
    else
        return 0;
}

//入队列
void enqueue(seqqueue *q,datatype x)
{
    if((q->rear+1)%queuesize==q->front)
        cout<<"queue overflow"<<endl;
    else
    {
        q->data[q->rear]=x;
        q->rear=(q->rear+1)%queuesize;
    }
}

//出队列
datatype dequeue(seqqueue *q)
{
    if(q->front==q->rear)
        cout<<"queue empty"<<endl;
    else
    {
        datatype x;
        x=q->data[q->front];
        q->front=(q->front+1)%queuesize;
        return x;
    }
   // return NULL;
}

//初始化栈
void initstack(seqstack *s)
{
    s->top=0;
}

//入栈
void push(seqstack *s,datatype x)
{
    if(s->top==stacksize)
        cout<<"stack overflow"<<endl;
    else
    {
        s->data[s->top]=x;
        s->top=s->top+1;
    }

}

//出栈
datatype pop(seqstack *s)
{
    if(s->top==0)
        cout<<"stack underflow"<<endl;
    else
        return s->data[--s->top];
}

//取栈顶元素
datatype gettop(seqstack *s)
{
    if(s->top==0)
         return false;
    else
        return s->data[s->top-1];
}