/*
 * @Author: Xu Bai
 * @Date: 2019-07-09 22:50:41
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-07-09 23:02:42
 */
#include "stdlib.h"
#include "stdio.h"
#include "io.h"

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


