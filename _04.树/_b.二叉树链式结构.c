/*
 * @Author: Xu Bai
 * @Date: 2019-07-13 22:24:04
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-07-23 22:51:03
 */
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
//#include "io.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;

/* ���ڹ��������********************************** */
int index = 1;
/*0�ŵ�Ԫ��Ŵ��ĳ��� */
typedef char String[24];
String str;

Status StrAssign(String T, char *chars)
{
    int i;
    if (strlen(chars) > MAXSIZE)
    {
        return ERROR;
    }
    else
    {
        T[0] = strlen(chars);
        for (i = 2; i <= T[0]; i++)
        {
            T[i] = *(chars + i - 1);
        }
        return OK;
    }
}
/* ************************************************ */

typedef char ElemType;
/*�ַ����Կո�Ϊ�� */
ElemType Nil = '#';

Status visit(ElemType e)
{
    printf("%c ", e);
    return OK;
}

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild;

} BiTNode, *BiTree;

Status InitBiTree(BiTree *T)
{
    *T = NULL;
    return OK;
}

void DestroyBiTree(BiTree *T)
{
    if (*T)
    {
        if ((*T)->lchild)
        {
            DestroyBiTree(&(*T)->lchild);
        }
        if ((*T)->rchild)
        {
            DestroyBiTree(&(*T)->rchild);
        }
        free(*T);
        *T = NULL;
    }
}

#define ClearBiTree DestroyBiTree

void CreateBiTree(BiTree *T)
{
    ElemType ch;
    ch = str[index++];
    if (ch == '#')
    {
        *T = NULL;
    }
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!*T)
        {
            exit(-1);
        }
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

Status BiTreeEmpty(BiTree T)
{
    if (T)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

int BiTreeDepth(BiTree T)
{
    int i, j;
    if (!T)
    {
        return 0;
    }
    if (T->lchild)
    {
        i = BiTreeDepth(T->lchild);
    }
    else
    {
        i = 0;
    }
    if (T->rchild)
    {
        j = BiTreeDepth(T->rchild);
    }
    else
    {
        j = 0;
    }
    return i > j ? i + 1 : j + 1;
}

/*��T���ڣ�����T�ĸ� */
ElemType Root(BiTree T)
{
    if (BiTreeEmpty(T))
    {
        return Nil;
    }
    else
    {
        return T->data;
    }
}

/*����p��ָ����ֵ */
ElemType Value(BiTree T)
{
    return T->data;
}

void Assign(BiTree p, ElemType value)
{
    p->data = value;
}

void PreOrderTraverse(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    printf("%c ", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiTree T)
{
    if (T == NULL)
    {
        return;
    }

    InOrderTraverse(T->lchild);
    printf("%c ", T->data);
    InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BiTree T)
{
    if (T == NULL)
    {
        return;
    }

    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c ", T->data);
}

int main()
{
    int i;
    BiTree T;
    InitBiTree(&T);
    ElemType e1;
    StrAssign(str, "ABDH#K###E##CFI###G#J##");
    CreateBiTree(&T);
    printf("����ն�������,���շ�%d(1:�� 0:��) �������=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
    e1 = Root(T);
    printf("�������ĸ�Ϊ: %c\n", e1);

    printf("\nǰ�����������:");
    PreOrderTraverse(T);
    printf("\n�������������:");
    InOrderTraverse(T);
    printf("\n�������������:");
    PostOrderTraverse(T);
    ClearBiTree(&T);
    printf("\n�����������,���շ�%d(1:�� 0:��) �������=%d\n", BiTreeEmpty(T), BiTreeDepth(T));
    i = Root(T);
    if (!i)
        printf("���գ��޸�\n");

    getchar();
    return OK;
}