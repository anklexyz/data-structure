//
// Created by 徐彬斌 on 2022/10/22.
//
//#ifndef DATA_STRUCTURE_3_5_H
//#define DATA_STRUCTURE_3_5_H
//
//#endif //DATA_STRUCTURE_3_5_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 10
//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0//return ERROR，也可以用exit(0)表示ERROR;
#define INFEASIBLE (-1)

typedef int QElemType;
typedef int Status;
typedef struct {
    QElemType data[MAXSIZE];
    int front;//队头指针
    int rear;//队尾指针
} SqQueue;

Status InitQueue(SqQueue *S);
Status IsFull(SqQueue S);
Status IsEmpty(SqQueue S);
Status EnQueue(SqQueue *S, QElemType e);
Status DeQueue(SqQueue *S, int *e);
Status PrintQueue(SqQueue S);
