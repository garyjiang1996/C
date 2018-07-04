#include <stdio.h>
#include <stdlib.h>

int main(){
	int ch,brace=0;
	while((ch=getchar())!=EOF){
		if(ch=='{')
			brace+=1;
		if(ch=='}')
			if(brace==0)	
				printf("Lack of: {");
			else
				brace-=1;
		}
		if(brace>0)
			printf("Lack of: }");
		else
			printf("Corrent with {}");
	return EXIT_SUCCESS;
}