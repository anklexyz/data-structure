//
// Created by 徐彬斌 on 2022/10/6.
//
#include "SqList.h"

int main()
{
    SqList L = InitList();
    printf("ListLength=%d\n", ListLength(L));
    printf("IsEmpty=%d\n", IsEmpty(L));
    WriteList(&L);
    PrintList(L);
    GetElem(L);
    LocateElem(L);
    ListInsert(&L);
    PrintList(L);
    printf("ListLength=%d\n", ListLength(L));
    printf("IsEmpty=%d\n", IsEmpty(L));
    ListDelete(&L);
    PrintList(L);
    printf("ListLength=%d\n", ListLength(L));
    printf("IsEmpty=%d\n", IsEmpty(L));
    ClearList(&L);
    printf("ListLength=%d\n", ListLength(L));
    printf("IsEmpty=%d\n", IsEmpty(L));
    DestroyList(&L);
//    system("pause");
    return 0;
}

//初始化顺序表
//初始化操作，建立一个空的线性表L
SqList InitList()
{
    SqList L;
    L.elem = (ElemType *) malloc(sizeof(ElemType) * MAXSIZE);
    if (!L.elem)
    {
        printf("顺序表初始化失败！\n");
        exit(OVERFLOW);
    }
    L.length = 0;
    L.size = MAXSIZE;
    printf("顺序表已初始化！\n");
    return L;
}

//写入顺序表
//给这个空的线性表初始化添加元素,把元素放入顺序表
void WriteList(SqList *L)
{
    for (int i = 1; i <= L->size - 10; i++)
    {
        L->elem[i - 1] = i;
        L->length++;
    }
}

//销毁顺序表
//销毁已存在的线性表L
Status DestroyList(SqList *L)
{
    if (L->elem)
    {
        free(L->elem);
        printf("顺序表销毁成功！\n");
        return OK;
    } else
    {
        printf("顺序表销毁失败！\n");
        return ERROR;
    }
}

//清空顺序表
//将线性表L清空，长度length重置为0
void ClearList(SqList *L)
{
    L->length = 0;
    printf("成功清空线性表！\n");
}

//顺序表的长度
//返回线性表L的元素个数
int ListLength(SqList L)
{
    return (L.length);
}

//顺序表是否为空
//若线性表L为空，返回TRUE，否则返回FALSE
int IsEmpty(SqList L)
{
    if (L.length == 0) return TRUE;
    else return FALSE;
}

//顺序表的取值
//根据位置i获取线性表L相应位置数据元素的内容
Status GetElem(SqList L)
{
    int i;
    ElemType e;
    printf("请输入您想要获取的位置：");
    scanf("%d", &i);
    if (i < 1 || i > L.length)
    {
        printf("取值失败！\n");
        return ERROR;
    }
    e = L.elem[i - 1];

    printf("该位置上的元素GetElem=%d\n", e);

    return OK;
}

//顺序表的查找
//在线性表L中查找与指定值e相同的数据元素的位置，若成功返回该元素在表中的序号，否则返回0
Status LocateElem(SqList L)
{
    ElemType e;
    printf("请输入您要搜索的元素：");
    scanf("%d", &e);
    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
        {
            printf("指定元素%d在第%d个位置。\n", e, i + 1);
            return OK;
        }
    }
    printf("未找到该元素！\n");
    return ERROR;
}

//顺序表的插入
//在线性表L中第i个位置插入新元素e
Status ListInsert(SqList *L)
{
    int i;
    ElemType e;
    bool sign = true;


    while (sign)
    {
        sign = true;
        printf("请输入要插入的位置和元素：");
        scanf("%d %d", &i, &e);
        if (i < 1 || i > L->length + 1)
        {
            printf("插入元素失败！\n");
            return ERROR;
        }
        if (L->length == MAXSIZE)
        {
            printf("插入元素失败！准备扩容！\n");
            ListExpand(L);
            return ERROR;
        }

        for (int j = L->length - 1; j >= i - 1; j--)
        {
            L->elem[j + 1] = L->elem[j];
        }

        L->elem[i - 1] = e;
        L->length++;
        printf("插入元素成功！\n");
        printf("是否继续插入？(Y|N)");
        sign = Ready();
    }

    return OK;
}

//顺序表的删除
//删除线性表L中第i个位置的元素
Status ListDelete(SqList *L)
{
    int i;
    printf("请输入想要删除元素的位置：");
    scanf("%d", &i);
    if (i < 1 || i > L->length)
    {
        printf("删除元素失败！\n");
        return ERROR;
    }

//    *e = L->elem[i];

    for (int j = i; j <= L->length - 1; j++)
    {
        L->elem[j - 1] = L->elem[j];
    }
    L->length--;
    printf("删除元素成功！\n");
    return OK;
}

//打印顺序表
//依次打印线性表中的元素，如果顺序表为空则输出提示
void PrintList(SqList L)
{
    if (IsEmpty(L))
    {
        printf("顺序表为空！\n");
        return;
    }

    printf("顺序表打印：[");
    for (int i = 0; i < L.length; i++)
    {
        printf("%d  ", L.elem[i]);
    }
    printf("]\n");
}

//顺序表扩容
//如果顺序表满了，就利用realloc()函数扩容成原来的两倍
void ListExpand(SqList *L)
{
    assert(L != NULL);
    if (L->length == L->size)
    {
        L->elem = (int *) realloc(L->elem, L->size * 2 * sizeof(ElemType));
    }
    assert(L->elem != NULL);
    L->size *= 2;
    printf("扩容成功！\n");
}

bool Ready()
{
    char ch;
    bool sign = true;
    while (true)
    {
        getchar();//Linux下没有conio.h头文件，因此会有bug，加了这行就没有了
        ch = getchar();
        if (ch == 'Y' || ch == 'y')
        {
            return sign;
        } else if (ch == 'N' || ch == 'n')
        {
            sign = false;
            return sign;
        } else
        {
            printf("请重新输入！(Y|N)");
        }
    }
}