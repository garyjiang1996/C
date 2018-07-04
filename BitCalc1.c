/*
& operator:
	1.set num 0: 5&3
	2.get specific bit:00101100 10101100&11111111 11111111
	3.keep specific bit:84->01010100 keep 84's 3 4 5 7 8 bit
	  0101 0100&0011 1011 (set 1 2 6 =0)
| operator:
	1.set num's n bits to 1, like set x's right 4 bits 0, 
	  n|8 (n|1 0000)
^ opertator:
	1.revert bits: x^1->1^1=0,0^1=1
	2.not change:x^0->1^0=1,0^0=0
>> opertator:
	1.left bits fill with 0 (logic)
	2.left bits fill with 1 (arith)
*/
#include <stdio.h>

char is_odd(int x);
void swap(int *a,int *b);

int main(){
	int a,b;
	while(~scanf("%d%d",&a,&b)){
		//printf("%d\n",is_odd(a));
		//printf("%d\n",a&b);
		//printf("%d\n",a|b);
		//swap(&a,&b);
		//printf("%d %d\n",a,b);
		a>>=1;
		printf("%d\n",a);
	}
	return 0;
}

char is_odd(int x){
	if(x&1)
		return 1;
	else
		return 0;
} 

void swap(int *a,int *b){
	*a=*a^*b;
	*b=*b^*a;
	*a=*a^*b;
//	*a=*a^*b^(*b^(*a^*b));
}
