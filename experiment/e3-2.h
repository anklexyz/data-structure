#define TRUE 1
#define OK 1
#define FALSE 0
#define ERROR 0
#define MAXSIZE 10
typedef int Status;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char data[MAXSIZE];
    int top;
}SqStack;
