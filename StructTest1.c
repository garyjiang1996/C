#include <stdio.h>

struct point{
	int x;
	int y;
}p1,p2;

struct point get_point1(void);
struct point* get_point2(struct point *p);
void show_point1(struct point p);
void show_point2(struct point *p);

//K&R:p131:"if a large structure is to be passed to a function,
//it is generally more efficient to pass a pointer than to copy
//the whole structure"
//使用->表示指针所指的结构变量中的成员(*p).day <=> p->day

int main(int argc,char *argv[]){
	p1=get_point1(); //得到对象
	//get_point2(&p2); //得到指针
	show_point1(p1);
	//show_point1(*get_point2(&p2));
	show_point2(get_point2(&p2));

	struct point p3,p4,p5;	
	p3=(struct point){3,0}; //数组强制转换
	show_point1(p3);
	p4=p3; //对象赋值
	show_point1(p4);
	*get_point2(&p5)=(struct point){5,0};
	show_point2(&p5);
	return 0;
}
//返回结构体指针
struct point* get_point2(struct point *p){
	printf("enter p.x p.y\n");
	fflush(stdout);
	scanf("%d",&p->x);
	scanf("%d",&p->y);
	return p;
}
//返回结构体对象
struct point get_point1(){
	struct point p;
	printf("enter p.x p.y\n");
	fflush(stdout);
	scanf("%d",&p.x);
	scanf("%d",&p.y);
	return p;
}
void show_point1(struct point p){
	printf("p.x=%d p.y=%d\n",p.x,p.y);
}

void show_point2(struct point *p){
	printf("p.x=%d p.y=%d\n",p->x,p->y);
}