/*
 * @Author: Xu Bai
 * @Date: 2019-07-01 21:32:41
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-07-01 22:12:36
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

Status ClearStack(LinkStack *S)
{
    LinkStackPtr p, q;
    p = S->top;
    while (p)
    {
        q = p;
        p = p->next;
        free(q);
    }
    S->count = 0;
    return OK;
}

Status StackEmpty(LinkStack S)
{
    if (S.count == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int StackLength(LinkStack S)
{
    return S.count;
}

Status GetTop(LinkStack S, ElemType *e)
{
    LinkStackPtr p;
    if (S.top == NULL)
    {
        return ERROR;
    }
    else
    {
        *e = S.top->data;
    }
    return OK;
}

Status Push(LinkStack *S, ElemType e)
{
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top;
    S->top = s;
    S->count++;
    return OK;
}

Status Pop(LinkStack *S, ElemType *e)
{
    if (StackEmpty(*S))
    {
        return ERROR;
    }
    LinkStackPtr p;
    *e = S->top->data;
    p = S->top->next;
    S->top->next = p->next;
    free(p);
    S->count--;
    return OK;
}

Status StackTraverse(LinkStack S)
{
    LinkStackPtr p;
    p = S.top;
    while (p)
    {
        visit(p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

int main()
{
    LinkStack s;
    ElemType e;
    InitStack(&s);
    int i;
    for (i = 1; i <= 10; i++)
    {
        Push(&s, i);
    }
    printf("Traverse:\n");
    StackTraverse(s);
    Pop(&s, &e);
    printf("pop:\n");
    StackTraverse(s);
    printf("the elem:%d\n", e);
    ClearStack(&s);
    printf("clear!");
    StackTraverse(s);

    getchar();
    return OK;
}