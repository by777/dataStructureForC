/*
 * @Author: Xu Bai
 * @Date: 2019-07-08 21:43:47
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-07-08 22:53:07
 */
#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "string.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100

typedef int Status;
typedef int ElemType;
typedef char String[MAXSIZE];

/*生成一个其值等于chars的字符串T */
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
        for (i = 1; i <= T[0]; i++)
        {
            T[i] = *(chars + i - 1);
        }
        return OK;
    }
}

/*清空串 */
Status ClearString(String S)
{
    S[0] = 0;
    return OK;
}

void StrPrint(String T)
{
    int i;
    for (i = 1; i <= T[0]; i++)
    {
        printf("%c ", T[i]);
    }
    printf("\n");
}

/*输出next数组 */
void NextPrint(int Next[], int Length)
{
    int i;
    for (i = 1; i <= Length; i++)
    {
        printf("%d ", Next[i]);
    }
    printf("\n");
}

int StrLength(String S)
{
    return S[0];
}

/*朴素匹配 */
int Index(String S, String T, int pos)
{
    int i = pos;
    /*i标记主串S的下标 */
    int j = 1;
    /*j为模式串T的下标 */
    while (i <= S[0] && j <= T[0])
    {
        if (S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }

        if (j > T[0])
        {
            return i - T[0];
        }
        else
        {
            return 0;
        }
    }
}

/*计算生成模式串T的Next数组 */
void GetNext(String T, int *Next)
{
    int i, j;
    i = 1;
    j = 0;
    Next[1] = 0;
    while (i < T[0])
    {
        if (j == 0 || T[i] == T[j])
        {
            ++i;
            ++j;
            Next[i] = j;
        }
        else
        {
            j = Next[j];
        }
    }
}

/*返回子串（模式串）T在主串S中第pos个字符之后?位置，若不存在返回0 */
int IndexByKMP(String S, String T, int pos)
{
    int i = pos;
    int j = 1;
    int next[255];
    GetNext(T, next);
    while (i <= S[0] && j <= T[0])
    {
        if (j == 0 || S[i] == T[i])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }
    if (j > T[0])
    {
        return i - T[0];
    }
    else
    {
        return 0;
    }
}

/*计算Nextval数组 */
void GetNextVal(String T, int *NextVal)
{
    int i, j;
    i = 1;
    j = 0;
    NextVal[1] = 0;
    while (i < T[0])
    {
        if (j == 0 || T[i] == T[j])
        {
            /*T[i]表示后缀的单个字符，T[j]前缀 */
            ++i;
            ++j;
            if (T[i] != T[j])
            {
                /*若当前字符与前缀字符不同，则当前的j为NextVal在i位置的值*/
                NextVal[i] = j;
            }
            else
            {
                /*若与前缀字符相同，则将前缀字符的nextval值赋值给nextval在i位置的值 */
                NextVal[i] = NextVal[j];
            }
        }
        else
        {
            /*若字符不相同，则j回溯 */
            j = NextVal[j];
        }
    }
}

int IndexByKMP1(String S, String T, int pos)
{
    /*i用来主串S当前位置下标值 */
    int i = pos;
    int j = 1;
    int next[255];
    GetNextVal(T, next);
    while (i <= S[0] && j <= T[0])
    {
        /* 若i小于S的长度并且j小于T的长度时，循环继续 */
        if (j == 0 || S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
            /* j退回合适的位置，i值不变 */
        }
    }
    if (j > T[0])
    {
        return i - T[0];
    }
    else
    {
        return 0;
    }
}

int main()
{
    int i, *p;
    String s1, s2;

    StrAssign(s1, "abcdex");
    printf("子串为: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    GetNext(s1, p);
    printf("Next为: ");
    NextPrint(p, StrLength(s1));
    printf("--------------------------------\n");

    StrAssign(s1, "abcabx");
    printf("子串为: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    GetNext(s1, p);
    printf("Next为: ");
    NextPrint(p, StrLength(s1));
    printf("--------------------------------\n");

    StrAssign(s1, "ababaaaba");
    printf("子串为: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    GetNext(s1, p);
    printf("Next为: ");
    NextPrint(p, StrLength(s1));
    printf("--------------------------------\n");

    StrAssign(s1, "aaaaaaaab");
    printf("子串为: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    GetNext(s1, p);
    printf("Next为: ");
    NextPrint(p, StrLength(s1));
    printf("--------------------------------\n");

    StrAssign(s1, "ababaaaba");
    printf("   子串为: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    GetNext(s1, p);
    printf("   Next为: ");
    NextPrint(p, StrLength(s1));
    GetNextVal(s1, p);
    printf("NextVal为: ");
    NextPrint(p, StrLength(s1));
    printf("--------------------------------\n");

    StrAssign(s1, "aaaaaaaab");
    printf("   子串为: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    GetNext(s1, p);
    printf("   Next为: ");
    NextPrint(p, StrLength(s1));
    GetNextVal(s1, p);
    printf("NextVal为: ");
    NextPrint(p, StrLength(s1));

    printf("--------------------------------\n");

    StrAssign(s1, "00000000000000000000000000000000000000000000000001");
    printf("主串为: ");
    StrPrint(s1);
    StrAssign(s2, "0000000001");
    printf("子串为: ");
    StrPrint(s2);
    printf("--------------------------------\n");
    printf("主串和子串在第%d个字符处首次匹配（朴素模式匹配算法）\n", Index(s1, s2, 1));
    printf("主串和子串在第%d个字符处首次匹配（KMP算法） \n", IndexByKMP(s1, s2, 1));
    printf("主串和子串在第%d个字符处首次匹配（KMP改良算法） \n", IndexByKMP1(s1, s2, 1));

    getchar();
    return OK;
}