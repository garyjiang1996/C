#include <stdio.h>

int main(){
	int i=1;
	const int *p=&i; //i可以变，p可以变，*p不能变
	//const int *p等价于int const *p
	//p is a pointer to a constant int
	//p can be changed to point to another constant integet 
	//at run time,const is before *, hence the value pointed 
	//is constant
	//int *const p 表示指针p不能被修改
	//p is a constant pointer to int, once initialized
	//p can't be changed at run-time, 
	//notice that constant is after *, hence the pointer is constant
	//waring:
	*p=2; 
	i++; 
	++*p; 
	//:end warning
	printf("p:%d\n",*p);
	printf("i:%d\n",i);
	
	printf("addr p:%p\n",p);
	printf("addr i:%p\n",&i);
	
	//void f(const int *x) 当要传递的参数类型比地址大的时候
	//int sum(const int a[]) 保护数组不被破坏
	int a[3]={1,2,3};
	int *const p,i=-1,len;
	
	p=a;
	len=sizeof(a)/sizeof(int *);
	
		while(++i<len){
		printf("a[%d]=%d\n",i,a[i]);
		printf("p[%d]=%d\n",i,*(p+i));
	}
	//modify a[0],p[0]
	*p=a[0]=10;
	printf("a[0]=%d\n",a[0]);
	printf("p[0]=%d\n",*p);
	return 0;
}