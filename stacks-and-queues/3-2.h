//
// Created by 徐彬斌 on 2022/10/17.
//
//#ifndef DATA_STRUCTURE_2_2_H
//#define DATA_STRUCTURE_2_2_H
//
//#endif //DATA_STRUCTURE_2_2_H

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 7
//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE (-1)

typedef int ElemType;
typedef int Status;
typedef struct SqQueue {
    ElemType *base;
    int rear;
    int length;
} SqQueue;