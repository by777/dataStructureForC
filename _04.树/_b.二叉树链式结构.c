/*
 * @Author: Xu Bai
 * @Date: 2019-07-13 22:24:04
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-07-18 21:31:33
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

/* 用于构造二叉树********************************** */
int index = 1;
/*0号单元存放串的长度 */
typedef char String[24];
String str;

Status StrAssign(String T, char *chars)
{
    int i;
    if (strlen(chars) > MAXSIZE)
    {
        return ERROR;
    }
    else
    {
        T[0] = strlen(chars);
        for (i = 2; i <= T[0]; i++)
        {
            T[i] = *(chars + i - 1);
        }
        return OK;
    }
}
/* ************************************************ */

typedef char ElemType;
/*字符型以空格为空 */
ElemType Nil = ' ';

Status visit(ElemType e)
{
    printf("%c ", e);
    return OK;
}

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;

} BiTNode, *BiTree;

Status InitBiTree(BiTree *T)
{
    *T = NULL;
    return OK;
}

void DestroyTree(BiTree *T)
{
    if (*T)
    {
        if ((*T)->lchild)
        {
            DestroyTree(&(*T)->lchild);
        }
        if ((*T)->rchild)
        {
            DestroyTree(&(*T)->rchild);
        }
        free(*T);
        *T = NULL;
    }
}

void CreateBiTree(BiTree *T)
{
    ElemType ch;
    ch = str[index++];
    if (ch == '#')
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!*T)
        {
            exit(-1);
        }
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

Status BiTreeEmpty(BiTree T)
{
    if (T)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}