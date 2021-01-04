//head.h
#include"stack&queue.h"

//给运算符排序
int priority(datatype op)
{
    switch(op)
    {
        case '(':
        case ')':
        case '#': return 0;
        case '-':
        case '+': return 1;
        case '*':
        case '/': return 2;
    }
    return -1;
}


void printStack(seqstack s){
    cout << "栈内情况为：" ;
    while(s.top){
        cout << pop(&s);
    }
    cout << endl;
}
//中转后
void transfer()
{
    cout<<"中序转后序表达式"<<endl;
    cout<<"输入:"<<endl;
    seqqueue *q;
    seqqueue postq;
    q=&postq;
    initqueue(q);
    seqstack os;
    char c,t;
    seqstack *s;
    s=&os;
    initstack(s);;
    push(s,'#');
    do{
        c=getchar();
        switch(c)
        {
            case '(':
                push(s,c);
                break;
            case')':
            case'#':
                do{
                    t=pop(s);
                    if(t!='('&&t!='#')
                        enqueue(q,t);
                }while(t!='('&&s->top!=0);
                break;
            case '+':
            case '-':
            case '*':
            case '/':
               while(priority(c)<=priority(gettop(s))){
                   t=pop(s);
                   enqueue(q,t);
                }
               push(s,c); 
               break;
            default:enqueue(q,c); break;
        }
        printStack(*s);
    }while(c!='#');
    while(!queueempty(q))
        cout<<dequeue(q)<<" ";
    cout<<endl;
}
