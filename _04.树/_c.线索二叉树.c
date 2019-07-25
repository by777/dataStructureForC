/*
 * @Author: Xu Bai
 * @Date: 2019-07-23 22:43:14
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-07-25 20:55:15
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

Status CreateBiThrTree(BiThrNode *T)
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

