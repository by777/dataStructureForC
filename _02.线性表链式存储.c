/*
 * @Author: Xu Bai
 * @Date: 2019-06-26 22:48:42
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-06-26 22:55:57
 */
#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"
#include "io.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef int Status;
typedef int ElemType;

Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;

typedef struct Node *LinkList;

