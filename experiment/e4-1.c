#include "e4-1.h"

Status visitT(TElemType e)
{
	printf("%c",e);
	return OK;
}

Status InitStack(SqStack *S)
{
	(*S).base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!(*S).base)
	{
		return ERROR;
	}
	(*S).top=(*S).base;
	(*S).stacksize=STACK_INIT_SIZE;
	return OK;
}

Status Push(SqStack *S,SElemType e)
{
	if((*S).top-(*S).base>=(*S).stacksize)
	{
		(*S).base=(SElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!(*S).base)
			return ERROR;
		(*S).top=(*S).base+(*S).stacksize;
		(*S).stacksize+=STACKINCREMENT;
	}
	*((*S).top)++=e;
	return OK;
}

Status Pop(SqStack *S,SElemType *e)
{
	if((*S).top==(*S).base)
		return ERROR;;
	*e=*--(*S).top;
	return OK;
}
 
Status StackEmpty(SqStack S)
{
	if(S.top==S.base)
		return TRUE;
	else
		return FALSE;
}

Status InitBiTree(BiTree *T)
{
	*T=NULL;
	return OK;
}

int BiTreeDepth(BiTree T)
{
	int i,j;
	if(!T)
		return 0;
	if(T->lchild)
		i=BiTreeDepth(T->lchild);
	else
		i=0;
	if(T->rchild)
		j=BiTreeDepth(T->rchild);
	else
		j=0;
	return i>j?i+1:j+1;
}
 
Status CreateBiTree(BiTree *T)
{
   TElemType ch;
   scanf("%c",&ch);
   if(ch==END)
   {
   		*T=NULL;
    	return OK;
   }
   else
   {
		*T=(BiTree)malloc(sizeof(BiTNode));
		if(!*T)
			return ERROR;
		(*T)->data=ch;
		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
   }
}

Status BiTreeEmpty(BiTree T)
{
	if(T)
		return FALSE;
	else
		return TRUE;
}

TElemType Root(BiTree T)
{
	if(BiTreeEmpty(T))
		return END;
	else
		return T->data;
}
 
Status recInOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{
	if(T)
	{
		recInOrderTraverse(T->lchild,Visit);
		Visit(T->data);
		recInOrderTraverse(T->rchild,Visit);
	}
	return OK;
}

Status InOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{
	SqStack S;
	InitStack(&S);
	while(T||!StackEmpty(S))
	{
		if(T)
		{
			Push(&S,T);
			T=T->lchild;
		}
		else
		{
			Pop(&S,&T);
			if(!Visit(T->data))
				return ERROR;
			T=T->rchild;
		}
	}
	printf("\n");
	return OK;
}

int main()
{
	int i;
	BiTree T,p,c;
	TElemType e;
	InitBiTree(&T);
	if(InitBiTree(&T))
	{
		printf("��ʼ����ɣ�\n"); 
	}
	printf("������Ԫ���Թ����������");
	if(CreateBiTree(&T))
	{
		printf("�����������ɣ�\n"); 
	}
	e=Root(T);
	if(e!=END)
	{
		printf("�������ĸ�Ϊ: %c\n",e);
	}
	else
	{
		printf("���գ��޸�\n");
	}
	printf("\n����ݹ����������:\n");
	recInOrderTraverse(T,visitT);
	printf("\n����ǵݹ����������:\n");
	InOrderTraverse(T,visitT);
	
	return 0; 
}
