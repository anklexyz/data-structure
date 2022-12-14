//
// Created by 徐彬斌 on 2022/10/17.
//
//3 将编号为0和1的两个栈存放于一个数组空间V［m］中，栈底分别处于数组的两端。
//当第0号栈的栈顶指针top［0］等于-1时该栈为空；当第1号栈的栈顶指针top［1］等于m时，该栈为空。m相当于-1
//两个栈均从两端向中间增长。试编写双栈初始化，判断栈空、栈满、进栈和出栈等算法的函数。【中】
//共享栈问题教材p83
#include "3-3.h"

Status InitDlStack(DlStack *S)
{
    S->v = malloc(sizeof(DlStack) * m);
    S->top[0] = -1;
    S->top[1] = m;
    return OK;
}

Status IsEmpty(DlStack S, int i)//i为栈号
{
    switch (i)
    {
        case 0:
            if (S.top[0] == -1)
            {
                return TRUE;
            } else
            {
                return FALSE;
            }
        case 1:
            if (S.top[1] == m)
            {
                return TRUE;
            } else
            {
                return FALSE;
            }
        default:
            return ERROR;//栈号输错
    }
}

Status IsFull(DlStack S)
{
    if (S.top[1] - S.top[0] == 1)//相差1个格子就说明已经邻接，要碰上了
    {
        return TRUE;
    } else
        return FALSE;
}

Status PushDlStack(DlStack *S, ElemType e, int i)
{
    if (IsFull(*S))
    {
        return ERROR;
        //也可以用exit(0)表示ERROR;
    }
    switch (i)
    {
        case 0:
            S->top[0]++;//上下两句位置颠倒会溢出
            S->v[S->top[0]] = e;
            return OK;
        case 1:
            S->top[1]--;
            S->v[S->top[1]] = e;
            return OK;
        default:
            return ERROR;
    }
}

Status PopDlStack(DlStack *S, ElemType *e, int i)
{
    if (i != 0 && i != 1)//这里和入栈不同，没放在default判断是因为，下面要判断栈空，防止传入的栈号错误
    {
        return ERROR;
    }
    if (IsEmpty(*S, i))
    {
        return ERROR;
    }
    switch (i)
    {
        case 0:
            *e = S->v[S->top[0]];
            S->top[0]--;
            return OK;
        case 1:
            *e = S->v[S->top[1]];
            S->top[1]++;
            return OK;
//        default:
//            return ERROR;
    }
}

Status PrintStack(DlStack S, int i)
{
    if (i != 0 && i != 1)//这里和入栈不同，没放在default判断是因为，下面要判断栈空，防止传入的栈号错误
    {
        return ERROR;
    }
    if (IsEmpty(S, i))
    {
        printf("Stack[%d] is Empty!\n", i);
        return ERROR;
    }
    printf("Stack[%d]=[", i);
    switch (i)
    {
        case 0:
            for (int j = 0; j <= S.top[i]; ++j)
            {
                printf("%d ", S.v[j]);
            }
            break;
        case 1:
            for (int j = m - 1; j >= S.top[i]; --j)
            {
                printf("%d ", S.v[j]);
            }
    }
    printf("]\n");
    return OK;
}

int main()
{
    DlStack S;
    ElemType e;
    int i;//栈的序号
    InitDlStack(&S);
    i = 0;
    PrintStack(S, i);
    i = 1;
    PrintStack(S, i);

    printf("下面演示入栈：\n");
    i = 0;
    for (int j = 0; j < m / 2; ++j)
    {
        printf("请输入要入栈[%d]的第%d个元素：", i, j + 1);
        scanf("%d", &e);
        PushDlStack(&S, e, i);
        PrintStack(S, i);
    }
    i = 1;
    for (int j = 0; j < m / 2; ++j)
    {
        printf("请输入要入栈[%d]的第%d个元素：", i, j + 1);
        scanf("%d", &e);
        PushDlStack(&S, e, i);
        PrintStack(S, i);
    }

    printf("全栈视图：[");
    for (int j = 0; j < m; ++j)
    {
        printf("%d ", S.v[j]);
    }
    printf("]\n");

    printf("下面演示弹栈：\n");
    i = 0;
    PrintStack(S, i);
    for (int j = 0; j < m / 2; ++j)
    {
        PopDlStack(&S, &e, i);
        PrintStack(S, i);
    }
    i = 1;
    PrintStack(S, i);
    for (int j = 0; j < m / 2; ++j)
    {
        PopDlStack(&S, &e, i);
        PrintStack(S, i);
    }

    return 0;
}
