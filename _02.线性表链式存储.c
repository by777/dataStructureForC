/*
 * @Author: Xu Bai
 * @Date: 2019-06-26 22:48:42
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-06-27 22:23:47
 */
#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"
#include "io.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

Status visit(ElemType c)
{
    printf("%d ", c);
    return OK;
}

typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;

typedef struct Node *LinkList;
// 把 struct Node * 定义成了新类型 LinkList。这个类型是一个结构体的指针

Status InitList(LinkList *L)
{
    // 插入和删除用到的是实参，所以就需要用指向指针的指针。
    *L = (LinkList)malloc(sizeof(Node));
    if (!(*L))
    {
        return ERROR;
    }
    (*L)->next = NULL;
    return OK;
}

Status ListEmpty(LinkList L)
{
    if (L->next)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

Status ClearList(LinkList *L)
{
    LinkList p, q;
    p = (*L)->next;
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}

int ListLength(LinkList L)
{
    int p = 0;
    while (L->next)
    {
        p++;
        L = L->next;
    }
    return p;
}

Status GetElem(LinkList L, int i, ElemType *e)
{
    LinkList p = L->next;
    LinkList q;
    int k = 0;
    while (p && k < i)
    {
        k++;
        p = p->next;
    }
    if (k > i || !p)
    {
        printf("not found!");
        return ERROR;
    }
    else
    {
        *e = p->data;
        return OK;
    }
}

int locateElem(LinkList L, ElemType e)
{
    LinkList p = L->next;
    int i = 0;
    while (p)
    {
        i++;
        if (p->data == e)
        {
            return i;
        }
        else
        {
            p = p->next;
        }
    }
    return ERROR;
}

Status ListInsert(LinkList *L, int i, ElemType e)
{
    // 在L中第i个位置之前插入新的数据元素e
    LinkList p, q;
    int j = 1;
    p = *L;
    // 寻找第i个结点
    while (p && j < i)
    {
        p = p->next;
        j++;
    }

    if (j > i || !p)
    {
        // 如果遍历到结束也没找到i结点
        return ERROR;
    }
    q = (LinkList)malloc(sizeof(Node));
    q->data = e;
    q->next = p->next;
    p->next = q;
    return OK;
}

Status ListTraverse(LinkList L){
    LinkList p = L->next;
    while (p)
    {
        visit(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
    
}

int main()
{
    LinkList L;
    ElemType e;
    InitList(&L);
    ListInsert(&L, 1, 3);
    ListInsert(&L, 1, 2);
    ListInsert(&L, 1, 1);
    ListTraverse(L);
    int i = locateElem(L, 3);
    int j = GetElem(L,2,&e);
    printf("i= %d , e= %d", i,e);
    getchar();
    return OK;
}