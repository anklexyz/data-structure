#include "e3-2.h"

Status InitStack(SqStack *S)//初始化栈
{
    S->top = -1;
    return OK;
}

Status StackEmpty(SqStack S)//判断栈空
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
    }//只进一半的栈，利用i的索引值和字符串的后半部分比较
    if (len % 2 == 1) i++;//奇数情况需要跳过
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
    printf("请输入一串以”@“结束的字符串：");
    scanf("%c", &str[i++]);
    do
    {
        scanf("%c", &str[i]);
    } while (str[i++] != '@');
    if (IsPalindrome(str))
    {
        printf(">该字符序列%s\b是回文！", str);
    } else
    {
        printf(">该字符序列%s\b不是回文！", str);
    }

    return 0;
}

