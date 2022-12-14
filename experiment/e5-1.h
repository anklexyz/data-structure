#include<string.h>
#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX_NAME 3
typedef int InfoType;
typedef char VertexType[MAX_NAME];

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
typedef int Status;
typedef int Boolean;

#define MAX_VERTEX_NUM 20
typedef struct ArcNode {
    int adjvex;
    struct ArcNode *nextarc;
    InfoType *info;
} ArcNode;

typedef struct {
    VertexType data;
    ArcNode *firstarc;
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

typedef int QElemType;
typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front, rear;
} LinkQueue;



