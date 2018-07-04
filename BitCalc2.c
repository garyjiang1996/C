#include <stdio.h>

int SetBitToZero(unsigned value,int b_count){
	value=value&b_count;
	return value;
}

int main(){
	int x=13;
	int bit_count=65535;
	printf("%d\n",SetBitToZero(x,bit_count));
	return 0;
}
