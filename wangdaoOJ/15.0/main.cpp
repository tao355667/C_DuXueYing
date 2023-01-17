/*
Description
读取10个元素 87  7 60 80 59 34 86 99 21  3，然后建立二叉查找树，中序遍历输出3  7 21 34 59 60 80 86 87 99，针对有序后的元素，存入一个长度为10的数组中，通过折半查找找到21的下标（下标为2），然后输出2
Input
标准输入读取10个元素 87  7 60 80 59 34 86 99 21  3
Output
中序遍历输出有序，每个元素占3个字母位置
3  7 21 34 59 60 80 86 87 99

接着输出2即可（就是元素21的下标），注意2直接在行首输出即可
Sample Input 1

87  7 60 80 59 34 86 99 21  3
Sample Output 1

  3  7 21 34 59 60 80 86 87 99
2
 */
#include <iostream>
//类型定义
typedef int TElemType;
typedef struct BSNode
{
    TElemType data;//数据
    struct BSNode* lchild,*rchild;//左右孩子
}BSNode,*BSTree;
//将一个元素插入二叉排序树
int BST_Insert(BSTree &T,TElemType e)
{
    if(T==NULL)
    {
        BSTree newNode=(BSTree) malloc(sizeof (BSNode));
        newNode->data=e;
        newNode->lchild=NULL;
        newNode->rchild=NULL;
        //
        T=newNode;
    }
    else
    {
        BSTree p=T;
        BSTree parent;
        while(p)
        {
            parent=p;
            if(e>p->data)
            {
                p=p->rchild;
            }
            else if(e<p->data)
            {
                p=p->lchild;
            }
            else
            {
                return 0;//输入值已经存在
            }
        }
        //新结点
        BSTree newNode=(BSTree) malloc(sizeof (BSNode));
        newNode->data=e;
        newNode->lchild=NULL;
        newNode->rchild=NULL;
        //插入
        if(e>parent->data)
        {
            parent->rchild=newNode;
        }
        else if(e<parent->data)
        {
            parent->lchild=newNode;
        }
    }
//    printf("%d insert success!\n",e);
    return 1;
}
//通过一个数组建立二叉排序树
int BST_Create(BSTree &T,TElemType *arr,int len)
{
    for(int i=0;i<len;i++)
    {
        BST_Insert(T,arr[i]);
    }
    return 1;
}
//在二叉排序树中查找值为e的元素
BSTree BST_Search(BSTree T,TElemType e)
{
    while(T)
    {
        if(e==T->data)
        {
            return T;
        }
        else if(e>T->data)
        {
            T=T->rchild;
        }
        else
        {
            T=T->lchild;
        }
    }
    return nullptr;
}
//中序遍历二叉排序树
void BST_InOrder(BSTree T,int *arr,int &i)
{
    if(T)
    {
        BST_InOrder(T->lchild,arr,i);
        printf("%3d",T->data);
        arr[i++]=T->data;
        BST_InOrder(T->rchild,arr,i);
    }
}
void InOrder(BSTree T,int *arr)
{
    int i=0;
    BST_InOrder(T,arr,i);//中序遍历二叉排序树，并按顺序存入数组arr
    printf("\n");
}
int BinarySearch(int e,int *arr,int len)
{//二分查找
    int low=0;
    int heigh=len-1;
    int mid;
    while(low<=heigh)
    {
        mid=(low+heigh)/2;
        if(arr[mid]==e)
        {
            return mid;
        }
        else if(arr[mid]<e)
        {
            low=mid+1;
        }
        else
        {
            heigh=mid-1;
        }
    }
    return -1;//没找到
}
//删除二叉排序树中值为e的元素,递归
void BST_DeleteNode(BSTree &T,TElemType e)
{
    //找到要删除的结点
    if(T==NULL)
    {
        return;
    }
    else if(T->data>e)
    {
        BST_DeleteNode(T->lchild,e);
    }
    else if(T->data<e)
    {
        BST_DeleteNode(T->rchild, e);
    }
    else//删除结点
    {
        if(T->lchild==NULL)
        {//左子树为空
            BSTree tempNode=T;
            T=T->rchild;
            free(tempNode);
        }
        else if(T->rchild==NULL)
        {//右子树为空
            BSTree tempNode=T;
            T=T->lchild;
            free(tempNode);
        }
        else//左右子树都不为空
        {
            //把左子树的最大值（右子树的最小值）放到T->data
            //再删除左子树根节点（右子树根节点）
            BSTree  p=T->lchild;
            while(p->rchild)
            {//找左子树的最大值对应的结点
                p=p->rchild;
            }
            T->data=p->data;
            BST_DeleteNode(T->lchild,p->data);

        }
    }
}
int main() {
    BSTree T=NULL;//空树，树根
    //接收10个元素，存入数组
    int arr[10]={};
    for(int i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
    }
    BST_Create(T,arr,10);//将数组元素插入二叉排序树
    //排序，查找
    int arrSorted[10]={};
    InOrder(T,arr);
    //二分查找,21
    int a=BinarySearch(21,arr,sizeof (arr)/sizeof (arr[0]));
    if(a==-1)
    {
        printf("%d not found!\n",21);
    }
    else
    {
        printf("%d\n",a);
    }
    //删除元素21，再次遍历
    BST_DeleteNode(T,80);
    InOrder(T,arr);
    return 0;
}
