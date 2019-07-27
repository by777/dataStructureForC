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
/*Link==0��ʾָ�����Һ���ָ�룬Thread==��ʾ���� */
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
            /* ������ */
            (*T)->LTag = Link;
        }
        if ((*T)->rchild)
        {
            (*T)->RTag = Link;
        }
    }
    return OK;
}

/*ȫ�ֱ�����ʼ��ָ��ոշ��ʵĽ�� */
BiThrTree pre;
/*���������� */
void InThreading(BiThrTree p)
{
    if (p)
    {
        InThreading(p->lchild);
        if (!p->lchild)
        {
            /*ǰ������ */
            p->LTag = Thread;
            /*����ָ��ָ��ǰ�� */
            p->lchild = pre;
        }
        if (!pre->rchild)
        {
            /* ǰ��û���Һ��� */
            /*������� */
            pre->RTag = Thread;
            /*ǰ���Һ���ָ���̣���ǰ���p�� */
            pre->rchild = p;
        }
        /*����preָ��p��ǰ�� */
        pre = p;
        InThreading(p->rchild);
    }
}

/*���������������������������������Thrtָ��ͷ�ڵ� */
Status InOrderThreading(BiThrTree *Thrt, BiThrTree T)
{
    *Thrt = (BiThrTree)malloc(sizeof(BiThrNode));
    if (!*Thrt)
    {
        exit(-1);
    }
    /*��ͷ�ڵ� */
    (*Thrt)->LTag = Link;
    (*Thrt)->RTag = Thread;
    /*��ָ���ָ */
    (*Thrt)->rchild = (*Thrt);
    if (!T)
    {
        /* ���������գ���ָ���ָ */
        (*Thrt)->lchild = *Thrt;
    }
    else
    {
        (*Thrt)->lchild = T;
        pre = (*Thrt);
        InThreading(T);
        pre->rchild = *Thrt;
        /*���һ����������� */
        pre->RTag = Thread;
        (*Thrt)->rchild = pre;
    }
    return OK;
}

/*����ǵݹ�������������� */
Status InOrderTraverse_Thr(BiThrTree T)
{
    BiThrTree p;
    /*pָ����ڵ� */
    p = T->lchild;
    while (p != T)
    {
        /* �������������ʱ��p==T */
        while (p->LTag == Link)
        {
            p = p->lchild;
        }
        if (!visit(p->data))
        {
            /*������������Ϊ�յĽ�� */
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
    CreateBiThrTree(&T);     /* ��ǰ����������� */
    InOrderThreading(&H, T); /* �������,������������������ */
    printf("�������(���)����������:\n");
    InOrderTraverse_Thr(H); /* �������(���)���������� */
    printf("\n");
    getchar();
    return OK;
}