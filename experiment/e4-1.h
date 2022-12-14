#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 2

typedef int Status;
typedef int Boolean;
typedef char TElemType;

char END='#';

typedef struct BiTNode
 {
   TElemType data;
   struct BiTNode *lchild,*rchild;
 }BiTNode,*BiTree;
 
typedef BiTree SElemType;

typedef struct SqStack
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;
