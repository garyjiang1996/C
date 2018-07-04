#include <stdio.h>

void Swap(int *x,int *y){
	int t;
	t=*x;
	*x=*y;
	*y=t;
}

int main(){
	int a,b;
	int *pi;
	a=1;
	b=2;
	pi=&a;
	*pi=3; //a=3 now
		
	printf("pi=%d\n",*pi);
	printf("a=%d\n",a);
	Swap(&a,&b);
	printf("a=%d,b=%d\n",a,b);
	return 0;
}
