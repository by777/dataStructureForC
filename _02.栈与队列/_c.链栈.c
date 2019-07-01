/*
 * @Author: Xu Bai
 * @Date: 2019-07-01 21:32:41
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-07-01 21:39:07
 */
#include "stdio.h"
#include "stdlib.h"
#include "io.h"

#define MAXSIZE 20
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0

typedef int Status;
typedef int ElemType;

typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;

typedef struct
{
    LinkStackPtr top;
    int count;
} LinkStack;

Status visit(ElemType e)
{
    printf("%d ", e);
    return OK;
}

Status InitStack(LinkStack *S)
{
    S->top = (LinkStackPtr)malloc(sizeof(StackNode));
    if (!S->top)
    {
        return ERROR;
    }
    S->top = NULL;
    S->count = 0;
    return OK;
}
