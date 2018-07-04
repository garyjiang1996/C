#include <stdio.h>
#define SWAP(x,y,t)((t)=(x),(x=y),(y=t));

void Perm(char *list,int i,int n){
	int j,temp;
	if(i==n){
		for(j=0;j<=n;j++)
			printf("%c",list[j]);
		printf("    ");
	}else{
		for(j=0;j<=n;j++){
			SWAP(list[i],list[j],temp);
			Perm(list,i+1,n);
			SWAP(list[i],list[j],temp);
		}
	}	
}

int main(){
	char s1[3]={'A','B','C'};
	Perm(s1,0,3);
	return 0;
}
