#include <stdio.h>

#define N 3
#define M 3
#define SWAP(x,y,t) t=(x);(x)=(y);(y)=t;

void init(int matrix[][M],iMt n,int m);
void init_input(int matrix[][M],int n,int m);
void output1(int matrix[][M],int n,int m);
void output2(int **matrix,int n,int m);
int max(int matrix[][M],int n,int m);
int min(int matrix[][M],int n,int m);
int** transpose(int matrix[][M],int n,int m);
void add(int matrix1[][M],int matrix2[][M],int n,int m);
void minus(int matrix1[][M],int matrix2[][M],int n,int m);
int ** multiply(int matrix1[][M],int matrix2[][M],int n1,int m1,int n2,int m2);

int main(){
	int matrix1[N][M];
	
	init(matrix1,N,M);
	output1(matrix1,N,M);
	
	int **matrix_trans;
	matrix_trans=transpose(matrix1,N,M); //transpose matrix1
	output2(matrix_trans,N,M);
	
	int max_value,min_value; //find min,max in matrix
	max_value=max(matrix1,N,M);
	printf("max=%d\n",max_value);
	min_value=min(matrix1,N,M);
	printf("min=%d\n",min_value);	
	
	int matrix2[N][M],matrix3[N][M]; //add matrix3 to matrix2
	init(matrix2,N,M);
	init(matrix3,N,M);
	add(matrix2,matrix3,N,M);
	output1(matrix2,N,M);
	
	return 0;
}

void init(int matrix[][M],int n,int m){
	int i,j,t=1;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			matrix[i][j]=t++;
		}
	}
}

void init_input(int matrix[][M],int n,int m){
	int row,col;
	printf("input matrix1's row, column:");
	scanf("%d%d",&row,&col);
	printf("input units:");
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			scanf("%d",&matrix[i][j]);
		}
	}
}

void output1(int matrix[][M],int n,int m){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%2d ",matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void output2(int **matrix,int n,int m){
	int i,j;
	i=j=0;
	while(i<m){
		while(j<n){
			printf("%2d ",matrix[i][j++]);
		}
		printf("\n");
		i++,j=0;
	}
	printf("\n");
}

int max(int matrix[][M],int n,int m){
	int i,j,max_i,max_j;
	for(max_i=matrix[0][0],i=0;i<n;i++){
		for(max_j=matrix[i][0],j=1;j<m;j++){
			if(matrix[i][j]>max_j){
				max_j=matrix[i][j];
			}
		}
		if(max_j>max_i){
			max_i=max_j;
		}
	}
	return max_i;
}

int min(int matrix[][M],int n,int m){
	int i,j,min_i,min_j;
	for(min_i=matrix[0][0],i=0;i<n;i++){
		for(min_j=matrix[i][0],j=1;j<m;j++){
			if(matrix[i][j]<min_j){
				min_j=matrix[i][j];
			}
		}
		if(min_j<min_i){
			min_i=min_j;
		}
	}
	return min_i;
}

int** transpose(int matrix[][M],int n,int m){
	int i,j;
	int **matrix_trans;
	matrix_trans=(int**)malloc(n*sizeof(int*));
	
	for(i=0;i<n;i++){
		*(matrix_trans+i)=(int*)malloc(m*sizeof(int));
		for(j=0;j<m;j++){
			matrix_trans[i][j]=matrix[j][i];
		}
	}
	return matrix_trans;
}

void add(int matrix1[][M],int matrix2[][N],int n,int m){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			matrix1[i][j]+=matrix2[i][j];
		}
	}
}

int** multiply(int matrix1[][M],int matrix2[][M],int n1,int m1,int n2,int m2){
	if(m1!=r2)	
		exit(EXIT_FAILURE);
	int **matrix_multi;
	matrix_multi=(int**)maclloc(n1*sizeof(int*));
	
	for(j=0;j<m2;j++)
		*(matrix_multi)=(int*)maclloc(sizeof(int));
	for(i=0;i<n1;i++){
		for(j=0;j<m2;j++){
			for(k=0;k<m1;k++){
				matrix[i][j]=matrix[i][j]+matrix1[i][k]*matrix2[k][j];
			}
		}
	}	
}
