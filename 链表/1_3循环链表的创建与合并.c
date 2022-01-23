#include<stdio.h>
#include<stdlib.h>

typedef struct List
{
	int data;
	struct List *next;
}List;

List* creatList(List *head);
void printfList(List *head);
List* connectList(List *ha,List *hb);
List* connectList(List *ha,List *hb)
{
	List *p,*q;
	p=ha->next;
	q=hb->next;

	while(p->next!=ha)
	{
		p=p->next;
	}
	while(q->next!=hb)
	{
		q=q->next;
	}

	p->next=hb->next;
	q->next=ha;

	return ha;
}
void printfList(List *head)
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

List* creatList(List *head)
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
	return head;
}
int main()
{
	List *ha,*hb;

	ha=(List *)malloc(sizeof(List));
	hb=(List *)malloc(sizeof(List));

	ha=creatList(ha);
	printfList(ha);

	hb=creatList(hb);
	printfList(hb);

	ha=connectList(ha,hb);
	printfList(ha);
	return 0;
}