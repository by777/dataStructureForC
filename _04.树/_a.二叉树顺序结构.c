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
/*二叉树最大节点数 */
#define MAX_TREE_SIZE 100

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
 	printf("请按层序输入结点的值(整型)，0表示空结点，输999结束。结点数≤%d:\n",MAX_TREE_SIZE);
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

/*当T不空，用e返回T的根，返回OK；否则返回ERROR，e无定义 */
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

/*返回处于e位置（层，本层序号 ）的结点的值*/
Status Value(SqBiTree T, Position e)
{
    return T[(int)powl(2, e.level - 1) + e.order - 2];
}

/*将处于位置e的结点赋新值value */
Status Assign(SqBiTree T, Position p, ElemType e)
{
    /*将层、本层序号转为矩阵的序号 */
    int i = (int)powl(2, p.level - 1) + p.order - 2;
    /*给叶子赋非空值但双亲为空 */
    if (e != Nil && T[(i + 1) / 2 - 1] == Nil)
    {
        return ERROR;
    }
    /*  给双亲赋空值但有叶子（不空） */
    else if (e == Nil && (T[i * 2 + 1] != Nil || T[i * 2 + 2] != Nil))
    {
        return ERROR;
    }
    T[i] = e;
    return OK;
}

/*若e是T的非根结点，则返回它的双亲，否则返回“空” */
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
    if (T[0] == Nil) /* 空树 */
        return Nil;
    for (i = 0; i <= MAX_TREE_SIZE - 1; i++)
        if (T[i] == e) /* 找到e */
            return T[i * 2 + 2];
    return Nil; /* 没找到e */
}

/*返回e的左兄弟 */
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
            /* 找到e且其序号为偶数（是右孩子） */
            return T[i - 1];
        }
    }
    return Nil;
}

/*返回e的右兄弟 */
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
            /* 找到e且其序号为偶数（是右孩子） */
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
        /* 左子树不空 */
        PreTraverse(T, 2 * e + 1);
    }
    if (T[2 * e + 2] != Nil)
    {
        /* 左子树不空 */
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
    if (!BiTreeEmpty(T)) /* 树不空 */
        InTraverse(T, 0);
    printf("\n");
    return OK;
}

void PostTraverse(SqBiTree T, int e)
{
    if (T[2 * e + 1] != Nil) /* 左子树不空 */
        PostTraverse(T, 2 * e + 1);
    if (T[2 * e + 2] != Nil) /* 右子树不空 */
        PostTraverse(T, 2 * e + 2);
    visit(T[e]);
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 后序遍历T。 */
Status PostOrderTraverse(SqBiTree T)
{
    if (!BiTreeEmpty(T)) /* 树不空 */
        PostTraverse(T, 0);
    printf("\n");
    return OK;
}

/*层序遍历 */
void LevelOrderTraverse(SqBiTree T)
{
    int i = MAX_TREE_SIZE;
    int j;
    while (T[i] != Nil)
    {
        /* 找到最后一个非空的结点序号 */
        i--;
    }
    for (j = 0; j <= i; j++)
    {
        /* 从根节点起，按层序遍历二叉树 */
        if (T[j] != Nil)
        {
            visit(T[j]);
        }
    }
    printf("\n");
}

/*逐层按本层序号输出二叉树 */
void Print(SqBiTree T)
{
    int j, k;
    Position p;
    ElemType e;
    for (j = 1; j <= BiTreeDepth(T); j++)
    {
        printf("第%d层：", j);
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
    printf("建立二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
    i = Root(T, &e);
    if (i)
        printf("二叉树的根为：%d\n", e);
    else
        printf("树空，无根\n");
    printf("层序遍历二叉树:\n");
    LevelOrderTraverse(T);
    printf("前序遍历二叉树:\n");
    PreOrderTraverse(T);
    printf("中序遍历二叉树:\n");
    InOrderTraverse(T);
    printf("后序遍历二叉树:\n");
    PostOrderTraverse(T);
    printf("修改结点的层号3本层序号2。");
    p.level = 3;
    p.order = 2;
    e = Value(T, p);
    printf("待修改结点的原值为%d请输入新值:50 ", e);
    e = 50;
    Assign(T, p, e);
    printf("前序遍历二叉树:\n");
    PreOrderTraverse(T);
    printf("结点%d的双亲为%d,左右孩子分别为", e, Parent(T, e));
    printf("%d,%d,左右兄弟分别为", LeftChild(T, e), RightChild(T, e));
    printf("%d,%d\n", LeftSibling(T, e), RightSibling(T, e));
    ClearBiTree(T);
    printf("清除二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
    i = Root(T, &e);
    if (i)
        printf("二叉树的根为：%d\n", e);
    else
        printf("树空，无根\n");

    getchar();
    return OK;
}