/*
Description
读取10个整型数据12 63 58 95 41 35 65  0 38 44，然后通过冒泡排序，快速排序，插入排序，分别对该组数据进行排序，输出3次有序结果，每个数的输出占3个空格

Input
12 63 58 95 41 35 65  0 38 44

Output
输出3次有序结果

0 12 35 38 41 44 58 63 65 95
0 12 35 38 41 44 58 63 65 95
0 12 35 38 41 44 58 63 65 95

Sample Input 1

12 63 58 95 41 35 65  0 38 44
Sample Output 1
  0 12 35 38 41 44 58 63 65 95
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
//冒泡排序,len为表长
void BubbleSort(ElemType A[],int len)
{
    for(int i=0;i<len-1;i++)
    {//每趟的左端点逐渐变小
        bool flag= true;//指示是否有序
        for(int j=len-1;j>i;j--)
        {//从后向前
            if(A[j-1]>A[j])
            {
                swap(A[j],A[j-1]);
                flag= false;//有交换，表示无序
            }
        }
        if(flag)//没有交换，说明有序，直接结束
        {
            return;
        }
    }
}
//快速排序,依赖函数，分割函数,以第一个元素为基准，将表分为两部分，返回中间下标
int Partition(ElemType A[],int low,int high)
{
    ElemType mid=A[low];//分割基准
    int i=low,j=high;//两端指针
    while (i<j)
    {
        //从后向前，找小的
        while(A[j]>=mid&&i<j)
            j--;
        A[i]=A[j];
        //从前向后，找大的
        while(A[i]<=mid&&i<j)
            i++;
        A[j]=A[i];
    }//此时i==j
    //printf("i=%d,j=%d\n",i,j);
    A[i]=mid;
    return i;
}
//快速排序,low为起点下标，high为终点下标
void QuickSort(ElemType A[],int low,int high)
{
    if(low<high)
    {
        int pivot=Partition(A,low,high);
        QuickSort(A,low,pivot-1);
        QuickSort(A,pivot+1,high);
    }
}
//插入排序,len为表长
void InsertSort(ElemType A[],int len)
{//插入排序
    for(int i=1;i<len;i++)//要插入的元素的下标
    {
        int val=A[i];
        int j;
        for(j=i-1;j>=0;j--)//将val与前面的元素值比较
        {
            if(val<A[j])//不符合条件，则后移
                A[j+1]=A[j];
            else
                break;
        }
        A[j+1]=val;//要插入的位置在j后面一格
    }
}
void Sort1()
{//冒泡排序
    SSTable T;
    ST_Init(T,10);
    ST_Scanf(T,T.len);
    BubbleSort(T.elem,10);
    ST_Print(T);
}
void Sort2()
{//快速排序
    SSTable T;
    ST_Init(T,10);
    ST_Scanf(T,T.len);
    QuickSort(T.elem,0,9);
    ST_Print(T);
}
void Sort3()
{//插入排序
    SSTable T;
    ST_Init(T,10);
    ST_Scanf(T,T.len);
    InsertSort(T.elem,10);
    ST_Print(T);
}
int main() {
    SSTable T1,T2,T3;
    ST_Init(T1,10);
    ST_Init(T2,10);
    ST_Init(T3,10);
    for(int i=0;i<10;i++)
    {
        ElemType temp;
        scanf("%d",&temp);
        T1.elem[i]=temp;
        T2.elem[i]=temp;
        T3.elem[i]=temp;
    }
    BubbleSort(T1.elem,T1.len);
    ST_Print(T1);
    QuickSort(T2.elem,0,9);
    ST_Print(T2);
    InsertSort(T3.elem,T3.len);
    ST_Print(T3);

    return 0;
}
