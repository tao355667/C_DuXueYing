/*
Description
读取10个整型数据12 63 58 95 41 35 65  0 38 44，然后通过选择排序，堆排序，分别对该组数据进行排序，输出2次有序结果，每个数的输出占3个空格
完成OJ作业的同学，可以购买《跟龙哥学C语言编程》，有很多课后习题可以练习，附带答案，或者直接B站搜王道论坛，看王道的数据结构，组成原理。
Input
12 63 58 95 41 35 65  0 38 44
Output
输出2次有序结果
0 12 35 38 41 44 58 63 65 95
0 12 35 38 41 44 58 63 65 95
Sample Input 1
12 63 58 95 41 35 65  0 38 44
Sample Output 1
  0 12 35 38 41 44 58 63 65 95
  0 12 35 38 41 44 58 63 65 95
 */
#include "stdlib.h"
#include "stdio.h"
#include "time.h"
typedef int ElemType;
typedef struct{
    ElemType *elem;
    int len;
}SSTable;
//交换两数据的值
void swap(ElemType &a,ElemType &b)
{
    ElemType temp=a;
    a=b;
    b=temp;
}
//表初始化,随机元素
void ST_Init(SSTable &T,int len)
{
    srand(time(NULL));
    T.elem=(ElemType*) malloc(len*sizeof (ElemType));
    T.len=len;
    for(int i=0;i<T.len;i++)
    {
        T.elem[i]=rand()%100;
    }
}
//表初始化,读取元素
void ST_Scanf(SSTable T,int len)
{
    for(int i=0;i<T.len;i++)
    {//读取10个值
        scanf("%d",&T.elem[i]);
    }
}
//输出表元素
void ST_Print(SSTable T)
{
    for(int i=0;i<T.len;i++)
    {
        printf("%3d",T.elem[i]);
    }
    printf("\n");
}
//选择排序,len为表长
void SelectSort(ElemType *A,int len)
{
    for(int i=0;i<len;i++)//i为左端
    {
        int min=i;//假设第一个(下标)为最小值
        for(int j=len-1;j>i;j--)//j从右到左
        {
            if(A[j]<A[min])
                min=j;
        }
        swap(A[i],A[min]);
    }
}
//从小到大排序：大根堆。从大到小排序：小根堆
//要求两个子树均为大根堆（空结点/叶子结点，也行），考虑根结点的插入，将根结点对应的树调整为大根堆
//下标从0开始,k为要调整的结点下标，ne为最后一个元素的下标
void AdjustDown1(ElemType *A,int k,int ne)
{
    int dad=k;
    int son=dad*2+1;//左孩子
    while(son<=ne)//左孩子和父亲都要存在
    {
        if(son+1<=ne&&A[son]<A[son+1])//右孩子存在&&右孩子大于左孩子
        {
            son++;
        }
        if(A[son]>A[dad])//孩子比爸爸大
        {//发生交换，影响下面的子树，故将孩子作为根节点继续调整。
            swap(A[son],A[dad]);
            dad=son;
            son=dad*2+1;
        }
        else//孩子比爸爸小，不交换，所以也不影响下面的子树
            break;
    }

}
//堆排序，ne为最后一个元素的下标
void HeapSort(ElemType* A,int ne)
{//堆在我心中，层次
    //1 将整个树变为大根堆
    for(int i=ne/2;i>=0;i--)
    {
        AdjustDown1(A,i,ne);
    }
    //2 将根结点与最后一个结点交换
    swap(A[0],A[ne]);
    //3 将最后一个元素排除，对缩小后的堆执行相同操作
    for(int i=ne-1;i>0;i--)
    {
        AdjustDown1(A,0,i);
        swap(A[0],A[i]);
    }
}
void Sort4()
{//选择排序
    SSTable T;
    ST_Init(T,10);
//    ST_Scanf(T,T.len);
    SelectSort(T.elem,T.len);
    ST_Print(T);
}
void Sort5()
{//堆排序
    SSTable T;
    ST_Init(T,10);
//    ST_Scanf(T,T.len);
    HeapSort(T.elem,T.len-1);
    ST_Print(T);
}
void test()
{
    SSTable T1,T2;
    ST_Init(T1,10);
    ST_Init(T2,10);
    for(int i=0;i<T1.len;i++)
    {//读取10个值
        ElemType temp;
        scanf("%d",&temp);
        T1.elem[i]=temp;
        T2.elem[i]=temp;
    }
    SelectSort(T1.elem,T1.len);
    ST_Print(T1);
    HeapSort(T2.elem,T2.len-1);
    ST_Print(T2);
}
int main() {
//    Sort4();
//    Sort5();
    test();
    return 0;
}
