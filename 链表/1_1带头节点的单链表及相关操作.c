#include<stdio.h>
#include<stdlib.h>

/*

*/
//�ṹ�嶨��
typedef struct node
{
	int data;
	struct node *next;
}list,*plist;

plist creatlist_headinsert(plist head);//ͷ�巨��������
plist creatlist_tailinsert(plist head);//β�巨��������
void printlist(plist head);//��ӡ����
int searchelement(plist head,int num_search);//��ѯֵΪnum_element��Ԫ�ص�λ��
plist delnode(plist head,int num_del);//ɾ��������ֵΪnum_del�Ľڵ�
plist addnode(plist head,int position,int num_add);//��position��λ�������ֵΪnum_add�Ľڵ�
int getlistlength(plist head);//��������ĳ���

plist creatlist_headinsert(plist head)
{
	plist p;
	int n;

	printf("please input some numbers to create linklist:");

	head->next=NULL;
	scanf("%d",&n);
	while(n!=0)
	{

		p=(plist)malloc(sizeof(list));
		p->data=n;
		p->next=head->next;
		head->next=p;
		scanf("%d",&n);
	}

	return head;
}
plist creatlist_tailinsert(plist head)
{
	plist p,r;
	int n;

	printf("please input some numbers to create linklist:");

	head->next=NULL;
	r=head;
	scanf("%d",&n);
	while(n!=0)
	{
		p=(plist)malloc(sizeof(list));

		p->data=n;
		p->next=NULL;
		r->next=p;
		r=p;

		scanf("%d",&n);
	}


	return head;
}
int searchelement(plist head,int num_search)
{
	plist p;
	int pos=0;
	int  flag=0;

	p=head->next;
	while(p!=NULL)
	{
		pos++;
		if(p->data==num_search)
		{
			flag=1;
			break;
		}
		p=p->next;
	}
	if(flag==0)//flag==0���ʾû�в鵽��Ԫ��
	{
		return 0;
	}
	else
	{
		return pos;
	}
}
plist delnode(plist head,int num_del)
{
	plist p,r;

	int pos=searchelement(head,num_del);

	p=head->next;
	r=head;
 
	if(pos==0)
	{
		return head;
	}
	else
	{
		while(pos!=1)
		{
			p=p->next;
			r=r->next;
			pos--;
		}
		r->next=p->next;
	
		return head;
	}
}
plist addnode(plist head,int position,int num_add)
{
	plist p,temp;
	temp=(plist)malloc(sizeof(list));

	temp->data=num_add;
	p=head->next;

	while(p!=NULL&&position!=1)
	{
		position--;
		p=p->next;
	}
	temp->next=p->next;
	p->next=temp;

	return head;
}

void printlist(plist head)
{
	plist p;
	p=head->next;

	printf("\nyour new linklist is:");
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n\n");
}

int getlistlength(plist head)
{
	int list_leng=0;
	plist p=head;

	p=head->next;
	while(p!=NULL)
	{
		list_leng++;
		p=p->next;
	}

	return list_leng;
}

int main()
{

	int del_num;

	int search_num;
	int pos_search;
	int pos_add;
	int numadd;//Ҫ��ӵ���

	//create a linklist
	plist head=(plist)malloc(sizeof(list));
	//head=creatlist_headinsert(head);
	head=creatlist_tailinsert(head);
	printlist(head);


	//delete a number
	printf("please input a number you want delete:");

	scanf("%d",&del_num);
	head=delnode(head,del_num);
	printlist(head);


	//search a  number,return position
	printf("please input a number you want to search:");
	scanf("%d",&search_num);
	pos_search=searchelement(head,search_num);
	
	if(pos_search==0)
	{
		printf("not find");
	}
	else
	{
		printf("the position is:");
		printf("%d",pos_search);
	}
	printf("\n");

	//get linklist's length

	printf("the length of linklist is:");
	printf("%d",getlistlength(head));
	printf("\n");

    
	//add a node
	printf("please input a position to add:");
	scanf("%d",&pos_add);
	if(pos_add>getlistlength(head))
	{
		printf("your position is bigger than length.");
		printf("\n");

	}
	else
	{
		printf("please input a number you want to add:");
		scanf("%d",&numadd);
		head=addnode(head,pos_add,numadd);
		
		printlist(head);
		printf("\n");
	}


	return 0;
}