//
// Created by 徐彬斌 on 2022/10/15.
//
//#ifndef DATA_STRUCTURE_E1_1_H
//#define DATA_STRUCTURE_E1_1_H
//
//#endif //DATA_STRUCTURE_E1_1_H
#include <stdio.h>
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE (-1)

typedef int ElemType;
typedef int Status;
typedef struct {
    int num[MAXSIZE];
    int key[MAXSIZE];
    int length;
} SqList;

void InitList(SqList *L, int n);

void Joseph(SqList *L, int m, int n);

