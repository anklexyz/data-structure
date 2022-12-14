//
// Created by 徐彬斌 on 2022/10/18.
//
//#ifndef DATA_STRUCTURE_E2_1_H
//#define DATA_STRUCTURE_E2_1_H
//
//#endif //DATA_STRUCTURE_E2_1_H
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE (-1)

typedef int ElemType;
typedef int Status;
typedef struct LNode {
    int num;//每个人的编号
    int key;//每个人对应的密钥
    struct LNode *next;
} LNode, *LinkList;

Status InitList(int n, LinkList L);//初始化循环链表
Status Joseph(int m, int n, LNode *L);//实现约瑟夫环的核心算法
Status PrintList(int n, LinkList L);//输出链表内容---测试用