#include "string.h"

#include "stdio.h"
#include "stdlib.h"
#include "io.h"
#include "ctype.h"

#define MAXSIZE 1000
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef char ElemType;

Status visit(ElemType c){
    printf("%c ",c);
    return OK;
}

typedef struct 
{
    ElemType data;
    int cur;// 游标，为0时无指向
}Component,staticLinkList[MAXSIZE];




int main()
{

    getchar();
    return 0;
}