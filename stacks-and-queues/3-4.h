//
// Created by 徐彬斌 on 2022/10/17.
//
//#ifndef DATA_STRUCTURE_3_4_H
//#define DATA_STRUCTURE_3_4_H
//
//#endif //DATA_STRUCTURE_3_4_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAXSIZE 6
//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0//return ERROR，也可以用exit(0)表示ERROR;
#define INFEASIBLE (-1)

typedef int QElemType;
typedef int Status;
typedef struct QNode {
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct{
    QueuePtr front,rear;
}LinkQueue;
Status InitQueue(LinkQueue *Q);
Status CreateQueue(LinkQueue *Q, int n);
Status IsEmpty(LinkQueue Q);
Status EnQueue(LinkQueue *Q, QElemType e);
Status DeQueue(LinkQueue *Q, QElemType *e);
Status PrintQueue(LinkQueue Q);


