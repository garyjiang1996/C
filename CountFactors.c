#include <stdio.h>
#include <math.h>

int count_factors(int x){
	if(x==1) 
		return 1;
	int count,i;
	count=2;
	for(i=2;i<=sqrt(x);i++){
		if(x%i==0){
			if(x/i==i&&i==sqrt(x)){
				count++;
			}else{
				count+=2;
			}
		}
	}
	return count;
}


int main(){
	int x;
	while(~scanf("%d",&x))
		printf("%d\n",count_factors(x));
	return 0;
}