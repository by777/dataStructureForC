/*
 * @Author: Xu Bai
 * @Date: 2019-06-25 23:10:17
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-06-26 22:06:39
 */

#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"
#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

Status visit(ElemType c)
{
    printf("%d ", c);
    return OK;
}

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} SqList;

Status ListTraverse(SqList L)
{
    int i = 0;
    for (i = 0; i <= L.length - 1; i++)
    {
        visit(L.data[i]);
    }
    printf("\n");
    return OK;
}

Status InitList(SqList *L)
{
    L->length = 0;
    return OK;
}

Status ListEmpty(SqList L)
{
    if (L.length == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

Status ClearList(SqList *L)
{
    L->length = 0;
    return OK;
}

int ListLength(SqList L)
{
    return L.length;
}

Status GetElem(SqList L, ElemType *e, int i)
{
    if (L.length == 0 || i < 1 || i > L.length)
    {
        return ERROR;
    }
    *e = L.data[i - 1]; // 返回第i个元素，下标为i -1
    return OK;
}

int LocateElem(SqList L, ElemType e)
{
    if (L.length == 0)
    {
        return ERROR;
    }
    int i;
    for (i = 0; i < L.length; i++) // 长度为5，下标为0~4
    {
        if (L.data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}

Status ListInert(SqList *L, ElemType e, int i)
{
    // 在第i个位置之前插入新元素e
    // 初始条件：L存在且不满,且i<=length
    if (L->length == MAXSIZE || i < 1 || i > L->length + 1)
    {

        return ERROR;
    }
    int k;
    // 插入新元素
    for (k = L->length - 1; k >= i - 1; k--)
    {
        L->data[k + 1] = L->data[k];
        // 从最后一个位置(length下标)开始移动
    }
    L->data[i - 1] = e;
    L->length++;
    return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e)
{
    if (L->length == 0)
    {
        return ERROR;
    }
    int k;
    *e = L->data[i - 1];
    for (k = i; k < L->length; k++)
    {
        L->data[k - 1] = L->data[k];
    }
    L->length--;
    return OK;
}

Status unionL(SqList *La, SqList Lb)
{
    int La_length = La->length;
    int Lb_length = Lb.length;
    int flag = 0;
    ElemType e;
    int i;
    for (i = 1; i < Lb.length; i++)
    {
        GetElem(Lb, &e, i);
        if (!LocateElem(*La, e))
        {
            flag = ListInert(La, e, ++La_length);
        }
        if (!flag)
        {
            return ERROR;
        }
    }
    return OK;
}

int main()
{
    SqList L;
    SqList R;
    InitList(&L);
    InitList(&R);

    int n;
    int elem;
    printf("insert \n ");
    for (int k = 1; k < 6; k++)
    {
        ListInert(&L, k, 1);
        ListInert(&R, k + 2, 1);
    }

    ListTraverse(L);
    printf("delete \n");
    ListDelete(&L, 1, &elem);
    ListTraverse(L);
    printf("union \n");
    unionL(&L, R);
    ListTraverse(L);
    ClearList(&R);
    if (ListEmpty(R))
    {
        printf("Empty! \n");
    }

    ListTraverse(R);

    getchar();
}

// EOF为ctrl + z