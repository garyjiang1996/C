#include <stdio.h>
#include <stdlib.h>
#define M 10

int main(){
	int i,j,k,row1,col1,row2,col2;
	int matrix1[M][M],matrix2[M][M],matrix[M][M];

	printf("input matrix1's row, column:");
	scanf("%d%d",&row1,&col1);
	printf("units:");
	for(i=0;i<row1;i++){
		for(j=0;j<col1;j++){
			scanf("%d",&matrix1[i][j]);
		}
	}
	printf("input matrix2's row, column:");
	scanf("%d%d",&row2,&col2);
	printf("units:");
	for(i=0;i<row2;i++){
		for(j=0;j<col2;j++){
			scanf("%d",&matrix2[i][j]);
		}
	}
	
	if(col1!=row2)	exit(EXIT_FAILURE);
	//initialize
	for(i=0;i<row1;i++){
		for(j=0;j<col2;j++){				
			matrix[i][j]=0;			
		}
	}
	//calc
	for(i=0;i<row1;i++){
		for(j=0;j<col2;j++){
			for(k=0;k<col1;k++){
				matrix[i][j]=matrix[i][j]+matrix1[i][k]*matrix2[k][j];
			}
		}
	}	
	printf("multiplied:\n");
	for(i=0;i<row1;i++){
		for(j=0;j<col2;j++){
			printf("%5d",matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
