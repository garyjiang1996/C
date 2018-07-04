/*
	printf 4 kinds of 9*9 mutiplication table(In China, it's a table that 
	every student must have studied since primary school.)
*/

#include "stdio.h"

int main()
{
	//left-up
	int i,j;
	for(i=1;i<=9;i++){
		printf("\n");
		for(j=1;j<=9;j++){
				if(j>=i)
					printf("%d*%d=%2d ",i,j,i*j);
			}		
	}
	//left-bottom
	//int i,j;
	for(i=1;i<=9;i++){
		printf("\n");
		for(j=1;j<=i;j++){
				printf("%d*%d=%2d ",i,j,i*j);
			}		
	}
	//right-up
	//int i,j;
	for(i=1;i<=9;i++){
		printf("\n");
		for(j=1;j<=9;j++){
				if(j<i)
					printf("       ");
				else
					printf("%d*%d=%2d ",i,j,i*j);
			}		
	}
	//right-bottom
	//int i,j,n;
	int k;
	for(i=1;i<=9;i++){
		printf("\n");
		for(k=0;k<=9-i;k++){
			printf("       ");
		}
		for(j=1;j<=i;j++){
			printf("%d*%d=%2d ",i,j,i*j);
		}		
	}
	 return 0;
 }