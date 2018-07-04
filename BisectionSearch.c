#include "stdio.h"

#define N 10

int BisectionMethod(int x,int *arr){
	int low=0,high=N-1,mid=(low+high)/2;
	
	if (x<arr[low]||x>arr[high])
		return 0;
	while(low<high){
		if(x==arr[mid]) 
			return 1;
		if(x>=arr[low]&&x<arr[mid]){
			high=mid;
			mid=(high+low)/2;
		}
		if(x>arr[mid]&&x<=arr[high]){
			low=mid;
			mid=(low+high)/2;
		}
	}
}

int main(int argc,char **argv){
	int arr[N];
	int i;
	for(i=0;i<N;i++)
		arr[i]=i;
	for(i=0;i<N;i++)	
		printf("%d ",arr[i]);		
	int x;
	int flag;
	printf("\ntype in a num to search:");
	scanf("%d",&x);
	flag=BisectionMethod(x,arr);
	if(flag)
		printf("the number exist in the array.");
	else
		printf("the number does not exist in the array.");
	return 0;
}
