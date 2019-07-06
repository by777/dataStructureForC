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
// 0位置用来存字符串长度

Status StrAssign(String T, char *chars)
{
    // 生成一个其值等于chars的串T
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
    // 注意此处并没有维护T[0]，存疑
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
    // 若S>T,返回值>0;S=T,返回值=0；否则<0
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
    // 可以注意到String为引用型
    S[0] = 0;
    return OK;
}

Status Concat(String T, String S1, String S2)
{
    // 用T返回S1+S2拼接串。若未截断返回TRUE，否则FALSE
    int i;
    if (S1[0] + S2[0] <= MAXSIZE)
    {
        // 未截断
        for (i = 1; i <= S1[0]; i++)
        {
            T[i] = S1[i];
        }
        for (i = 1; i <= MAXSIZE - S1[0]; i++)
        // i上界存疑
        {
            T[S1[0] + i] = S2[i];
        }
        T[0] = S1[0] + S2[0];
        return TRUE;
    }
    else
    {
        //截断S2
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