//
// Created by 徐彬斌 on 2022/10/5.
//
//3试写一算法，自大至小依次输出顺序读入的三个整数X、Y和Z的值。【易】
//实质是三个数两两比较。另外，实质上不是X，Y，Z在交换，
//而是把X，Y，Z当作三个存储变量的容器，其实是容器里的东西在交换，让交换过程始终保持X>Y>Z的要求。
#include <stdio.h>

void tripleSwapSort(int *x, int *y, int *z)
{
    int temp;
    if (*x < *y)
    {
        temp = *x;
        *x = *y;
        *y = temp;
    }

    if (*y < *z)
    {
        temp = *z;
        *z = *y;
        if (*x > temp)
        {
            *y = temp;
        } else
        {
            *y = *x;
            *x = temp;
        }
    }

}

int main()
{
//    setbuf(stdout,NULL);    MinGW调试需要，不然不能及时输出
    int x, y, z;
    printf("请输入三个数：");

    scanf("%d %d %d", &x, &y, &z);

    tripleSwapSort(&x, &y, &z);

    printf("%d,%d,%d", x, y, z);

    return 0;
}


