#include <stdio.h>

void str_cpy(char *s1,char *s2);

struct student{
	int age;
	char name[10];
}st1;

typedef struct{
	int a;
	char b;
	float c;
}Simple;

struct complex{
	float f;
	int a[20];
	long *lp;
	Simple s;
	Simple sa[10];
	Simple *sp;
}cp1;

int main(){
	int Age=19;
	char Name[10];
	st1.age=Age;
	str_cpy(st1.name,"John");
	printf("student(1) name: %s age: %d\n",st1.name,st1.age);
	
	//struct student StuArr[3];
	Simple sp1;
	struct complex *cpp1;
	cpp1->f=2;
	float a=cpp1->f;
	//cp1.sp->a=1;
	//cp1.sp->b=2;
	//cp1.sp->c=3;
	printf("(cp1) a: %d\n",a);
	//printf("(cp1) a: %d b: %d c: %d\n",cp1.sp->a,cp1.sp->b,cp1.sp->c);
	return 0;
}

void str_cpy(char *s1,char *s2){
	while((*s1++=*s2++)!='\0');
}
