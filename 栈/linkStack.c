#include<stdio.h>
#include<stdlib.h>
/*
��ջ��˵���������ô��룩��
1.��ջ�����˳��ջ��˵û��ջ��ָ�룬����һ�������ı���count��
2.��ջ��topָ��ָ��ջ��Ԫ�أ���˳��ջ��topָ��ָ��ջ��Ԫ�ص���һ��λ�á�
3.����ջ�����˳��ջ���ͽ�Լ�ռ䡣

*/
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int status;

typedef struct sNode
{
	int data;
	struct sNode *next;
}sNode,*PsNode;

typedef struct linkStack
{
	PsNode top;//ջ��ָ��
	int count;//ջ�ĳ���
}linkStack,*plinkStack;

status initLinkStack(plinkStack s);//��ʼ��ջ
status pushStack(plinkStack s,int n);//ѹջ
int popStack(plinkStack s);//��ջ
status StackisEmpty(plinkStack s);//�ж�ջ��
int getlength(plinkStack s);//��ȡջ�ĳ���
int gettopEle(plinkStack s);//��ȡջ��Ԫ��

status initLinkStack(plinkStack s)
{
	s->top=(sNode *)malloc(sizeof(sNode));
	if(s->top==NULL)
	{
		return ERROR;
	}
	s->top->next=NULL;
	s->count=0;
	return OK;
}

status pushStack(plinkStack s,int n)
{
	PsNode t;
	t=(PsNode)malloc(sizeof(sNode));
	if(!t)
	{
		return ERROR;
	}
	t->data=n;
	t->next=s->top->next;
	s->top->next=t;
	s->count++;
	return OK;
}

int popStack(plinkStack s)
{
	PsNode p=s->top;
	int n=s->top->next->data;
	s->top=s->top->next;
	free(p);
	s->count--;
	return n;
}

int getlength(plinkStack s)
{
	return s->count;
}

status StackisEmpty(plinkStack s)
{
	if(s->count==0)//��ʾջ�գ���count���ж�
	{
		return TRUE;
	}
	else
	{
		return FALSE;//��ʾ�ǿ�
	}
}

int gettopEle(plinkStack s)
{
	return s->top->next->data;
}
int main()
{

	int i;
	plinkStack s;

	s=(plinkStack)malloc(sizeof(linkStack));
	initLinkStack(s);

	pushStack(s,11);
	pushStack(s,23);
	pushStack(s,31);
	pushStack(s,15);
	pushStack(s,5);
	pushStack(s,67);

	printf("the top elemnt is:\n");
	printf("%d\n",gettopEle(s));

	printf("the length of stack is :\n");
	printf("%d\n",getlength(s));

	printf("the sequence of pop is:\n");
	for(i=0;i<6;i++)
	{
		printf("%d ",popStack(s));
	}
	printf("\n");

	if(StackisEmpty(s)==1)
	{
		printf("the stack is empty!\n");
	}


	return 0;
}
