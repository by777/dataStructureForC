/*
 * @Author: Xu Bai
 * @Date: 2019-07-06 22:20:08
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-07-08 00:10:40
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

int Index(String S, String T, int pos)
{
    // �����Ӵ�T������S�е�pos���ַ�֮���λ�á��������ڣ��򷵻�0
    //���У�T�ǿգ�1��pos��StrLength(S)
    int i = pos;
    // i��������S�е�ǰλ�õ��±�ֵ����pos��Ϊ1���posλ�ÿ�ʼƥ��
    int j = 1;
    // j�����Ӵ�T�е�ǰλ���±�ֵ
    while (i <= S[0] && j <= T[0])
    {
        if (S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            //ָ��������¿�ʼƥ��
            i = i - j + 2; // i�˻��ϴ�ƥ����λ��һλ
            j = 1;         //j�˻��Ӵ�T����λ
        }
    }
    if (j > T[0])
    {
        //�ҵ���ƥ��λ��
        return i - T[0];
    }
    else
    {
        return 0;
    }
}

int index2(String S, String T, int pos)
{
    // TΪ�ǿմ���������S�д��ڵ�pos���ַ�֮�������T��ȵ��Ӵ�
    // �򷵻ص�һ���������Ӵ���S�е�λ�ã����򷵻�0
    int n, m, i;
    String sub;
    if (pos > 0)
    {
        n = StrLength(S); //����
        m = StrLength(T); //�Ӵ�
        i = pos;
        while (i <= n - m + 1)
        {
            SubString(sub, S, i, m);
            //ȡ�Ӵ��е�i��λ�ó�����T��ȵ��Ӵ���sub
            if (StrCompare(sub, T) != 0)
            {
                ++i;
            }
            else
            {
                // �������
                return i;
            }
        }
    }
    return 0;
}

// �ڴ�s�ĵ�pos���ַ�֮ǰ���봮T����ȫ�����򷵻�TRUE
Status StrInsert(String S, int pos, String T)
{
    int i;
    if (pos < 1 || pos > S[0] + 1)
    {
        return ERROR;
    }
    if (S[0] + T[0] <= MAXSIZE)
    {
        // ������ȫ����
        for (i = S[0]; i >= pos; i--)
        {
            S[i + T[0]] = S[i];
        }
        for (i = pos; i < pos + T[0]; i++)
        {
            S[i] = T[i - pos + 1];
        }
        S[0] = S[0] + T[0];
        return TRUE;
    }
    else
    {
        for (i = MAXSIZE; i <= pos; i--)
        {
            S[i] = S[i - T[0]]; // �Ӻ���ǰ
        }
        for (i = pos; i < pos + T[0]; i++)
        {
            S[i] = T[i - pos + 1];
        }
        S[0] = MAXSIZE;
        return FALSE;
    }
}

// �Ӵ�S��ɾ����pos���ַ��𳤶�Ϊlen���Ӵ�
Status StrDelete(String S, int pos, int len)
{
    int i;
    if (pos < 1 || pos > S[0] - len + 1 || len < 0)
    {
        return ERROR;
    }
    for (i = pos + len; i < S[0]; i++)
    {
        S[i - len] = S[i];
    }
    S[0] -= len;
    return OK;
}

// ��V�滻����S�г��ֵ�������T��ȵĲ��ص����Ӵ�
Status Replace(String S, String T, String V)
{

    int i = 1;
    if (StrEmpty(T))
    {
        return ERROR;
    }

    do
    {
        i = Index(S, T, i);
        // iΪ����һ��i֮���ҵ����Ӵ�T��λ��
        if (i)
        {
            // ��S�д���T
            StrDelete(S, i, StrLength(T));
            StrInsert(S, i, V);
            i += StrLength(V);
            //�ڲ���Ĵ�V��������Ҵ�T
        }
    } while (i);
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

int main()
{
    Status k;
    String s1, s2;
    k = StrAssign(s1, "bai_xu");
    if (!k)
    {
        printf("ERROR!\n");
        exit(0);
    }
    printf("s1= ");
    StrPrint(s1);
    StrCopy(s2, s1);
    printf("s2= ");
    StrPrint(s2);
    StrAssign(s2, "-------");
    printf("then, s2= ");
    StrPrint(s2);
    String t;
    k = Concat(t, s1, s2);
    if (k)
    {
        printf("concat completed: ");
        StrPrint(t);
    }
    else
    {
        printf("cutted off:");
        StrPrint(t);
    }
    int i = 2, j = 3;
    k = SubString(s2, t, i, j);
    printf("Substring: ");
    StrPrint(s2);
    StrDelete(t, 1, 2);
    StrInsert(t, 1, s2);
    Replace(s2, t, s1);
    StrPrint(s2);
    getchar();
    return OK;
}