#include<stdio.h>
#include<stdlib.h>

typedef struct List
{
	int data;
	struct List *next;
}List;

void creatList(List *head);//创建单链表
void linkListend(List *ha,List *hb);//在尾部合并链表
void linkorderList(List *ha,List *hb,List *hc);//合并链表，让其有序
void linkorderList(List *ha,List *hb,List *hc)
{
	List *p,*q;
	List *r;
	
	hc->next=NULL;
	p=ha->next;
	q=hb->next;
	r=hc;

	while(p!=NULL&&q!=NULL)
	{
		if(p->data<=q->data)
		{
			r->next=p;
			p=p->next;
			r=r->next;
		}
		else
		{
			r->next=q;
			q=q->next;
			r=r->next;
		}
	}
	if(p!=NULL)
	{
		r->next=p;
	}
	else
	{
		r->next=q;
	}

	while(hc->next!=NULL)
	{
		printf("%d ",hc->next->data);
		hc=hc->next;
	}
}


void linkListend(List *ha,List *hb)//在链尾合并链表！
{
	/*//a在b前面！
	List *p;

	p=ha;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=hb->next;

	while(ha->next!=NULL)
	{
		printf("%d ",ha->next->data);
		ha=ha->next;
	}*/
	//a在b后面！
	List *p;

	p=hb;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=ha->next;

	while(hb->next!=NULL)
	{
		printf("%d ",hb->next->data);
		hb=hb->next;
	}
}
void creatList(List *head)
{
	int n;
	List *p,*r;

	head->next=NULL;
	r=head;
	scanf("%d",&n);
	while(n!=0)
	{
		p=(List *)malloc(sizeof(List));
		p->next=NULL;
		p->data=n;
		r->next=p;
		r=p;
		scanf("%d",&n);
	}

	while(head->next!=NULL)
	{
		printf("%d ",head->next->data);
		head=head->next;
	}
}


int main()
{
	List *ha,*hb;
	List *hc;

	hc=(List *)malloc(sizeof(List));
	ha=(List *)malloc(sizeof(List));
	hb=(List *)malloc(sizeof(List));

	creatList(ha);
	printf("\n");
	creatList(hb);
	printf("\n");
	//linkListend(ha,hb);
	linkorderList(ha,hb,hc);
}