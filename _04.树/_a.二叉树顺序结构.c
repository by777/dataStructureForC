/*
 * @Author: Xu Bai
 * @Date: 2019-07-09 22:50:41
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-07-12 22:59:06
 */
#include "stdlib.h"
#include "stdio.h"
#include "io.h"
#include "math.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100
/*���������ڵ��� */
#define MAX_TREE_SIZE 100

typedef int Status;
/*�������������� */
typedef int ElemType;
/*0�ŵ�Ԫ�洢���ڵ� */
typedef ElemType SqBiTree[MAX_TREE_SIZE];

typedef struct
{
    /*���Ĳ䡢������ţ��������������㣩 */
    int level, order;
} Position;

/*��������0Ϊ�� */
ElemType Nil = 0;

Status visit(ElemType e)
{
    printf("%d ", e);
    return OK;
}

/*����ն����� */
Status InitBiTree(SqBiTree T)
{
    int i;
    for (i = 0; i < MAX_TREE_SIZE; i++)
    {
        /*��ֵΪ�� */
        T[i] = Nil;
    }
    return OK;
}

/*�������������������н���ֵ���ַ��ͻ����ͣ� */
Status CreateBiTree(SqBiTree T)
{
    int i = 0;
 	printf("�밴�����������ֵ(����)��0��ʾ�ս�㣬��999�������������%d:\n",MAX_TREE_SIZE);
    while (i < 10)
    {
        T[i] = i + 1;
        /*�˽�㣨���գ���˫���Ҳ��Ǹ��ڵ�*/
        if (i != 0 && T[(i + 1) / 2 - 1] == Nil && T[i] != Nil)
        {
            printf("������˫�׵ķǸ����%d\n", T[i]);
            exit(ERROR);
        }
        i++;
    }
    while (i < MAX_TREE_SIZE)
    {
        /*���ո�ֵ��T����Ľ�� */
        T[i] = Nil;
        i++;
    }
    return OK;
}

/*��˳��洢�У�������ȫһ�� */
#define ClearBiTree InitBiTree

Status BiTreeEmpty(SqBiTree T)
{
    if (T[0] == Nil)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int BiTreeDepth(SqBiTree T)
{
    int i, j = -1;
    for (i = MAX_TREE_SIZE - 1; i >= 0; i--)
    {
        /*�ҵ����һ����� */
        if (T[i] != Nil)
        {
            break;
        }
    }
    i++;
    do
    {
        j++;
    } while (i >= powl(2, j));
    /*����2��j���� */
    return j;
}

/*��T���գ���e����T�ĸ�������OK�����򷵻�ERROR��e�޶��� */
Status Root(SqBiTree T, ElemType *e)
{
    if (BiTreeEmpty(T))
    {
        return ERROR;
    }
    else
    {
        *e = T[0];
        return OK;
    }
}

/*���ش���eλ�ã��㣬������� ���Ľ���ֵ*/
Status Value(SqBiTree T, Position e)
{
    return T[(int)powl(2, e.level - 1) + e.order - 2];
}

/*������λ��e�Ľ�㸳��ֵvalue */
Status Assign(SqBiTree T, Position p, ElemType e)
{
    /*���㡢�������תΪ�������� */
    int i = (int)powl(2, p.level - 1) + p.order - 2;
    /*��Ҷ�Ӹ��ǿ�ֵ��˫��Ϊ�� */
    if (e != Nil && T[(i + 1) / 2 - 1] == Nil)
    {
        return ERROR;
    }
    /*  ��˫�׸���ֵ����Ҷ�ӣ����գ� */
    else if (e == Nil && (T[i * 2 + 1] != Nil || T[i * 2 + 2] != Nil))
    {
        return ERROR;
    }
    T[i] = e;
    return OK;
}

/*��e��T�ķǸ���㣬�򷵻�����˫�ף����򷵻ء��ա� */
ElemType Parent(SqBiTree T, ElemType e)
{
    int i;
    if (T[0] == Nil)
    {
        return Nil;
    }
    for (i = 1; i <= MAX_TREE_SIZE - 1; i++)
    {
        if (T[i] == e)
        {
            return T[(i + 1) / 2 - 1];
        }
    }
    return Nil;
}

ElemType LeftChild(SqBiTree T, ElemType e)
{
    int i;
    if (T[0] == Nil)
    {
        return Nil;
    }
    for (i = 0; i <= MAX_TREE_SIZE - 1; i++)
    {
        if (T[i] == e)
        {
            return T[i * 2 + 1];
        }
    }
    return Nil;
}

ElemType RightChild(SqBiTree T, ElemType e)
{
    int i;
    if (T[0] == Nil) /* ���� */
        return Nil;
    for (i = 0; i <= MAX_TREE_SIZE - 1; i++)
        if (T[i] == e) /* �ҵ�e */
            return T[i * 2 + 2];
    return Nil; /* û�ҵ�e */
}

/*����e�����ֵ� */
ElemType LeftSibling(SqBiTree T, ElemType e)
{
    int i;
    if (T[0] == Nil)
    {
        return Nil;
    }
    for (i = 1; i < MAX_TREE_SIZE; i++)
    {
        if (T[i] == e && i % 2 == 0)
        {
            /* �ҵ�e�������Ϊż�������Һ��ӣ� */
            return T[i - 1];
        }
    }
    return Nil;
}

/*����e�����ֵ� */
ElemType RightSibling(SqBiTree T, ElemType e)
{
    int i;
    if (T[0] == Nil)
    {
        return Nil;
    }
    for (i = 1; i < MAX_TREE_SIZE; i++)
    {
        if (T[i] == e && i % 2 == 1)
        {
            /* �ҵ�e�������Ϊż�������Һ��ӣ� */
            return T[i + 1];
        }
    }
    return Nil;
}

void PreTraverse(SqBiTree T, int e)
{
    visit(T[e]);
    if (T[2 * e + 1] != Nil)
    {
        /* ���������� */
        PreTraverse(T, 2 * e + 1);
    }
    if (T[2 * e + 2] != Nil)
    {
        /* ���������� */
        PreTraverse(T, 2 * e + 2);
    }
}

Status PreOrderTraverse(SqBiTree T)
{
    if (!BiTreeEmpty(T))
    {
        PreTraverse(T, 0);
    }
    printf("\n");
    return OK;
}

void InTraverse(SqBiTree T, int e)
{
    if (T[2 * e + 1] != Nil)
    {
        InTraverse(T, 2 * e + 1);
    }
    visit(T[e]);
    if (T[2 * e + 2] != Nil)
    {
        InTraverse(T, 2 * e + 2);
    }
}

Status InOrderTraverse(SqBiTree T)
{
    if (!BiTreeEmpty(T)) /* ������ */
        InTraverse(T, 0);
    printf("\n");
    return OK;
}

void PostTraverse(SqBiTree T, int e)
{
    if (T[2 * e + 1] != Nil) /* ���������� */
        PostTraverse(T, 2 * e + 1);
    if (T[2 * e + 2] != Nil) /* ���������� */
        PostTraverse(T, 2 * e + 2);
    visit(T[e]);
}

/* ��ʼ����: ������T���� */
/* �������: �������T�� */
Status PostOrderTraverse(SqBiTree T)
{
    if (!BiTreeEmpty(T)) /* ������ */
        PostTraverse(T, 0);
    printf("\n");
    return OK;
}

/*������� */
void LevelOrderTraverse(SqBiTree T)
{
    int i = MAX_TREE_SIZE;
    int j;
    while (T[i] != Nil)
    {
        /* �ҵ����һ���ǿյĽ����� */
        i--;
    }
    for (j = 0; j <= i; j++)
    {
        /* �Ӹ��ڵ��𣬰�������������� */
        if (T[j] != Nil)
        {
            visit(T[j]);
        }
    }
    printf("\n");
}

/*��㰴���������������� */
void Print(SqBiTree T)
{
    int j, k;
    Position p;
    ElemType e;
    for (j = 1; j <= BiTreeDepth(T); j++)
    {
        printf("��%d�㣺", j);
        for (k = 1; k <= powl(2, j - 1); k++)
        {
            p.level = j;
            p.order = k;
            e = Value(T, p);
            if (e != Nil)
            {
                printf("%d: %d", k, e);
            }
        }
        printf("\n");
    }
}

int main()
{
    Status i;
    Position p;
    ElemType e;
    SqBiTree T;
    InitBiTree(T);
    CreateBiTree(T);
    printf("������������,���շ�%d(1:�� 0:��) �������=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
    i = Root(T, &e);
    if (i)
        printf("�������ĸ�Ϊ��%d\n", e);
    else
        printf("���գ��޸�\n");
    printf("�������������:\n");
    LevelOrderTraverse(T);
    printf("ǰ�����������:\n");
    PreOrderTraverse(T);
    printf("�������������:\n");
    InOrderTraverse(T);
    printf("�������������:\n");
    PostOrderTraverse(T);
    printf("�޸Ľ��Ĳ��3�������2��");
    p.level = 3;
    p.order = 2;
    e = Value(T, p);
    printf("���޸Ľ���ԭֵΪ%d��������ֵ:50 ", e);
    e = 50;
    Assign(T, p, e);
    printf("ǰ�����������:\n");
    PreOrderTraverse(T);
    printf("���%d��˫��Ϊ%d,���Һ��ӷֱ�Ϊ", e, Parent(T, e));
    printf("%d,%d,�����ֱֵܷ�Ϊ", LeftChild(T, e), RightChild(T, e));
    printf("%d,%d\n", LeftSibling(T, e), RightSibling(T, e));
    ClearBiTree(T);
    printf("�����������,���շ�%d(1:�� 0:��) �������=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
    i = Root(T, &e);
    if (i)
        printf("�������ĸ�Ϊ��%d\n", e);
    else
        printf("���գ��޸�\n");

    getchar();
    return OK;
}