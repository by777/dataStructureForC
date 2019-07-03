#include "stdlib.h"
#include "stdio.h"
#include "io.h"

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

typedef struct QNode
{
    ElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct
{
    QueuePtr front, rear;
} LinkQueue;

Status visit(ElemType e)
{
    printf("%d ", e);
    return OK;
}

Status InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if (!Q->front)
    {
        exit(-1);
    }
    Q->front->next = NULL;
    return OK;
}

Status Destroy(LinkQueue *Q)
{
    while (Q->front)
    {
        // Q->rearûɶ�þ�������Ϊ��ʱ�����洢��̽ڵ�
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}

Status ClearQueue(LinkQueue *Q)
{
    // ��������ȱ�����front���
    QueuePtr p, q;
    Q->rear = Q->front;
    p = Q->front->next;
    Q->front->next = NULL;
    while (p)
    {
        q = p;
        p = p->next;
        free(q);
    }
    return OK;
}

Status QueueEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
    {
        return TRUE;
    }
    return FALSE;
}

int QueueLength(LinkQueue Q)
{
    int i = 0;
    QueuePtr p;
    p = Q.front;
    while (Q.rear != p)
    {
        i++;
        p = p->next;
    }
    return i;
}

Status GetHead(LinkQueue Q, ElemType *e)
{
    QueuePtr p;
    if (Q.rear == Q.front)
    {
        return ERROR;
    }
    p = Q.front->next;
    *e = p->data;
    return OK;
}

Status EnQueue(LinkQueue *Q,ElemType e){
    Q
}