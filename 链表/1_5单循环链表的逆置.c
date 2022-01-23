#include<stdlib.h>
#include<stdio.h>
typedef struct List
{
	int data;
	struct List *next;
}List;

void creatcriList(List *head);//创建循环链表
void printList(List *head);//打印链表
void revserList(List *head);//逆转循环链表
void revserList(List *head)
{
	List *p,*q,*r;
	r=head;
	p=head->next;
	q=p->next;
	while(p!=head)
	{
		p->next=r;
		r=p;
		p=q;
		q=p->next;
	}
	head->next=r;
}
void printList(List *head)
{
	List *p;
	p=head->next;
	while(p!=head)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");

}
void creatcriList(List *head)
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
		r->next=p;
		r=p;
		scanf("%d",&n);

	}
	r->next=head;
}
int main()
{
	List *head;
	head=(List *)malloc(sizeof(List));
	creatcriList(head);
	printList(head);

	revserList(head);
	printList(head);
	return 0;
}


