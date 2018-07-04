//YangHui's triangle like below:
//1
//11
//121
#include "stdio.h"

void yanghui_triangle1(int n);
void yanghui_triangle2(int n);
void yanghui_triangle3(int n);
void yanghui_triangle4(int n);
void yanghui_triangle5(int n)

int main(){
	int n;
	while(~scanf("%d",&n)&&!(n>=1&&n<=10));
	yanghui_triangle4(n);
	return  0;
}

void yanghui_triangle1(int n){
	int i,j,a[10][10]={0}; 

	for(i=1;i<n;i++){
		a[i][0]=1;
		for(j=1;j<=i;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j];
	}

	for(i=0;i<n;i++){ 
		for(j=0;j<=i;j++)
			printf("%d",a[i][j]);
		printf("\n");
	}
}

void yanghui_triangle2(int n){
	int i,j,a[10][10]={0,1}; 
	
	for(i=1;i<n+1;i++){
		for(j=1;j<=i;j++)
			a[i][j]=a[i-1][j-1]+a[i-1][j];
	}
	
	for(i=1;i<n+1;i++){
		for(j=1;j<=i;j++)
			printf("%d",a[i][j]);
		printf("\n");
	}
}

void yanghui_triangle3(int n){
	int i,j,a[10][10]={0,1}; 
	
	for(i=1;i<n+1;i++){
		for(j=1;j<=i;j++){
			a[i][j]=a[i-1][j-1]+a[i-1][j];
			printf("%d",a[i][j]);
		}
		printf("\n");
	}
}

void yanghui_triangle4(int n){
	int i,j,a[10]={1},b[10];
	
	for(i=0;i<n;i++){
		b[0]=a[0];
		for(j=1;j<=i;j++){
			b[j]=a[j-1]+a[j];
		}
		for(j=0;j<=i;j++){
			a[j]=b[j];
			printf("%d",a[j]);
		}
		printf("\n");
	}
}

void yanghui_triangle5(int n){
	int i,j,l,r,a[10]={0,1};
	
	for(i=1;i<=n;i++){ 
		l=0;
		for(j=1;j<=i;j++){ 
			r=a[j];
			a[j]=l+r;
			l=r;
			printf("%d",a[j]);
		}
		printf("\n");
	}
}