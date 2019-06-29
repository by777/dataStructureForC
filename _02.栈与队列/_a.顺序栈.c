/*
 * @Author: Xu Bai
 * @Date: 2019-06-29 22:05:11
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-06-29 22:46:28
 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "ctype.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

Status visit(ElemType e)
{
    printf("%d ", e);
    return 0;
}

typedef struct
{
    ElemType data[MAXSIZE];
    int top;
} SqStack;

Status InitStack(SqStack *S)
{
    S->top = -1;
    return OK;
}

Status ClearStack(SqStack *S)
{
    S->top = -1;
    return OK;
}

Status StackEmpty(SqStack S)
{
    if (S.top == -1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int StackLength(SqStack S)
{
    return S.top + 1;
}

Status GetTop(SqStack S, ElemType *e)
{
    if (S.top == -1)
    {
        return ERROR;
    }
    else
    {
        *e = S.data[S.top];
    }
    return OK;
}

Status Push(SqStack *S, ElemType e)
{
    //入栈
    if (S->top == MAXSIZE - 1)
    {
        return ERROR;
    }
    S->data[++(S->top)] = e;
    return OK;
}

Status Pop(SqStack *S, ElemType *e)
{
    if (S->top == -1)
    {
        return ERROR;
    }
    *e = S->data[(S->top)--];
    return OK;
}

Status SqStackTraverse(SqStack S)
{
    int i = 0;
    while (i <= S.top)
    {
        visit(S.data[i++]);
    }
    printf("\n");
    return OK;
}

int main()
{
    SqStack S;
    InitStack(&S);
    int j;
    ElemType e;
    printf("Push 0~10! \n");
    for (j = 0; j < 11; j++)
    {
        Push(&S, j);
    }
    SqStackTraverse(S);
    printf("Pop! \n");
    Pop(&S, &e);
    SqStackTraverse(S);
    GetTop(S, &e);
    printf("GetTop: %d \n", e);
    ClearStack(&S);
    printf("clear!");
    SqStackTraverse(S);
    getchar();
    return OK;
}