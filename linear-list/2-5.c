//
// Created by 徐彬斌 on 2022/10/4.
//
//5 设顺序表va中的数据元素递增有序，试写一个算法，将x插入到顺序表的适当位置上，以保持该表的有序性。
#include<stdio.h>

#define OK 1
#define ERROR (-1)
#define MAXSIZE 20
typedef int Status;
typedef int Element;

typedef struct {
    /* data */
    Element elem[MAXSIZE];
    int size;
    int length;
} SqList;

SqList InitElem()//无参构造器的写法，封装，后面我不这样写了
{
    SqList va;
    va.size = MAXSIZE;
    for (int i = 0; i < MAXSIZE - 1; i++)
    {
        va.elem[i] = (i + 1) * 2;
        va.length++;
    }
    return va;
}

Status InsertOrder(SqList *va, Element x)
{
    if (va->length >= va->size)
        return ERROR;
    int i;
    for (i = va->length - 1; (i > 0) && (va->elem[i] > x); i--)//插入从尾部往前遍历
    {
        va->elem[i + 1] = va->elem[i];
    }
    va->elem[++i] = x;
    va->length++;
}

Status PrintList(SqList L)
{
    printf("SqL=[");
    for (int j = 0; j < L.length; j++)
    {
        printf("%d ", L.elem[j]);
    }
    printf("]\n");
    return OK;
}
int main()
{
    SqList va = InitElem();
    PrintList(va);
    Element x;
    printf("请输入要插入的数：");
    scanf("%d", &x);
    InsertOrder(&va, x);
    PrintList(va);
    return 0;
}