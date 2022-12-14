//
// Created by 徐彬斌 on 2022/10/31.
//

//#ifndef DATA_STRUCTURE_1_6_H
//#define DATA_STRUCTURE_1_6_H
//
//#endif //DATA_STRUCTURE_1_6_H
//#include <stdio.h>
//#include <stdlib.h>
//#define OK 1
//#define ERROR (-1)
//#define MAXSIZE 20
//typedef int Status;
//typedef int ElemType;

//typedef struct LNode {
//    ElemType data;
//    struct LNode *next;
//} LNode, *LinkList;
#include<stdio.h>
#include<malloc.h>
typedef  struct LNode {
    int data;
    struct LNode * next;  //下一个节点地址
}LNode,*LinkList;
