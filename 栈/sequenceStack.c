#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define Stack_ini_Size 100
#define StackIncerment 10
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int status;

typedef struct stack
{
	int *base;
	int *top;
	int StackSize;
}sqStack,*PsqStack;


status InitStack(sqStack *s);//��ʼ��ջ
status pushStack(sqStack *s,int n);//ѹջ
status StackisEmpty(sqStack *s);//�ж�ջ��
int popStack(sqStack *s);//��ջ
int getlength(sqStack *s);//��ȡջ�ĳ���
int gettopELe(sqStack *s);//��ȡջ��Ԫ��

status InitStack(sqStack *s)
{
	s->base = (int *)malloc( Stack_ini_Size * sizeof(int));
	if(!(*s).base)
	{
		return ERROR;
	}
    (*s).top=(*s).base;
	(*s).StackSize=Stack_ini_Size;
	return OK;
}

int StackisEmpty(sqStack *s)
{
	if(s->base==s->top)
	{
		return TRUE;//��ʾջ��
	}
	else
	{
		return FALSE;//��ʾջ��
	}
}

status pushStack(sqStack *s,int n)
{
	if(s->top-s->base==s->StackSize)
	{
		s->base=(int *)realloc(s->base,StackIncerment * sizeof(int));
		
		if(!s->base)
		{
			return ERROR;
		}
		s->top=s->base+s->StackSize;
		s->StackSize +=StackIncerment;
	}
	*(s->top)=n;
	s->top++;
	return OK;
}

int popStack(sqStack *s)
{
	return *(--s->top);
}

int getlength(sqStack *s)
{
	int count=0;
	int *temp;

	temp=s->base;
	while(temp!=s->top)
	{
		count++;
		temp++;
	}
	return count;
}

int gettopELe(sqStack *s)
{
	int n;
	n=*(s->top-1);
	return n;
}
int main()
{
	int i;
	sqStack s;
	
	InitStack(&s);
	pushStack(&s,2);
	pushStack(&s,5);
	pushStack(&s,8);
	pushStack(&s,11);
	pushStack(&s,7);
	pushStack(&s,31);

	printf("top element is:\n");
	printf("%d\n",gettopELe(&s));
	printf("length of stack is:\n");
	printf("%d\n",getlength(&s));

	printf("sequence of pop is:\n");
	for(i=0;i<6;i++)
	{
		printf("%d ",popStack(&s));
	}
	printf("\n");
	if(StackisEmpty(&s))
	{
		printf("stack is empty!\n");

	}

	
	
	return 0;
}