#include "string.h"

#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "ctype.h"

#define MAXSIZE 1000
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef char ElemType;

Status visit(ElemType c)
{
    printf("%c ", c);
    return OK;
}

typedef struct
{
    ElemType data;
    int cur; // �α꣬Ϊ0ʱ��ָ��
} Component, StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList space)
{
    // ��һά����space�и���������һ����������
    // space[0].curΪͷָ�룬��ָ���־λ0
    int i;
    for (i = 0; i < MAXSIZE - 1; i++)
    {
        space[i].cur = i + 1;
    }
    space[MAXSIZE - 1].cur = 0;
    // ������̬��������β��0
    return OK;
}

int Malloc_SSL(StaticLinkList space)
{
    // ����������ǿգ��򷵻ط���Ľ���±꣬���򷵻�0
    //
    int i = space[0].cur;
    // ��ǰ�����һ��Ԫ�ص�cur���ֵ
    // ��һ�����ÿ��е��±�
    if (space[0].cur)
    {
        // ����Ҫ�ó�һ��������ʹ���ˣ��������ǰ�����
        // ��һ����������������
        space[0].cur = space[i].cur;
    }
    return i;
}

void Free_SSL(StaticLinkList space, int k)
{ // ���±�Ϊk�Ŀ���������յ���������
    // �ѵ�һ��Ԫ�ص�curֵ����Ҫɾ���ķ���cur
    space[k].cur = space[0].cur;
    // ����Ҫɾ�����ĺ�̽ڵ���Ϣ
    // ��Ҫɾ���ķ����±긳ֵ����һ��Ԫ�ص�cur
    space[0].cur = k;
}

int ListLength(StaticLinkList L)
{
    int i, j;
    j = 0;
    i = L[MAXSIZE - 1].cur;
    while (i)
    {
        i = L[i].cur;
        j++;
    }
    return j;
}

Status ListInsert(StaticLinkList L, int i, ElemType e)
{
    if (i < 1 || i > ListLength(L) + 1)
    {
        return ERROR;
    }
    int j = Malloc_SSL(L);
    // ��ÿ��з������±�
    int k = MAXSIZE - 1;
    int l;
    if (j)
    {
        L[j].data = e;
        for (l = 1; l <= i - 1; l++)
        {
            // �ҵ���i��Ԫ��֮ǰ��λ�ø�ֵ��k
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;
        //����i��Ԫ��֮ǰ��cur��ֵ����Ԫ�ص�cur
        L[k].cur = j;
        // ��j����
        return OK;
    }
    return ERROR;
}

Status ListDelete(StaticLinkList L, int i)
{
    if (i < 1 || i > ListLength(L))
    {
        return ERROR;
    }
    int k = MAXSIZE - 1;
    int j;
    for (j = 0; j < i - 1; j++)
    {
        k = L[k].cur;
    }
    j = L[k].cur;
    L[k].cur = L[j].cur;
    Free_SSL(L, j);
    return OK;
}

Status ListTraverse(StaticLinkList L)
{
    int i, j;
    i = L[MAXSIZE - 1].cur;
    //j = 0;
    while (i)
    {
        visit(L[i].data);
        i = L[i].cur;
        //j++;
    }
    printf("\n");
    return OK;
}

int main()
{
    StaticLinkList L;

    InitList(L);
    printf("��ʼ����L.length=%d \n", ListLength(L));
    ListInsert(L, 1, 'u');
    ListInsert(L, 1, 'X');
    ListInsert(L, 1, ' ');
    ListInsert(L, 1, 'i');
    ListInsert(L, 1, 'a');
    ListInsert(L, 1, 'B');
    ListTraverse(L);
    ListDelete(L, 4);
    ListTraverse(L);
    getchar();
    return 0;
}