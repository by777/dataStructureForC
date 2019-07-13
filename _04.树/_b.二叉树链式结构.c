/*
 * @Author: Xu Bai
 * @Date: 2019-07-13 22:24:04
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-07-13 22:29:40
 */
#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "io.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;

/* 用于构造二叉树********************************** */
int index = 1;
/*0号单元存放串的长度 */
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


