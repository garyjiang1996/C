#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define P(k,a,b) printf("%d=%d+%d\n",k,a,b);

int prime(int n){
	int i;
	for(i=2;i<=sqrt(n);)
		if(!(n%i++))	
			return 0;
	return 1;
} 

int main(){
	int k,a,b;
	
	for (k=4;k<=100;k=k+2){
		for (a=2;a<=k/2;a++){
			if (prime(a))	b=k-a;  
			if (prime(b))	{P(k,a,b);break;}
		}
	}
	return 0;
}
