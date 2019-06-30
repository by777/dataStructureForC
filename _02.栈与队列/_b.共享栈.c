/*
 * @Author: Xu Bai
 * @Date: 2019-06-30 20:54:59
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-06-30 21:25:05
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

typedef struct
{
    ElemType data[MAXSIZE];
    int top1;
    int top2;
} SqDoubleStack;

Status visit(ElemType e)
{
    printf("%d ", e);
    return OK;
}

Status InitStack(SqDoubleStack *S)
{
    S->top1 = -1;
    S->top2 = MAXSIZE;
    return OK;
}

Status ClearStack(SqDoubleStack *S)
{
    S->top1 = -1;
    S->top2 = MAXSIZE;
    return OK;
}

Status StackEmpty(SqDoubleStack S)
{
    if (S.top1 == -1 && S.top2 == MAXSIZE)
    {
        return TRUE;
    }
    return FALSE;
}

int StackLength(SqDoubleStack S)
{
    return (S.top1 + 1) + (MAXSIZE - S.top2);
}

Status Push(SqDoubleStack *S, ElemType e, int stackNumber)
{
    if (S->top1 + 1 == S->top2)
    {
        printf("Stack overflow");
        return ERROR;
    }
    if (stackNumber == 1)
    {
        S->data[++S->top1] = e;
    }
    else if (stackNumber == 2)
    {
        S->data[--S->top2] = e;
    }
    else
    {
        printf("stackNumber = 1 or 2");
        return ERROR;
    }
    return OK;
}

Status Pop(SqDoubleStack *S, ElemType *e, int stackNumber)
{
    if (stackNumber == 1)
    {
        if (S->top1 == -1)
        {
            return ERROR;
        }
        *e = S->data[S->top1--];
    }
    else if (stackNumber == 2)
    {
        if (S->top2 == MAXSIZE)
        {
            return ERROR;
        }
        *e = S->data[S->top2++];
    }
    else
    {
        return ERROR;
    }

    return OK;
}

Status StackTraverse(SqDoubleStack S)
{
    int i = 0;
    while (i <= S.top1)
    {
        visit(S.data[i++]);
    }
    i = S.top2;
    while (i < MAXSIZE)
    {
        visit(S.data[i++]);
    }
    printf("\n");
    return OK;
}

int main()
{
    int j;
    ElemType e;
    SqDoubleStack S;
    InitStack(&S);
    for (j = 0; j <= 5; j++)
    {
        Push(&S, j, 1);
    }
    for (j = MAXSIZE; j >= MAXSIZE - 2; j--)
    {
        Push(&S, j, 2);
    }
    printf("Traverse: \n");
    StackTraverse(S);
    printf("pop 1 &2 \n");
    Pop(&S, &e, 1);
    Pop(&S, &e, 2);
    StackTraverse(S);
    ClearStack(&S);
    printf("Clear!\n");
    StackTraverse(S);
    getchar();
    return OK;
}