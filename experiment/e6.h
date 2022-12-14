//
// Created by 徐彬斌 on 2022/12/12.
//
/* c1.h (程序名) */
#include<string.h>
#include<malloc.h> /* malloc()等 */
#include<limits.h> /* INT_MAX等 */
#include<stdio.h> /* EOF(=^Z或F6),NULL */
#include<stdlib.h> /* atoi() */
#include<math.h> /* floor(),ceil(),abs() */
#include<process.h> /* exit() */
/* 函数结果状态代码 */
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */

#define MAX_NAME 6 /* 顶点字符串的最大长度+1 */
#define MAX_INFO 20 /* 相关信息字符串的最大长度+1 */

typedef int VRType;
typedef char InfoType;
typedef char VertexType[MAX_NAME];

/* c7-1.h 图的数组(邻接矩阵)存储表示 */
#define INFINITY INT_MAX /* 用整型最大值代替∞ */
#define MAX_VERTEX_NUM 20 /* 最大顶点个数 */
typedef enum {
    DG, DN, AG, AN
} GraphKind; /* {有向图,有向网,无向图,无向网} */
typedef struct {
    VRType adj; /* 顶点关系类型。对无权图，用1(是)或0(否)表示相邻否； */
    /* 对带权图，c则为权值类型 */
    InfoType *info; /* 该弧相关信息的指针(可无) */
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct {
    VertexType vexs[MAX_VERTEX_NUM]; /* 顶点向量 */
    AdjMatrix arcs; /* 邻接矩阵 */
    int vexnum, arcnum; /* 图的当前顶点数和弧数 */
    GraphKind kind; /* 图的种类标志 */
} MGraph;

typedef int PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef int ShortPathTable[MAX_VERTEX_NUM];
