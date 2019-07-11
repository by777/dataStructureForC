/*
 * @Author: Xu Bai
 * @Date: 2019-07-09 22:50:41
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-07-11 22:44:11
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
#define MAX_TREE_SIZE

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
    printf("�밴�����������ֵ��int����0��ʾ�ս�㣬999��������ڵ�����%d\n", MAX_TREE_SIZE);
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
Status Value(SqBiTree T,Position e){
    return T[(int)powl(2,e.level-1)+e.order-2];
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

