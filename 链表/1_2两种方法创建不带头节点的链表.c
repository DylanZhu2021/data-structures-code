#include<stdio.h>
#include<stdlib.h>
/*
不带头节点创建链表：
1.头插法：必须用双重指针
2.尾插法：可以用双重指针，也可以用但指针。
*/
/*
本代码使用双重指针创建链表!!!!!!!
*/
typedef struct List
{
	int data;
	struct List *next;
}List,*pList;

void creatList(pList *head);
void printList(pList head);


void creatList(pList *head)
{
	pList p,r;
	int n;
	scanf("%d",&n);
	(*head)->next=NULL;
	(*head)->data=n;
	r=(*head);
	while(1)
	{
		
		scanf("%d",&n);
		if(n==0)
		{
			break;
		}
		p=(List *)malloc(sizeof(List));
		//头插法
		/*
		p->data=n;
		p->next=*head;
		*head=p;
		*/
		//尾插法
		p->data=n;
		p->next=NULL;
		r->next=p;
		r=p;

	}

}
void printList(pList head)
{
	List *p;
	p=head;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}

int main()
{
	List *head;
	head=(pList)malloc(sizeof(List));
	creatList(&head);
	printList(head);
	return 0;
}