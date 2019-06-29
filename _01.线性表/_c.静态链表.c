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
    int cur; // 游标，为0时无指向
} Component, StaticLinkList[MAXSIZE];

Status InitList(StaticLinkList space)
{
    // 将一维数组space中各分量廉成一个备用链表
    // space[0].cur为头指针，空指针标志位0
    int i;
    for (i = 0; i < MAXSIZE - 1; i++)
    {
        space[i].cur = i + 1;
    }
    space[MAXSIZE - 1].cur = 0;
    // 构建静态链表，并表尾置0
    return OK;
}

int Malloc_SSL(StaticLinkList space)
{
    // 若备用链表非空，则返回分配的结点下标，否则返回0
    //
    int i = space[0].cur;
    // 当前数组第一个元素的cur存的值
    // 第一个备用空闲的下标
    if (space[0].cur)
    {
        // 由于要拿出一个分量来使用了，所以我们把它的
        // 下一个分量拿来做备用
        space[0].cur = space[i].cur;
    }
    return i;
}

void Free_SSL(StaticLinkList space, int k)
{ // 将下标为k的空闲链表回收到备用链表
    // 把第一个元素的cur值赋给要删除的分量cur
    space[k].cur = space[0].cur;
    // 保存要删除结点的后继节点信息
    // 把要删除的分量下标赋值给第一个元素的cur
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
    // 获得空闲分量的下标
    int k = MAXSIZE - 1;
    int l;
    if (j)
    {
        L[j].data = e;
        for (l = 1; l <= i - 1; l++)
        {
            // 找到第i个元素之前的位置赋值给k
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;
        //将第i个元素之前的cur赋值给新元素的cur
        L[k].cur = j;
        // 将j插入
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
    printf("初始化后：L.length=%d \n", ListLength(L));
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