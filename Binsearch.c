#include <stdio.h>
#include <time.h>
#define MAX_SIZE 32
//#define COMPARE(x,y) ((x)<(y)?-1:((x)==(y)?0:1))	//x>y:1 x<y:-1 x=y:0
#define COMPARE(x,y) ((x)>(y)?1:((x)<(y)?-1:0))

int bin_search1(int list[],int num,int left,int right){
	int middle;
	while(left<=right){
		middle=(left+right)/2;
		if(num<list[middle])
			right=--middle;
		else if(num==list[middle])
			return 1;
		else
			left=++middle;
	}
	return -1;
}

int bin_search2(int list[],int num,int left,int right){
	int middle;
	while(left<=right){
		middle=(left+right)/2;
		switch(COMPARE(list[middle],num)){
				case -1:left=++middle;break;
				 case 0:return 1;
			      case 1:right=--middle;break;
		}
	}
	return -1;
}

int bin_search3(int list[],int num,int left,int right){
	int middle;
	if(left<=right){
		middle=(left+right)/2;
		switch(COMPARE(list[middle],num)){
				case -1:bin_search3(list,num,middle+1,right);break;
				 case 0:return 1;
			      case 1:bin_search3(list,num,left,middle-1);break;
		}
	}
}
void output(int flag){
	switch(flag){
		case 1:printf("Found!\n");break;
		 case -1:printf("can't find.\n");break;
		  default:break;
	}
}

int main(){
	int list[MAX_SIZE];
	int i;

	printf("initial list:");
	for(i=0;i<MAX_SIZE;i++){
		list[i]=i;
		printf("%d ",list[i]);
	}

	printf("\ninput a num to search:");
	int number;
	scanf("%d",&number);
	
	int ans;
	int span; 
	
	clock_t t0,t1;
	t0=clock();
	t1=clock();
	ans=bin_search1(list,number,0,MAX_SIZE-1);
	span=(t1-t0)/CLOCK_PER_SEC;
	printf("time spent:%d\n",span);	
	output(ans);
	return 0;
}
