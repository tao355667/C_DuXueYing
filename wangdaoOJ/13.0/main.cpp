/*
Description
新建一个栈，读取标准输入3个整数3 4 5，入栈3 4 5，依次出栈
 ，打印 5 4 3，新建循环队列（Maxsize为5），读取标准输入3 4 5 6 7，入队7时，队满，打印false，
 然后依次出队，输出 3 4 5 6

Input
读取标准输入，内容依次是3 4 5，换行后，接着是3 4 5 6 7
Output
如果输入是3 4 5，换行，接着是3 4 5 6 7，那么输出是
5 4 3
false
3 4 5 6
注意每个数字占用两个字符的位置，5之前是有一个空格的，第三行的3之前也是有一个空格的
 */
#include "stdlib.h"
#include "stdio.h"
#define MAXSIZE 50
#define MAXQSIZE 5
//栈结构体
typedef struct
{
    int data[MAXSIZE];
    int top;
}Stack;
//队列结构体
typedef struct
{
    int data[MAXQSIZE];
    int front,rear;
}SqQueue;
//队列初始化
void InitQueue(SqQueue &Q)
{
    Q.front=Q.rear=0;
}
//队列判空
bool IsEmptyQueue(SqQueue &Q)
{
    if(Q.front==Q.rear)
        return true;
    else
        return false;
}
//入队
void EnQueue(SqQueue &Q,int e)
{
//    printf("Q.front=%d,Q.rear=%d\n",Q.front,Q.rear);
    //判断队是否满了
    if((Q.rear+1)%MAXQSIZE==Q.front)
    {
        printf("false\n");
        return;
    }
    //元素入队
    Q.data[Q.rear]=e;
    Q.rear=(Q.rear+1)%MAXQSIZE;
}
//出队
bool DeQueue(SqQueue &Q,int &e)
{
//    printf("Q.front=%d,Q.rear=%d\n",Q.front,Q.rear);
    //判断队是否为空
    if(Q.front==Q.rear)
    {
        printf("false2\n");
        return false;
    }
    //出队
    e=Q.data[Q.front];
    Q.front=(Q.front+1)%MAXQSIZE;
    return true;
}
//栈初始化
void InitStack(Stack &s)
{
    s.top=-1;
}
//判断栈是否为空
bool IsEmptyStack(Stack s)
{
    if(s.top==-1)
        return true;
    else
        return false;
}
//入栈
void Push(Stack &s,int e)
{
    s.data[++s.top]=e;
}
//出栈
void Pop(Stack &s,int &e)
{
    e=s.data[s.top--];
}
//遍历栈
void PrintStack(Stack s)
{
    int i;
    for(i=0;i<s.top;i++)
        printf("%2d",s.data[i]);
    printf("\n");
}

int main() {
    int i,j;
    int e;
    SqQueue Q;
    Stack S;
    InitQueue(Q);
    InitStack(S);
    for(i=0;i<3;i++)
    {
        scanf("%d",&e);
        Push(S,e);
    }
    for(i=0;i<3;i++)
    {
        Pop(S,e);
        printf("%2d",e);
    }
    printf("\n");
    //队列
    for(i=0;i<5;i++)
    {
        scanf("%d",&e);
        EnQueue(Q,e);
    }
    for(i=0;i<4;i++)
    {
        if(DeQueue(Q,e))
            printf("%2d",e);
    }
    return 0;
}
