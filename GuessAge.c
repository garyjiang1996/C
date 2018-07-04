#include "stdio.h"

int age(int n){
	if(n==1)
		return 10;
	else
		return 2+age(n-1);	
}

int main(){
	int n;
	printf("type in n (man in order)\n");
	scanf("%d",&n);
	printf("the man in order %d 's age is %d\n",n,age(n));
	return 0;
}
