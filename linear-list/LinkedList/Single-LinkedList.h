//
// Created by 徐彬斌 on 2022/10/16.
//
//#ifndef DATA_STRUCTURE_SINGLE_LINKEDLIST_H
//#define DATA_STRUCTURE_SINGLE_LINKEDLIST_H
//
//#endif //DATA_STRUCTURE_SINGLE_LINKEDLIST_H

#pragma once  //防止头文件被二次引用

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include <stdbool.h>
//#include <conio.h>

//#define TRUE 1
//#define FALSE 0
//#define OK 1
//#define ERROR 0
//#define INFEASIBLE (-1)
//#define OVERFLOW (-2)
//#define MAXSIZE 100
//
//typedef int ElemType;//后续要存储其它类型时方便更改
//typedef int Status;

//typedef struct LNode {
//    ElemType data;
//    struct LNode *next;
//} LNode, *LinkList;

#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "stdlib.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */

typedef struct Node
{
    ElemType data;
    struct Node *next;
}Node;
typedef struct Node *LinkList; /* 定义LinkList */

