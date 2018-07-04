#include "stdio.h"
#include "stdlib.h"

#define N 3
#define M 2
#define len sizeof(struct student)

struct student
{
	int num;
	char name[10];
	int xb;
	int sore[3];
	int ave;
};

void input(struct student st[]);
void out(struct student st[]);
void write(struct student st[]);

int main()
{
	struct student st[M];
	input(st);
	out(st);
	write(st);
	return 0;
}

void input(struct student st[])
{
	int i,j,sum;
	sum=0;
	for(i=0;i<M;i++)
	{
		scanf("%d",&st[i].num);
		scanf("%s",st[i].name);
		scanf("%d",&st[i].xb);
		for(j=0;j<3;j++)
		{
			scanf("%d",&st[i].sore[j]);
			sum+=st[i].sore[j];
		}
		st[i].ave=sum/N;
		sum=0;
	}
}

void out(struct student st[])
{
	int i,j;
	for(i=0;i<M;i++)
	{
		printf("num:%d ",st[i].num);
		printf("name:%s ",st[i].name);
		printf("sex:%d ",st[i].xb);
		printf("ave=%d ",st[i].ave);	
		for(j=0;j<3;j++)
		{
			printf("score:%d ",st[i].sore[j]);
		}
		printf("\n");
	}
	
}

void write(struct student st[]){
	FILE *fp;
	int i;
	fp=fopen("d:\\save.txt","w");
	for(i=0;i<M;i++)
		fwrite(st+i,len,1,fp);
}