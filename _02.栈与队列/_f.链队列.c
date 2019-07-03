/*
 * @Author: Xu Bai
 * @Date: 2019-07-03 21:37:15
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-07-03 22:46:26
 */

#include "stdlib.h"
#include "stdio.h"
#include "io.h"

#define MAXSIZE 20
#define OVERFLOW -1
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
        exit(OVERFLOW);
    }
    Q->front->next = NULL;
    return OK;
}

Status DestroyQueue(LinkQueue *Q)
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

Status EnQueue(LinkQueue *Q, ElemType e)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
    if (!p)
    {
        exit(OVERFLOW);
    }
    p->data = e;
    p->next = NULL;
    Q->rear->next = p; //���ӵ���β
    Q->rear = p;
    return OK;
}

Status DeQueue(LinkQueue *Q, ElemType *e)
{
    if (Q->rear == Q->front)
    {
        return ERROR;
    }
    QueuePtr p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p)
    {
        // ��������ͷ�ڵ���ֻʣ��һ��Ԫ��ʱ�����轫rearָ��ͷ�ڵ�
        //����ͷ���Ƕ�β����ɾ����rearָ��front
        Q->rear = Q->front;
    }
    free(p);
    return OK;
}

Status QueueTraverse(LinkQueue Q)
{
    QueuePtr p;
    p = Q.front->next;
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
    ElemType e;
    LinkQueue q;
    int i = InitQueue(&q);
    if (i)
    {
        printf("inited! \n");
        printf("Empty? 1 or 0: %d\n", QueueEmpty(q));
    }
    EnQueue(&q, -5);
    EnQueue(&q, 5);
    EnQueue(&q, 10);
    printf("����3��Ԫ��(-5,5,10)��,���еĳ���Ϊ%d\n", QueueLength(q));
    QueueTraverse(q);
    i = GetHead(q, &e);
    if (i == OK)
        printf("��ͷԪ���ǣ�%d\n", e);
    DeQueue(&q, &e);
    printf("ɾ���˶�ͷԪ��%d\n", e);
    QueueTraverse(q);
    ClearQueue(&q);
    printf("��ն��к�,q.front=%u q.rear=%u q.front->next=%u\n", q.front, q.rear, q.front->next);
    DestroyQueue(&q);
    printf("���ٶ��к�,q.front=%u q.rear=%u\n", q.front, q.rear);
    getchar();
}