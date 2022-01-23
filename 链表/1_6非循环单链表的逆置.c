#include<stdlib.h>
#include<stdio.h>
typedef struct List
{
	int data;
	struct List *next;
}List;

void creatList(List *head);
void printList(List *head);
void revserList(List *head);
void revserList(List *head)//Äæ×ªÁ´±í£¡
{
	List *p,*q;

	p=head->next;
	head->next=NULL;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		q->next=head->next;
		head->next=q;
	}
}
void printList(List *head)
{
	List *p;
	p=head->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void creatList(List *head)
{
	List *p,*r;
	int n;

	head->next=NULL;
	r=head;
	scanf("%d",&n);
	while(n!=0)
	{
		p=(List *)malloc(sizeof(List));
		p->data=n;
		p->next=r->next;
		r->next=p;
		r=p;
		scanf("%d",&n);
	}
}
int main()
{
	List *head;
	head=(List *)malloc(sizeof(List));
	creatList(head);
	printList(head);

	revserList(head);
	printList(head);
	return 0;
}