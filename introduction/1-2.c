//
// Created by 徐彬斌 on 2022/10/4.
//
//2试仿照三元组的抽象数据类型写出抽象数据类型复数的定义及操作（加法、减法、
//乘法、除法、求实部、求虚部、构造函数、析构函数）。【易】

#include <stdio.h>

typedef struct {
    double real;
    double virtual;
} Complex;

//void Assign(Complex *A,double a,double b)
//{
//    A->real=a;
//    A->virtual=b;
//}

void Add(Complex *A, Complex B, Complex C)
{
    A->real = B.real + C.real;
    A->virtual = B.virtual + C.virtual;
}

void Minus(Complex *A, Complex B, Complex C)
{
    A->real = B.real - C.real;
    A->virtual = B.virtual - C.virtual;
}

void Multiply(Complex *A, Complex B, Complex C)
{
    A->real = B.real * C.real;
    A->virtual = B.virtual * C.virtual;
}

void Divide(Complex *A, Complex B, Complex C)
{
    A->real = B.real / C.real;
    A->virtual = B.virtual / C.virtual;
}

void Integrate(Complex *A)
{
    if (A->virtual < 0)
    {
        printf("%.1lf\n", A->real);
    } else
    {
        printf("%.1lf+%.1lfi\n", A->real, A->virtual);
    }
}

int main()
{
    Complex A, B, C;
//    double a, b;
    setbuf(stdout, NULL);
    printf("请输入第一个复数：（如a+bi）\n");
    scanf("%lf+%lfi", &B.real, &B.virtual);
    printf("请输入第二个复数：（如a+bi）\n");
    scanf("%lf+%lfi", &C.real, &C.virtual);
//    Assign(&A,A.real,A.virtual);

    printf("第一个复数为：");
    Integrate(&B);
    printf("第二个复数为：");
    Integrate(&C);

    Add(&A, B, C);
    printf("复数1+复数2=");
    Integrate(&A);

    Minus(&A, B, C);
    printf("复数1-复数2=");
    Integrate(&A);

    Multiply(&A, B, C);
    printf("复数1*复数2=");
    Integrate(&A);

    Divide(&A, B, C);
    printf("复数1/复数2=");
    Integrate(&A);

    return 0;
}


