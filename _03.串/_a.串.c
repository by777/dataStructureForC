/*
 * @Author: Xu Bai
 * @Date: 2019-07-06 22:20:08
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-07-06 23:50:11
 */

#include "string.h"
#include "stdio.h"
#include "stdlib.h"
#include "io.h"

#define MAXSIZE 40
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

typedef char String[MAXSIZE + 1];
// 0λ���������ַ�������

Status StrAssign(String T, char *chars)
{
    // ����һ����ֵ����chars�Ĵ�T
    int i;
    if (strlen(chars) > MAXSIZE)
    {
        return ERROR;
    }
    else
    {
        T[0] = strlen(chars);
        for (i = 1; i <= T[0]; i++)
        {
            T[i] = *(chars + i - 1);
        }
        return OK;
    }
}

Status StrCopy(String T, String S)
{

    int i;
    for (i = 0; i <= S[0]; i++)
    {
        T[i] = S[i];
    }
    return OK;
}

Status StrEmpty(String S)
{
    if (S[0] == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int StrCompare(String S, String T)
{
    // ��S>T,����ֵ>0;S=T,����ֵ=0������<0
    int i;
    for (i = 1; i <= S[0] && i <= T[0]; i++)
    {
        if (S[i] != T[i])
        {
            return S[i] - T[i];
        }
    }
    return S[0] - T[0];
}

int StrLength(String S)
{
    return S[0];
}

Status ClearString(String S)
{
    // ����ע�⵽StringΪ������
    S[0] = 0;
    return OK;
}

Status Concat(String T, String S1, String S2)
{
    // ��T����S1+S2ƴ�Ӵ�����δ�ضϷ���TRUE������FALSE
    int i;
    if (S1[0] + S2[0] <= MAXSIZE)
    {
        // δ�ض�
        for (i = 1; i <= S1[0]; i++)
        {
            T[i] = S1[i];
        }

        /*
        ԭ���룺
        for (i = 1; i <= MAXSIZE - S1[0]; i++)
        ��i�Ͻ����
        ��if�������Ѿ��жϲ���Խ�磬Ӧ�÷��ĸ���
         */

        for (i = 1; i <= S2[0]; i++)
        {
            T[S1[0] + i] = S2[i];
        }
        T[0] = S1[0] + S2[0];
        return TRUE;
    }
    else
    {
        //�ض�S2
        for (i = 1; i < S1[0]; i++)
        {
            T[i] = S1[i];
        }
        for (i = 1; i <= MAXSIZE - S1[0]; i++)
        {
            T[S1[0] + i] = S2[i];
        }
        T[0] = MAXSIZE;
        return FALSE;
    }
}

Status SubString(String Sub, String S, int pos, int len)
{
    // ��Sub���ش�S�Ĵӵ�pos�𳤶�Ϊlen���ִ�
    int i;
    if (pos < 1 || len < 0 || len > S[0] - pos + 1 || pos > S[0])
    {
        return ERROR;
    }
    for (i = 1; i <= len; i++)
    {
        Sub[i] = S[pos + i - 1];
    }
    Sub[0] = len;
    return OK;
}

int main()
{
    char chars[] = "ABCD";
    String T = " ";
    StrAssign(T, chars);
    printf("%s \n", T);
    printf("%c", T[3]);

    getchar();
    return OK;
}