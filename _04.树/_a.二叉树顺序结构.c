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
/*二叉树最大节点数 */
#define MAX_TREE_SIZE

typedef int Status;
/*树结点的数据类型 */
typedef int ElemType;
/*0号单元存储根节点 */
typedef ElemType SqBiTree[MAX_TREE_SIZE];


typedef struct
{
    /*结点的蹭、本层序号（按满二叉树计算） */
    int level, order;
} Position;

/*设整型以0为空 */
ElemType Nil = 0;

Status visit(ElemType e)
{
    printf("%d ", e);
    return OK;
}


