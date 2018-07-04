#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
//17/12/2017 16:36
struct Node{
	char name[10];
	int score;	
	struct Node *next;
};

typedef struct Node ListNode;
//declare:
ListNode *CreateList(int n);
void InsertList(ListNode *h,int i,char name[],int score,int n);
void DeleteList(ListNode *h,int i,int n);
void OutputList(ListNode *h);
//
int main(){
	ListNode *head;
	int i,score,pick,n;	//position,score,judgement,units of the list
	char name[10];
	
	pick=1;
	while(pick){
		printf("1.Create New List.\n");
		printf("2.Add New Unit.\n");
		printf("3.Delete Unit.\n");
		printf("4.Print Out.\n");
		printf("0.exit\n");
		
		scanf("%d",&pick);
		switch(pick) {
			case 1:
				printf("set list units = ");
				scanf("%d",&n);
				head=CreateList(n);
				//printf("sizeof h:%d\n",sizeof(h));
				break;
			case 2:
				printf("which position?");
				scanf("%d",&i);
				printf("what name?");
				scanf("%s",name);
				printf("What score?");
				scanf("%d",&score);
				InsertList(head,i,name,score,n);
				printf("Inserted:\n");
				OutputList(head);
				break;
			case 3:
				printf("which position?");
				scanf("%d",&i);
				DeleteList(head,i,n);
				break;
			case 4:
				printf("List output:\n");
				OutputList(head);
				break;
			case 0:break;
			default:printf("Invalid Option!\n");break;
		}
	}
	return 0;
}

ListNode *CreateList(int n){
	ListNode *head,*p,*pre;
	head=(ListNode *)malloc(sizeof(ListNode));
	//head->next=NULL;
	pre=head;
	int i;
	for(i=1;i<=n;i++){
		p=(ListNode *)malloc(sizeof(ListNode)); //new node
		printf("stu(%d)'s name: ",i);
		scanf("%s",&p->name);
		printf("stu(%d)'s score: ",i);
		scanf("%d",&p->score);
		pre->next=p; //pre aim to next node p
		pre=p;
	}
	p->next=NULL;
	return head;
}

void InsertList(ListNode *h,int i,char name[],int score,int n){
	ListNode *q,*p;
	int j;
	if(i<1||i>n+i)
		printf("-i-Range Error!\n");
	else{
		j=0;
		p=h;
		while(j<i-1){
			p=p->next;
			j++;
		}
		q=(ListNode *)malloc(sizeof(ListNode));
		strcpy(q->name,name);
		q->score=score;
		//
		q->next=p->next;
		p->next=q;
	}
}

void DeleteList(ListNode *h,int i,int n){
	ListNode *p,*q;
	int j,score;
	char name[10];
	if(i<1||i>n)
		printf("-i-Range Error!");
	else{
		j=0;
		p=h;
		while(j<i-1){
			p=p->next;
			j++;
		}
		q=p->next; //point index:i
		p->next=q->next;
		//output:
		strcpy(name,q->name);
		score=q->score;
		free(q);
		printf("stu(?) name=%s,score=%d has been deleted\n",name,score);
	}
}

void OutputList(ListNode *h){
	ListNode *p;
	p=h->next;	
	
	int i=1;
	while(p){
		printf("student(%d): name %s score %d\n",i++,p->name,p->score);
		p=p->next;
	}
}
