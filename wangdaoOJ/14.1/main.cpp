/*
Description
读取字符串abcdefghij，然后层次建树建立一颗二叉树，然后前序遍历输出abdhiejcfg，注意不要打印前序遍历几个汉字

Input
abcdefghij

Output
abdhiejcfg

*/
#include "cstdlib"
#include "cstdio"
typedef char BiElemType;
//树结点结构体
typedef struct BiTNode
{
    BiElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode,*BiTree;
//链式 辅助 队列结点
typedef struct QNode
{
    BiTree t;
    struct QNode *next;
}QNode,*pQueue;
//前序遍历树
void PreOrder(BiTree T)
{
    if(T)
    {
        putchar(T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
int main() {
    //队列初始化
    pQueue Q;
    Q= (pQueue)calloc(1,sizeof (QNode));
    pQueue qcur=NULL;//队列指针
    pQueue qtail=Q;//队列尾指针
    //树初始化
    BiTree T;
    T=NULL;
    //接收字符的变量
    char c;
    //读取字符直到换行
    while (scanf("%c",&c))
    {
        if(c=='\n')
            break;
        //第一个字符进树
        if(T==NULL)
        {
            //新结点
            BiTree newT=(BiTNode*) calloc(1,sizeof (BiTNode));
            newT->data=c;
            //结点进树
            T=newT;
            //结点进队列
            pQueue newQNode=(QNode*) calloc(1,sizeof (QNode));
            newQNode->t=newT;
            qtail->next=newQNode;
            qtail=qtail->next;
            //队列指针
            qcur=Q->next;
        }
        else//第二个及以后字符进树
        {
            //新结点
            BiTree newT=(BiTNode*) calloc(1,sizeof (BiTNode));
            newT->data=c;
            //结点进队列
            pQueue newQNode=(QNode*) calloc(1,sizeof (QNode));
            newQNode->t=newT;
            qtail->next=newQNode;
            qtail=qtail->next;
            //结点进树
            if(qcur->t->lchild==NULL)//左子树为空
            {
                //结点进树
                qcur->t->lchild=newT;

            }
            else if(qcur->t->rchild==NULL)//右子树为空
            {
                //结点进树
                qcur->t->rchild=newT;
                qcur=qcur->next;//队列指针后移
            }

        }
    }
    //前序遍历树
    PreOrder(T);
    return 0;
}
