//
// Created by 徐彬斌 on 2022/10/17.
//
//2 假设将循环队列定义为：以域变量rear和length分别指示循环队列中队尾元素的位置和内含元素的个数。
//试给出此循环队列的队满条件，并写出相应的入队列和出队列的算法（出队列的算法中要返回对头元素）。【易】
//循环队列但没有front指针
#include "3-2.h"

Status InitQueue(SqQueue *Q)
{
    Q->base = (ElemType *) malloc(sizeof(ElemType) * MAXSIZE);
    Q->rear = 0;
    Q->length = 0;
    return OK;
}

Status EnQueue(SqQueue *Q, ElemType e)
{
    if (Q->length == MAXSIZE)//因为没有front，所以这是队满的条件
    {
        return ERROR;
    }
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXSIZE;
    Q->length++;
    return OK;
}

Status DeQueue(SqQueue *Q, ElemType *e)
{
    if (Q->length == 0)//判断队列为空
    {
        return ERROR;
    }
    *e = Q->base[(Q->rear + MAXSIZE - Q->length + 1) % MAXSIZE];//带回被删除的元素
    Q->length--;
    return OK;
}

Status PrintQueue(SqQueue Q)
{
    if (Q.length == 0)//判断队列为空
    {
        printf("Queue=[]");
        return ERROR;
    }
    printf("Queue=[");
    for (int i = 0; i < Q.length; i++)
    {
        printf("%d ", Q.base[i]);
    }
    printf("]\n");
}

int main()
{
    SqQueue Q;
    InitQueue(&Q);
    ElemType e;
    printf("下面演示入队操作：\n");
    for (int i = 0; i < MAXSIZE; i++)
    {
        printf("请输入第%d个要入队的元素e：", i + 1);
        scanf("%d", &e);
        EnQueue(&Q, e);
        PrintQueue(Q);
    }
    printf("下面演示入队操作：\n");
    for (int i = 0; i < MAXSIZE; i++)
    {
        DeQueue(&Q, &e);
        PrintQueue(Q);
    }
    return 0;
}
