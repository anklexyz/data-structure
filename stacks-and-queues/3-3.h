//
// Created by 徐彬斌 on 2022/10/17.
//
//#ifndef DATA_STRUCTURE_3_3_H
//#define DATA_STRUCTURE_3_3_H
//
//#endif //DATA_STRUCTURE_3_3_H
#include <stdio.h>
#include <stdlib.h>

#define m 6
//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0//return ERROR，也可以用exit(0)表示ERROR;
#define INFEASIBLE (-1)

typedef int ElemType;
typedef int Status;

typedef struct {
    ElemType *v;
    int top[2];//因为是共享栈，两个栈在一个数组里，所以要两个指针*2
} DlStack;
