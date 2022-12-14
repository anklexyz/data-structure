//
// Created by 徐彬斌 on 2022/10/17.
//
//4 假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾元素结点（注意：不设头指针），
//试编写相应的置空队列、判断队列是否为空、入队和出队等算法。【中】
#include  "3-4.h"

int main()
{

    LinkQueue Q;
    InitQueue(&Q);
//    PrintQueue(Q);
    int n;
    printf("请输入要初始化的长度：");
    scanf("%d", &n);
    CreateQueue(&Q, n);
    printf("IsEmpty=%d\n", IsEmpty(Q));
    PrintQueue(Q);
    QElemType e;
    printf("请输入要入队元素e：");
    scanf("%d", &e);
    EnQueue(&Q, e);
    PrintQueue(Q);
    printf("下面演示出队：\n");
    while (DeQueue(&Q, &e))
    {
        PrintQueue(Q);
    }
    printf("IsEmpty=%d\n", IsEmpty(Q));
    return 0;
}

Status InitQueue(LinkQueue *Q)
{
    Q->front = Q->rear = (QueuePtr) malloc(sizeof(QNode));
    if (Q == NULL)
    {
        return ERROR;
    }
    Q->front->next = NULL;
    printf("Initiate finished!\n");
    return OK;
}

Status CreateQueue(LinkQueue *Q, int n)
{
    srand(time(0));
    QueuePtr s;
    for (int i = 0; i < n; i++)
    {
        s = (QueuePtr) malloc(sizeof(QNode));
        s->data = rand() % 100 + 1;
        Q->rear->next = s;//连到上一个结点的末尾，这两步可以互换
        s->next = Q->front;//接成循环链表
        Q->rear = s;//尾指针后移
    }
    QueuePtr p;
    p = Q->front;
    Q->front = Q->front->next;
    free(p);//释放头结点
    Q->rear->next = Q->front;
    return OK;
}

Status IsEmpty(LinkQueue Q)
{
    if (Q.front == Q.rear)
    {
        return TRUE;
    } else
    {
        return FALSE;
    }
}

Status EnQueue(LinkQueue *Q, QElemType e)
{
    QueuePtr s;
    s = (QueuePtr) malloc(sizeof(QNode));
    s->data = e;
    Q->rear->next = s;//连到上一个结点的末尾，这两步可以互换
    s->next = Q->front;//接成循环链表
    Q->rear = s;//尾指针后移
    return OK;
}

Status DeQueue(LinkQueue *Q, QElemType *e)
{
    if (IsEmpty(*Q))
    {
        return ERROR;
    }
    QueuePtr p;
    *e = Q->front->data;
    p = Q->front;
    Q->front = Q->front->next;//头指针后移
    Q->rear->next = Q->front;//尾结点重新连到新的首元结点
    free(p);
    return OK;
}

Status PrintQueue(LinkQueue Q)
{
    QueuePtr p = Q.front;
    printf("LQ=[");
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != Q.front);//等价Q.rear->next
    printf("]\n");
    return OK;
}
