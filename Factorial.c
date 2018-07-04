#include <stdio.h>

int factorial_whileloop(int n){
	int t,i;
	t=i=1;
	while(i<=n)
		t*=i++;
	return t;	
}

int factorial_recursive(int n){
	if(n==0||n==1)
		return 1;
	else
		return n*factorial_recursive(n-1);
}

int factorial_recursive_tail(int n,int t){
	if(n==0)
		return 1;
	if(n==1)
		return t;
	else
		return factorial_recursive_tail(n-1,n*t);
}

int main(){
	int n,t;
	n=4; //suppose n >=0
	
	printf("func whileloop:%d\n",factorial_whileloop(n));
	printf("func recursive:%d\n",factorial_recursive(n));
	printf("func recursive_tail:%d",factorial_recursive_tail(n,1));
	
	return 0;
}
