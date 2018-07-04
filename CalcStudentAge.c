#include <stdio.h>
#include <string.h>
struct student
{
	int num;
	char name[6];
	int birth;
	int age;
};

void build_student(struct student *s){
	s->num=1;
	strcpy(s->name,"li");
	s->birth=1996;
	s->age=21;
}

int main()
{
 	struct student st[2];
	memset(st,0,sizeof(st));
 	int year,i;
 	scanf("%d",&year);
	
 	for(i=0;i<2;i++){
		build_student(&st[i]);
 		st[i].age=year-st[i].birth;
 		if(st[i].age>20){
 			printf("num:%d name:%s birth:%d age:%d\n",st[i].num,st[i].name,st[i].birth,st[i].age);
		}
	}
	return 0;
}
