#include <iostream>
#define MAX_LIST_SIZE 100
//顺序表结构体
typedef struct
{
   int *data;
   int length,listsize;
}SqList;
//初始化
void InitList(SqList &L)
{
    L.data=new int[MAX_LIST_SIZE];
    L.length=0;
    L.listsize=MAX_LIST_SIZE;
}
//输出顺序表
void ListPrint(SqList L)
{
    int i;
    for(i=0;i<L.length;i++)
    {
        std::cout<<"  "<<L.data[i];

    }
    std::cout<<"\n";
}
//在表中第i个位置插入元素e
void ListInsert(SqList &L,int i,int e)
{
    //输入位置不合法
    if(i>L.length+1||i<1)
    {
        std::cout<<"false\n";
        return;
    }
    //输入位置合法
    int j;
    for(j=L.length;j>=i;j--)
    {
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    ListPrint(L);
}
//删除线性表第i个元素
void ListDelete(SqList &L,int i)
{
    //输入位置不合法，顺序表为空
    if(i<1||i>L.length||L.length==0)
    {
        std::cout<<"false\n";
        return;
    }
    //输入位置合法
    int j;
    for(j=i;j<L.length;j++)//j开始指向下标为i+1的元素
    {
        L.data[j-1]=L.data[j];
    }
    L.length--;
    ListPrint(L);
}

int main() {
    SqList L;
    InitList(L);
    L.data[0]=1;L.length++;
    L.data[1]=2;L.length++;
    L.data[2]=3;L.length++;
//    ListPrint(L);
//    printf("L.length=%d",L.length);
    //在第二个位置插入元素e
    int e;
    scanf("%d",&e);
    ListInsert(L,2,e);
    //删除第j个位置的元素
    int j;
    scanf("%d",&j);
    ListDelete(L,j);

    return 0;
}
