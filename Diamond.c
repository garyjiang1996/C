#include<stdio.h>
#define ROW 3

int main()
{
	int i,j;
	for(i=0;i<ROW+1;i++){		//i:row from 0+...+ROW
		for(j=0;j<ROW-i;j++)	//j:" "  0+...ROW-i-1
			printf(" ");
		for(j=0;j<2*i+1;j++)  	//j:"*"
			printf("*");
		printf("\n");
	}							//--middle--
	for(i=0;i<ROW;i++){		//i:row from 0+...+ROW-1
		for(j=0;j<i+1;j++)
			printf(" ");
		for(j=0;j<2*(ROW-i)-1;j++)
			printf("*");
		printf("\n");
	}
	return 0;
}
