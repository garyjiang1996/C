 #include <stdio.h>
#include <stdlib.h>

int main(){
	int ch,size,index;

	while((ch=getchar()!=EOF)&&ch!='\n'){
		switch(ch){
			case 1:	printf("this is 1:");
					break;
			
			case 2:	printf("this is 2:");
					break;
			default:
					printf("invalid option.\n");
					break;
		}
	}
	system("pause");
	return 0;
}