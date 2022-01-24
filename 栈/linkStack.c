#include<stdio.h>
#include<stdlib.h>
/*
链栈的说明（针对与该代码）：
1.链栈相对与顺序栈来说没有栈底指针，多了一个计数的变量count。
2.链栈的top指针指向栈顶元素，而顺序栈的top指针指向栈顶元素的上一个位置。
3.用链栈相对于顺序栈能耐节约空间。

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
	PsNode top;//栈顶指针
	int count;//栈的长度
}linkStack,*plinkStack;

status initLinkStack(plinkStack s);//初始化栈
status pushStack(plinkStack s,int n);//压栈
int popStack(plinkStack s);//出栈
status StackisEmpty(plinkStack s);//判断栈空
int getlength(plinkStack s);//获取栈的长度
int gettopEle(plinkStack s);//获取栈顶元素

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
	if(s->count==0)//表示栈空，用count来判断
	{
		return TRUE;
	}
	else
	{
		return FALSE;//表示非空
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
