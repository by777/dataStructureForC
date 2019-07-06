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

int main(){
    //char chars[]="ABCD";
    String T = "1233";
    //StrAssign(T,chars);
    printf("%s \n",T);
    printf("%c",T[3]);



    

    getchar();
    return OK;
}