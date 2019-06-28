/*
 * @Author: Xu Bai
 * @Date: 2019-06-26 22:48:42
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-06-28 21:13:10
 */
#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"
#include "io.h"
#include "math.h"
#include "time.h"

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
    int k = 1;
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

Status ListDelete(LinkList *L, int i, ElemType *e)
{
    LinkList p, q;
    p = *L;
    int j = 1;
    while (p && j < i)
    {
        // 寻找结点
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i)
    {
        return ERROR;
    }
    q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return OK;
}

void CreateListHead(LinkList *L, int n)
{
    // 建立到头结点的单链表（头插法）
    LinkList p;
    int i;
    srand(time(0)); // 初始化随机种子
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    for (i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1; //随机生成100以内的数字
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void CreateListTail(LinkList *L, int n)
{
    // 尾插法
    LinkList p, r;
    int i;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    r = *L; //r指向尾结点
    for (i = 0; i < n; i++)
    {
        p = (Node *)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        // 新建结点并插入到尾结点
        r->next = p;
        r = p;
    }
    r->next = NULL;
}

Status ListTraverse(LinkList L)
{
    LinkList p = L->next;
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
    LinkList L;
    ElemType e;
    int i, j, k;
    InitList(&L);
    for (j = 1; j <= 5; j++)
        i = ListInsert(&L, 1, j);
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L);
    ListInsert(&L, 1, 0);
    printf("在L的表头插入0后：L.data=");
    ListTraverse(L);
    GetElem(L, 5, &e);
    printf("第5个元素的值为：%d\n", e);
    k = ListLength(L); /* k为表长 */
    for (j = k + 1; j >= k; j--)
    {
        i = ListDelete(&L, j, &e); /* 删除第j个数据 */
        if (i == ERROR)
            printf("删除第%d个数据失败\n", j);
        else
            printf("删除第%d个的元素值为：%d\n", j, e);
    }
    printf("依次输出L的元素：");
    ListTraverse(L);
    ClearList(&L);
    CreateListHead(&L, 20);
    printf("整体创建L的元素(头插法)：");
    ListTraverse(L);
    ClearList(&L);
        CreateListTail(&L,20);
    printf("整体创建L的元素(尾插法)：");
    ListTraverse(L); 
    getchar();
    return OK;
}