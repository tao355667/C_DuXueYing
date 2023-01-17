/*
输入3 4 5 6 7 9999一串整数，9999代表结束，通过头插法新建链表，并输出，通过尾插法新建链表并输出。

注意输出要采用如下代码（因为OJ判题对空格敏感，因此需要用下面的打印代码来做）：

//打印链表中每个结点的值

void PrintList(LinkList L)

{

L=L->next;

while(L!=NULL)

{

printf("%d",L->data);//打印当前结点数据

L=L->next;//指向下一个结点

if(L!=NULL)

{

printf(" ");

}

}

printf("\n");

}


*/
#include <iostream>
#include "cstring"
typedef struct LNode
{
    int data;
    struct LNode* next;
}*LinkList,LNode;
//
void InitList(LinkList &L)
{
    L= (LinkList)malloc(sizeof (LNode));
    L->next=NULL;
}
void ListInsertHead(LinkList L,int e)
{
    LinkList newnode=(LinkList) malloc(sizeof (LNode));
    newnode->data=e;
    //插入-头插
    newnode->next=L->next;
    L->next=newnode;
}
void ListInsertTail(LinkList L,int e)
{
    LinkList newnode=(LinkList) malloc(sizeof (LNode));
    newnode->data =e;
    //尾插
    LinkList p=L;
    while(p->next)
    {
        p=p->next;
    }//出while，p指向尾结点
    p->next=newnode;
    newnode->next=NULL;
}
void PrintList(LinkList L)
{
    if(L->next==NULL)
        return;
    LinkList p=L->next;
    while(p)
    {
        printf("%d",p->data);
        p=p->next;
        if(p)
            printf(" ");
    }
    printf("\n");
}
int main() {
    LinkList L;
    InitList(L);
    int a;
    scanf("%d",&a);
    while(a!=9999)
    {
        ListInsertHead(L,a);
        scanf("%d",&a);
    }

    /////
    LinkList L1;
    InitList(L1);
    scanf("%d",&a);
    while(a!=9999)
    {

        ListInsertTail(L1,a);
        scanf("%d",&a);
    }
    PrintList(L);
    PrintList(L1);
    return 0;
}
