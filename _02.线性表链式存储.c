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
// �� struct Node * ������������� LinkList�����������һ���ṹ���ָ��

Status InitList(LinkList *L)
{
    // �����ɾ���õ�����ʵ�Σ����Ծ���Ҫ��ָ��ָ���ָ�롣
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
    // ��L�е�i��λ��֮ǰ�����µ�����Ԫ��e
    LinkList p, q;
    int j = 1;
    p = *L;
    // Ѱ�ҵ�i�����
    while (p && j < i)
    {
        p = p->next;
        j++;
    }

    if (j > i || !p)
    {
        // �������������Ҳû�ҵ�i���
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
        // Ѱ�ҽ��
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
    // ������ͷ���ĵ�����ͷ�巨��
    LinkList p;
    int i;
    srand(time(0)); // ��ʼ���������
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    for (i = 0; i < n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1; //�������100���ڵ�����
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void CreateListTail(LinkList *L, int n)
{
    // β�巨
    LinkList p, r;
    int i;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));
    r = *L; //rָ��β���
    for (i = 0; i < n; i++)
    {
        p = (Node *)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        // �½���㲢���뵽β���
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
    printf("��L�ı�ͷ���β���1��5��L.data=");
    ListTraverse(L);
    ListInsert(&L, 1, 0);
    printf("��L�ı�ͷ����0��L.data=");
    ListTraverse(L);
    GetElem(L, 5, &e);
    printf("��5��Ԫ�ص�ֵΪ��%d\n", e);
    k = ListLength(L); /* kΪ�� */
    for (j = k + 1; j >= k; j--)
    {
        i = ListDelete(&L, j, &e); /* ɾ����j������ */
        if (i == ERROR)
            printf("ɾ����%d������ʧ��\n", j);
        else
            printf("ɾ����%d����Ԫ��ֵΪ��%d\n", j, e);
    }
    printf("�������L��Ԫ�أ�");
    ListTraverse(L);
    ClearList(&L);
    CreateListHead(&L, 20);
    printf("���崴��L��Ԫ��(ͷ�巨)��");
    ListTraverse(L);
    ClearList(&L);
        CreateListTail(&L,20);
    printf("���崴��L��Ԫ��(β�巨)��");
    ListTraverse(L); 
    getchar();
    return OK;
}