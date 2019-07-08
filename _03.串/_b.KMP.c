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

/*����һ����ֵ����chars���ַ���T */
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

/*��մ� */
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

/*���next���� */
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

/*����ƥ�� */
int Index(String S, String T, int pos)
{
    int i = pos;
    /*i�������S���±� */
    int j = 1;
    /*jΪģʽ��T���±� */
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

/*��������ģʽ��T��Next���� */
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

/*�����Ӵ���ģʽ����T������S�е�pos���ַ�֮��?λ�ã��������ڷ���0 */
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

/*����Nextval���� */
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
            /*T[i]��ʾ��׺�ĵ����ַ���T[j]ǰ׺ */
            ++i;
            ++j;
            if (T[i] != T[j])
            {
                /*����ǰ�ַ���ǰ׺�ַ���ͬ����ǰ��jΪNextVal��iλ�õ�ֵ*/
                NextVal[i] = j;
            }
            else
            {
                /*����ǰ׺�ַ���ͬ����ǰ׺�ַ���nextvalֵ��ֵ��nextval��iλ�õ�ֵ */
                NextVal[i] = NextVal[j];
            }
        }
        else
        {
            /*���ַ�����ͬ����j���� */
            j = NextVal[j];
        }
    }
}

int IndexByKMP1(String S, String T, int pos)
{
    /*i��������S��ǰλ���±�ֵ */
    int i = pos;
    int j = 1;
    int next[255];
    GetNextVal(T, next);
    while (i <= S[0] && j <= T[0])
    {
        /* ��iС��S�ĳ��Ȳ���jС��T�ĳ���ʱ��ѭ������ */
        if (j == 0 || S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
            /* j�˻غ��ʵ�λ�ã�iֵ���� */
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
    printf("�Ӵ�Ϊ: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    GetNext(s1, p);
    printf("NextΪ: ");
    NextPrint(p, StrLength(s1));
    printf("--------------------------------\n");

    StrAssign(s1, "abcabx");
    printf("�Ӵ�Ϊ: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    GetNext(s1, p);
    printf("NextΪ: ");
    NextPrint(p, StrLength(s1));
    printf("--------------------------------\n");

    StrAssign(s1, "ababaaaba");
    printf("�Ӵ�Ϊ: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    GetNext(s1, p);
    printf("NextΪ: ");
    NextPrint(p, StrLength(s1));
    printf("--------------------------------\n");

    StrAssign(s1, "aaaaaaaab");
    printf("�Ӵ�Ϊ: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    GetNext(s1, p);
    printf("NextΪ: ");
    NextPrint(p, StrLength(s1));
    printf("--------------------------------\n");

    StrAssign(s1, "ababaaaba");
    printf("   �Ӵ�Ϊ: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    GetNext(s1, p);
    printf("   NextΪ: ");
    NextPrint(p, StrLength(s1));
    GetNextVal(s1, p);
    printf("NextValΪ: ");
    NextPrint(p, StrLength(s1));
    printf("--------------------------------\n");

    StrAssign(s1, "aaaaaaaab");
    printf("   �Ӵ�Ϊ: ");
    StrPrint(s1);
    i = StrLength(s1);
    p = (int *)malloc((i + 1) * sizeof(int));
    GetNext(s1, p);
    printf("   NextΪ: ");
    NextPrint(p, StrLength(s1));
    GetNextVal(s1, p);
    printf("NextValΪ: ");
    NextPrint(p, StrLength(s1));

    printf("--------------------------------\n");

    StrAssign(s1, "00000000000000000000000000000000000000000000000001");
    printf("����Ϊ: ");
    StrPrint(s1);
    StrAssign(s2, "0000000001");
    printf("�Ӵ�Ϊ: ");
    StrPrint(s2);
    printf("--------------------------------\n");
    printf("�������Ӵ��ڵ�%d���ַ����״�ƥ�䣨����ģʽƥ���㷨��\n", Index(s1, s2, 1));
    printf("�������Ӵ��ڵ�%d���ַ����״�ƥ�䣨KMP�㷨�� \n", IndexByKMP(s1, s2, 1));
    printf("�������Ӵ��ڵ�%d���ַ����״�ƥ�䣨KMP�����㷨�� \n", IndexByKMP1(s1, s2, 1));

    getchar();
    return OK;
}