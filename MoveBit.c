#include <stdio.h>

void CountOneBits(unsigned value,int *bits0,int *bits1){
	for(;value!=0;value=value>>1){
		if(value%2==0)
			(*bits0)++;
		else
			(*bits1)++;
	}
}
int main(){
	int bits0=0,bits1=0;
	int x=8,y=13,z=10244;
	CountOneBits(x,&bits0,&bits1);
	printf("%d contains: 0 bit:%d	1 bit:%d\n",x,bits0,bits1);
	CountOneBits(y,&bits0,&bits1);
	printf("%d contains: 0 bit:%d	1 bit:%d\n",y,bits0,bits1);
	CountOneBits(z,&bits0,&bits1);
	printf("%d contains: 0 bit:%d	1 bit:%d\n",z,bits0,bits1);
	return 0;
}
