#include <stdio.h>

int is_palindromic_num(int a,int scale){
	int b,a_copy;
	b=0,a_copy=a;
	while(a){
		b=b*scale+a%scale;
		a/=scale;
	}
	printf("a=%d\n",a_copy);
	printf("b=%d\n",b);
	return a_copy==b;
}

int main(){
	int a,scale;
	while(~scanf("%d%d",&a,&scale)){
		if(is_palindromic_num(a,scale)){
		printf("a is a palindromic num\n");
		}else{
		printf("a is not a palindromic num\n");
		}
	}
	return 0;
}