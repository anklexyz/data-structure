//
// Created by 徐彬斌 on 2022/10/15.
//
//1、编号为1，2… n的n个人按顺时针方向围坐一圈，每人持有一个密码（正整数）。
//一开始任选一个正整数作为报数的上限值m，从第一个人开始按顺时针方向自1开始顺序报数，
//报到m时停止报数，报m的人出列，将他的密码作为新的m值，从他的顺时针方向上的下一个开始重新从1报数，
//如此下去，直至所有人全部出列为止，设计一个程序求出出列顺序。
#include "e1-1.h"

int main()
{
    SqList L;
    int m, n;
    printf("请输入这个圈的总人数n=");
    scanf("%d", &n);
    printf("请输入报数的上限值m=");
    scanf("%d", &m);
    InitList(&L, n);
    Joseph(&L, m, n);
    return 0;
}

void InitList(SqList *L, int n)
{
    L->length = 0;
    printf("请输入%d个密码：", n);
    for (int i = 0; i < n; i++)
    {
        L->num[i] = i + 1;
        scanf("%d", &L->key[i]);
        L->length++;
    }
//测试用
//    printf("\n编号num=[ ");
//    for (int k = 0; k < n; k++)
//    {
//        printf("%d ", L->num[k]);
//    }
//    printf("]");
//    printf("\n密码key=[ ");
//    for (int k = 0; k < n; k++)
//    {
//        printf("%d ", L->key[k]);
//    }
//    printf("]\n");
}

void Joseph(SqList *L, int m, int n)
{
    int new_m = m, count = 1, num = n;//new_m是每次的新密码，count是报数个数，num是圈内剩余人数
//    int *p=L->num;也可以使用指针当下标遍历
    printf("出列顺序：");
    for (int i = 0; num > 0; i++)
    {
        if ((count == new_m) && (L->num[i] != 0))
        {
            count = 0;
            new_m = L->key[i];
            printf("%d ", L->num[i]);
            L->num[i] = 0;
            num--;
        }

        if (i > L->length - 1)
        {
            if (L->num[0] != 0)//已经被淘汰了的不再参与计数，所以要限定条件，要确定下一个位置是不是已经淘汰
            {
                count++;//报数+1
            }
        } else if (L->num[i + 1] != 0)//要确定下一个位置是不是已经淘汰，分成i+1和0的情况，因为数组到头了要重新回到开头
        {
            count++;//报数+1
        }

        if (i > L->length - 1)//让数组变成一个循环数组，也就是一个“圈"
        {
            i = -1;//因为循环结束还会加，所以为-1
        }
    }
}


