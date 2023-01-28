/*
Description
读取10个整型数据12 63 58 95 41 35 65  0 38 44，然后通过归并排序，对该组数据进行排序，输出有序结果，每个数的输出占3个空格
Input
12 63 58 95 41 35 65  0 38 44
Output
0 12 35 38 41 44 58 63 65 95
Sample Input 1
12 63 58 95 41 35 65  0 38 44
Sample Output 1
  0 12 35 38 41 44 58 63 65 95
 */
#include "stdlib.h"
#include "stdio.h"
#include "time.h"

#define N 10
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
    for(int i=0;i<len;i++)
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
//将两连续的“有序数组片段”有序合并
//low~mid与mid+1~high有序合并
void Merge(ElemType *A,int low,int mid,int high)
{
    static ElemType B[N]={};
    for(int i=0;i<N;i++)
    {//把A中元素复制到B中
        B[i]=A[i];
    }
    int i=low,j=mid+1;
    int k=low;
    while (i<=mid&&j<=high)
    {
        if(B[i]<B[j])
            A[k++]=B[i++];
        else
            A[k++]=B[j++];
    }
    //插入剩下元素
    while(i>mid&&j<=high)
    {
        A[k++]=B[j++];
    }
    while(i<=mid&&j>high)
    {
        A[k++]=B[i++];
    }
}
//归并排序，两两归并
void MergeSort(ElemType *A,int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merge(A,low,mid,high);
    }
}
void test()
{
    SSTable T;
    ST_Init(T,10);
    ST_Scanf(T,10);
    MergeSort(T.elem,0,9);
    ST_Print(T);
}
int main()
{
    test();
    return 0;
}
