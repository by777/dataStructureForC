/*
 * @Author: Xu Bai
 * @Date: 2019-07-23 22:43:14
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-07-27 23:35:31
 */
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "io.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;
typedef char ElemType;
/*Link==0表示指向左右孩子指针，Thread==表示线索 */
typedef enum
{
    Link,
    Thread
} PointerTag;

typedef struct BiThrNode
{
    ElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag;
    PointerTag RTag;
} BiThrNode, *BiThrTree;

ElemType Nil = '#';

Status visit(ElemType e)
{
    printf("%c ", e);
    return OK;
}

Status CreateBiThrTree(BiThrTree *T)
{
    ElemType h;
    scanf("%c", &h);
    if (h == Nil)
    {
        *T = NULL;
    }
    else
    {
        *T = (BiThrTree)malloc(sizeof(BiThrNode));
        if (!*T)
        {
            exit(-1);
        }
        (*T)->data = h;
        CreateBiThrTree(&(*T)->lchild);
        if ((*T)->lchild)
        {
            /* 有左孩子 */
            (*T)->LTag = Link;
        }
        if ((*T)->rchild)
        {
            (*T)->RTag = Link;
        }
    }
    return OK;
}

/*全局变量，始终指向刚刚访问的结点 */
BiThrTree pre;
/*中序线索化 */
void InThreading(BiThrTree p)
{
    if (p)
    {
        InThreading(p->lchild);
        if (!p->lchild)
        {
            /*前驱线索 */
            p->LTag = Thread;
            /*左孩子指针指向前驱 */
            p->lchild = pre;
        }
        if (!pre->rchild)
        {
            /* 前驱没有右孩子 */
            /*后继线索 */
            pre->RTag = Thread;
            /*前驱右孩子指向后继（当前结点p） */
            pre->rchild = p;
        }
        /*保持pre指向p的前驱 */
        pre = p;
        InThreading(p->rchild);
    }
}

/*中序遍历二叉树，并将其中序线索化，Thrt指向头节点 */
Status InOrderThreading(BiThrTree *Thrt, BiThrTree T)
{
    *Thrt = (BiThrTree)malloc(sizeof(BiThrNode));
    if (!*Thrt)
    {
        exit(-1);
    }
    /*建头节点 */
    (*Thrt)->LTag = Link;
    (*Thrt)->RTag = Thread;
    /*右指针回指 */
    (*Thrt)->rchild = (*Thrt);
    if (!T)
    {
        /* 若二叉树空，左指针回指 */
        (*Thrt)->lchild = *Thrt;
    }
    else
    {
        (*Thrt)->lchild = T;
        pre = (*Thrt);
        InThreading(T);
        pre->rchild = *Thrt;
        /*最后一个结点线索化 */
        pre->RTag = Thread;
        (*Thrt)->rchild = pre;
    }
    return OK;
}

/*中序非递归遍历线索二叉树 */
Status InOrderTraverse_Thr(BiThrTree T)
{
    BiThrTree p;
    /*p指向根节点 */
    p = T->lchild;
    while (p != T)
    {
        /* 空树或遍历结束时，p==T */
        while (p->LTag == Link)
        {
            p = p->lchild;
        }
        if (!visit(p->data))
        {
            /*访问其左子树为空的结点 */
            return ERROR;
        }
        while (p->RTag == Thread && p->rchild != T)
        {
            p = p->rchild;
            visit(p->data);
        }
        p = p->rchild;
    }
    return OK;
}

int main()
{

    BiThrTree H, T;
    printf(":'ABDH##I##EJ###CF##G##')\n");
    CreateBiThrTree(&T);     /* 按前序产生二叉树 */
    InOrderThreading(&H, T); /* 中序遍历,并中序线索化二叉树 */
    printf("中序遍历(输出)二叉线索树:\n");
    InOrderTraverse_Thr(H); /* 中序遍历(输出)二叉线索树 */
    printf("\n");
    getchar();
    return OK;
}