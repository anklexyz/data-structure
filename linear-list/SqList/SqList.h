//
// Created by 徐彬斌 on 2022/10/6.
//
//#ifndef UNIT1_SQLIST_H
//#define UNIT1_SQLIST_H
//
//#endif //UNIT1_SQLIST_H

#pragma once  //防止头文件被二次引用

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include <stdbool.h>
//#include <conio.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE (-1)
#define OVERFLOW (-2)
#define MAXSIZE 100

typedef int ElemType;//后续要存储其它类型时方便更改
typedef int Status;

//顺序表的动态存储
typedef struct {
    ElemType *elem;
    int size;
    int length;
} SqList;

//初始化顺序表
SqList InitList();

//销毁顺序表
Status DestroyList(SqList *L);

//写入顺序表
void WriteList(SqList *L);

//清空顺序表
void ClearList(SqList *L);

//求顺序表长度
int ListLength(SqList L);

//顺序表是否非空
int IsEmpty(SqList L);

//顺序表按位置取值
Status GetElem(SqList L);

//顺序表查找
Status LocateElem(SqList L);

//顺序表的插入
Status ListInsert(SqList *L);

//顺序表的删除
Status ListDelete(SqList *L);

//打印顺序表
void PrintList(SqList L);

//顺序表的扩容
void ListExpand(SqList *L);

//确定与否
bool Ready();