#include<stdio.h>
#include<stdlib.h>
/*
����ͷ�ڵ㴴������
1.ͷ�巨��������˫��ָ��
2.β�巨��������˫��ָ�룬Ҳ�����õ�ָ�롣
*/
/*
������ʹ��˫��ָ�봴������!!!!!!!
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
		//ͷ�巨
		/*
		p->data=n;
		p->next=*head;
		*head=p;
		*/
		//β�巨
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