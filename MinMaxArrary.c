#include <stdio.h>

void MinMax(int a[],int len,int *min,int *max);

int main(int argc,char **argv){
	int a[8]={7,6,8,2,3,1,5,4};
	int min,max,len;
	len=sizeof(a)/sizeof(a[0]);
	MinMax(a,len,&min,&max);
	printf("min=%d,max=%d",min,max);
}

void MinMax(int a[],int len,int *min,int *max){
	*min=*max=a[0];
	int i;
	for(i=1;i<len;i++){
		if(a[i]<*min)
			*min=a[i];
		if(a[i]>*max)
			*max=a[i];
	}
}
