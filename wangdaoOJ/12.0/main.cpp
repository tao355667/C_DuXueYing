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
//在第i个位置插入元素e
void ListInsertNode(LinkList L,int i,int e)
{
    if(L->next==NULL)
        return;
    int j=1;
    LinkList p=L->next;
    LinkList q=L;
    while(p&&j<i)
    {
        p=p->next;
        q=q->next;
        j++;
    }
    //插入新元素
    LinkList newnode=(LinkList) malloc(sizeof (LNode));
    newnode->data=e;
    //
    newnode->next=p;
    q->next=newnode;

}
//用e返回链表中第i个元素
void GetListNode(LinkList L,int i,int &e)
{
    int j=1;
    LinkList p=L->next;
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    if(j<i)//表不空且没有第i个元素
        return;
    e=p->data;
}
//删除链表中第i个元素
void DeleteListNode(LinkList L,int i)
{
    LinkList p=L->next;
    LinkList q=L;
    int j=1;
    while(p&&j<i)
    {
        p=p->next;
        q=q->next;
        j++;
    }
    //删除结点
    LinkList del=p;
    q->next=p->next;
    free(del);
}
//打印链表L
void PrintList(LinkList L)
{
    if(L->next==NULL)
        return;
    LinkList p=L->next;
    while(p)
    {
        printf("%3d",p->data);
        p=p->next;

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
        ListInsertTail(L,a);
        scanf("%d",&a);
    }
    //输出第二个位置的元素
    LinkList p=L->next->next;
    printf("%d\n",p->data);
    //在第二个位置插入99
    ListInsertNode(L,2,99);
    PrintList(L);
    //删除第四个位置的值
    DeleteListNode(L,4);
    PrintList(L);
    return 0;
}
