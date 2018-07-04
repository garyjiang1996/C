#include <stdio.h>

int add(int x, int y) {
    return x + y;
}

int substract(int x, int y) {
    return x - y;
}

int two_num_op(int (*pf)(int,int),int x,int y) {
	return (*pf)(x,y);
}

int main() {
	int (*pfadd1)()=add;	//add作为函数名，返回这个函数的地址，它被隐式的转换为一个函数指针
	int (*pfadd2)()=*add;	//在返回在这个地址的函数,和函数名一样之后被隐式的转换为一个函数指针
	int (*pfadd3)()=&add;	//直接返回这个函数的地址，之后又得到一个函数指针
	printf("%d %d %d\n",(*pfadd1)(1,2),(*pfadd2)(1,2),(*pfadd3)(1,2));	//output pfadd1~3
	
	int a,b;
	a=3; b=4;
	printf("two_num_op(%d,%d)=%d\n",a,b,two_num_op(add,a,b));
	printf("two_num_op(%d,%d)=%d\n",a,b,two_num_op(substract,a,b));
}


