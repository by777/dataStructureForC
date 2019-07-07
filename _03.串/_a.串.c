/*
 * @Author: Xu Bai
 * @Date: 2019-07-06 22:20:08
 * @LastEditors: Xu Bai
 * @LastEditTime: 2019-07-07 23:21:21
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

        /*
        原代码：
        for (i = 1; i <= MAXSIZE - S1[0]; i++)
        但i上界存疑
        在if条件中已经判断不会越界，应该放心复制
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

Status SubString(String Sub, String S, int pos, int len)
{
    // 用Sub返回串S的从第pos起长度为len的字串
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
    // 返回子串T在主串S中第pos个字符之后的位置。若不存在，则返回0
    //其中，T非空，1≤pos≤StrLength(S)
    int i = pos;
    // i用来主串S中当前位置的下标值，若pos不为1则从pos位置开始匹配
    int j = 1;
    // j用来子串T中当前位置下标值
    while (i <= S[0] && j <= T[0])
    {
        if (S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            //指针后退重新开始匹配
            i = i - j + 2; // i退回上次匹配首位下一位
            j = 1;         //j退回子串T的首位
        }
    }
    if (j > T[0])
    {
        //找到了匹配位置
        return i - T[0];
    }
    else
    {
        return 0;
    }
}

int index2(String S, String T, int pos)
{
    // T为非空串。若主串S中存在第pos个字符之后存在与T相等的子串
    // 则返回第一个这样的子串在S中的位置，否则返回0
    int n, m, i;
    String sub;
    if (pos > 0)
    {
        n = StrLength(S); //主串
        m = StrLength(T); //子串
        i = pos;
        while (i <= n - m + 1)
        {
            SubString(sub, S, i, m);
            //取子串中第i个位置长度与T相等的子串给sub
            if (StrCompare(sub, T) != 0)
            {
                ++i;
            }
            else
            {
                // 两串相等
                return i;
            }
        }
    }
    return 0;
}



// Status Replace(String S,String T, String V){
//     // 用V替换主串S中出现的所有与T相等的不重叠的子串
//     int i =1;
//     if(StrEmpty(T)){
//         return ERROR;
//     }

//     do{
//         i=
//     }
// }

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