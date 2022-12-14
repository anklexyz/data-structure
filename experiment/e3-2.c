#include "e3-2.h"

Status InitStack(SqStack *S)//��ʼ��ջ
{
    S->top = -1;
    return OK;
}

Status StackEmpty(SqStack S)//�ж�ջ��
{
    if (S.top == -1)
    {
        return TRUE;
    } else
    {
        return FALSE;
    }
}

Status Push(SqStack *S, char e)
{
    if (S->top == MAXSIZE - 1)
    {
        return ERROR;
    }
    S->top++;
    S->data[S->top] = e;
    return OK;
}

Status Pop(SqStack *S, char *e)
{
    if (S->top == -1)
        return ERROR;
    *e = S->data[S->top];
    S->top--;
    return OK;
}

Status IsPalindrome(char *str)
{
    SqStack S;
    InitStack(&S);
    int i;
    int len = strlen(str) - 1;
    for (i = 0; i < len / 2; i++)
    {
        Push(&S, str[i]);
    }//ֻ��һ���ջ������i������ֵ���ַ����ĺ�벿�ֱȽ�
    if (len % 2 == 1) i++;//���������Ҫ����
    while (!StackEmpty(S))
    {
        char e;
        Pop(&S, &e);
        if (e != str[i]) return FALSE;
        else i++;
    }
    return TRUE;
}

int main()
{
    char str[MAXSIZE];
    int i = 0;
    printf("������һ���ԡ�@���������ַ�����");
    scanf("%c", &str[i++]);
    do
    {
        scanf("%c", &str[i]);
    } while (str[i++] != '@');
    if (IsPalindrome(str))
    {
        printf(">���ַ�����%s\b�ǻ��ģ�", str);
    } else
    {
        printf(">���ַ�����%s\b���ǻ��ģ�", str);
    }

    return 0;
}

