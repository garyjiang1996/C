#include "stdio.h"
#include "stdlib.h"

#define LEN sizeof(struct student)

struct student
{
	int num;
	int sore;
	struct student *next;	
};

struct student* create()
{
	struct student *head,*p1,*p2;
	p1=p2=(struct student *)malloc(LEN);
	scanf("%d,%d",&p1->num,&p1->sore);
	head=NULL;
	int n;
	while(p1->num)
	{
		n++;
		if(n==1)
			head=p1;
		else
			p2->next=p1;
		p2=p1;
		p1=(struct student *)malloc(LEN);
		scanf("%d,%d",&p1->num,&p1->sore);
	}
	p2->next==NULL;
	return head;
}

int main()
{
	create();
	return 0;
}
