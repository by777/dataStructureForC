/*
 * @Author: Xu Bai
 * @Date: 2019-07-02 22:06:31
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-07-02 22:39:29
 */
#include "stdlib.h"
#include "io.h"
#include "stdio.h"

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int front;
    int rear;
} SqQueue;

Status visit(ElemType e)
{
    printf("%d ", e);
    return OK;
}

Status InitQueue(SqQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

Status CleatQueue(SqQueue *Q)
{
    Q->front = Q->rear = 0;
    return OK;
}

Status QuequEmpty(SqQueue Q)
{
    if (Q.front == Q.rear)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int QueueLength(SqQueue Q)
{
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

Status GetHead(SqQueue Q, ElemType *e)
{
    if (Q.front = Q.rear)
    {
        return ERROR;
    }
    else
    {
        *e = Q.data[Q.front];
        return OK;
    }
}

Status EnQueue(SqQueue *Q, ElemType e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front)
    {
        // ¶ÓÁÐÂú
        printf("full!\n");
        return ERROR;
    }
    else
    {
        Q->data[Q->rear] = e;
        Q->rear = (Q->rear + 1) % MAXSIZE;
        return OK;
    }
}

Status DeQueue(SqQueue *Q, ElemType *e)
{
    if (Q->front == Q->rear)
    {
        printf("Empty!\n");
        return ERROR;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAXSIZE;
    return OK;
}

Status QueueTraverse(SqQueue Q)
{
    int i = Q.front;
    while ((i + Q.front) != Q.rear)
    {
        visit(Q.data[i]);
        i = (i + 1) % MAXSIZE;
    }
    printf("\n");
    return OK;
}

int main()
{
    ElemType e;
    SqQueue q;
    InitQueue(&q);
    int i;
    printf("EnQueue!\n");
    for (i = 0; i < MAXSIZE; i++)
    {
        EnQueue(&q, i);
    }

    QueueTraverse(q);
    printf("DeQueue!\n");
    DeQueue(&q, &e);

    QueueTraverse(q);
    CleatQueue(&q);
    if (QuequEmpty(q))
    {
        printf("empty!\n");
    }
    getchar();
    return OK;
}
