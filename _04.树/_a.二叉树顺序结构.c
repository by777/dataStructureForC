/*
 * @Author: Xu Bai
 * @Date: 2019-07-09 22:50:41
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-07-10 23:12:44
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

/*构造空二叉树 */
Status InitBiTree(SqBiTree T)
{
    int i;
    for (i = 0; i < MAX_TREE_SIZE; i++)
    {
        /*初值为空 */
        T[i] = Nil;
    }
    return OK;
}

/*按层序次序输入二叉树中结点的值（字符型或整型） */
Status CreateBiTree(SqBiTree T)
{
    int i = 0;
    printf("请按层序输入结点的值（int），0表示空结点，999表结束。节点数：%d\n", MAX_TREE_SIZE);
    while (i < 10)
    {
        T[i] = i + 1;
        /*此结点（不空）无双亲且不是根节点*/
        if (i != 0 && T[(i + 1) / 2 - 1] == Nil && T[i] != Nil)
        {
            printf("出现无双亲的非根结点%d\n", T[i]);
            exit(ERROR);
        }
        i++;
    }
    while (i < MAX_TREE_SIZE)
    {
        /*将空赋值给T后面的结点 */
        T[i] = Nil;
        i++;
    }
    return OK;
}

/*在顺序存储中，二者完全一样 */
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
        /*找到最后一个结点 */
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
    /*计算2的j次幂 */
    return j;
}

