//
// Created by 徐彬斌 on 2022/10/18.
//
//1、编号为1，2… n的n个人按顺时针方向围坐一圈，每人持有一个密码（正整数）。
//一开始任选一个正整数作为报数的上限值m，从第一个人开始按顺时针方向自1开始顺序报数，
//报到m时停止报数，报m的人出列，将他的密码作为新的m值，从他的顺时针方向上的下一个开始重新从1报数，
//如此下去，直至所有人全部出列为止，设计一个程序求出出列顺序。（本题要求用循环链表实现）
#include "e2-1.h"

int main()
{
    LNode L;
    int m, n;
    printf("请输入这个圈的总人数n=");
    scanf("%d", &n);
    printf("请输入报数的上限值m=");
    scanf("%d", &m);
    InitList(n, &L);
    Joseph(m, n, &L);

    return 0;
}

Status InitList(int n, LinkList L)
{
    LNode *p, *q;
    q = L;
    printf("请输入%d个人的密码：", n);
    for (int i = 0; i < n; ++i)
    {
        p = (LinkList) malloc(sizeof(LNode));
        p->num = i + 1;
        scanf("%d", &p->key);
        q->next = p;//把新申请的空间连到队尾
        q = p;//q指针往后移动
    }
    L = L->next;//头结点不要了
    q->next = L;//尾部连接头部
    PrintList(n, L);
    return OK;
}

Status PrintList(int n, LinkList L)
{
    LNode *p;
    p = L;
    printf("**num=[");
    do
    {
        printf("%d ", p->num);
        p = p->next;
    } while (p != L);
    printf("]\n");

    p = L;
    printf("**key=[");
    do
    {
        printf("%d ", p->key);
        p = p->next;
    } while (p != L);
    printf("]\n");
    return OK;
}

Status Joseph(int m, int n, LinkList L)
{
    if (L == NULL)
    {
        return ERROR;
    }

    LNode *p, *q;
    p = L;
    printf("出列顺序：");
    while (n)
    {
        for (int i = 1; i < m; i++)
        {
            p = p->next;//指针往下遍历
        }
        printf("%d ", p->next->num);
        m = p->next->key;//更新队列的密码
        q = p->next;//临时存放被淘汰的结点
        p->next = p->next->next;//淘汰出队
        free(q);//释放结点
        n--;//队列人数减一
    }
    return OK;
}