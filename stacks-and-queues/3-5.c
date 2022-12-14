//
// Created by 徐彬斌 on 2022/10/22.
//
//5、如果允许在循环队列的两端都可以进行插入和删除操作。要求：
//①写出循环队列的类型定义；
//②写出“从队尾删除”和“从队头插人”的算法。【难】
#include "3-5.h"

int main()
{
    QElemType e;
    SqQueue S;
    InitQueue(&S);
    PrintQueue(S);// 打印队列
    printf("下面演示入队操作：\n");
    printf("请输入入队元素e：");
    scanf("%d", &e);
    EnQueue(&S, e);// 将数组中的元素入队
    PrintQueue(S);// 打印队列
    printf("下面演示出队操作：\n");
    while (!IsEmpty(S))
    {
        DeQueue(&S, &e);// 将元素1出队
        PrintQueue(S);// 打印队列
    }
    return 0;
}

Status InitQueue(SqQueue *S)
{
    srand(time(0));//伪随机数，普遍性好
    S->front = 0;
    S->rear = 0;
    for (int i = 0; i < MAXSIZE - 2; ++i)//先空两格位置，方便后面演示入队，因为IsFull判定还剩一个空间单元就认为满了所以空两格
    {
        S->data[i] = rand() % 100 + 1;
        S->rear = (S->rear + 1) % MAXSIZE;
    }
    printf("初始化队列成功！");
    return OK;
}

Status IsFull(SqQueue S)
{//这种判定方法要浪费一个内存单元，也就是说还有一个空闲单元的时候就认为是满了！！！要么还有一种方法是在struct里加一个count计数器，不过都要浪费一个单元
    if (S.front == (S.rear + 1) % MAXSIZE)
    {   //rear可能比front大，也可能比front小。队满条件是头尾指针相邻。相差最大一圈，取模%的目的就是为了解决rear与front的大小问题
        return TRUE;
    } else
    {
        return FALSE;
    }
}

Status IsEmpty(SqQueue S)
{
    if (S.front == S.rear)
    {  //头指针等于尾指针，队空
        return TRUE;
    } else
    {
        return FALSE;
    }
}

Status EnQueue(SqQueue *S, QElemType e)
{
    if (IsFull(*S))
    {
        return ERROR;
    }
    S->data[S->rear] = e; //x赋值给头结点的data域
    S->rear = (S->rear + 1) % MAXSIZE;   //尾指针后移
    return OK;
}

Status DeQueue(SqQueue *S, int *e)
{
    if (IsEmpty(*S))
    {
        return ERROR;
    }
    *e = S->data[S->front];  //保留e送回
    S->front = (S->front + 1) % MAXSIZE;  //头指针后移
    return OK;
}

Status PrintQueue(SqQueue S)
{
    if (IsEmpty(S))
    {
        return ERROR;
    }
    printf("SqQueue=[");
    for (int i = S.front; i < S.rear; ++i)
    {
        printf("%d ", S.data[i]);
    }
    printf("]\n");
    return OK;
}