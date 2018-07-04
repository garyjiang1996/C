#include <stdio.h>
int main(){
	int t,c;
	
	for (;;) {
    fputs("Please input an integer: ", stdout);
        if ( scanf("%d", &t) != EOF ) {
            while ( (c=getchar()) != '\n' && c != EOF ) {
            	;
            } 
        }
        printf("%d\n", t);
		printf("octal-> %o\n",t);
		printf("decimal-> %d\n",t);
		printf("hexadicimal-> %x\n",t);
    }
	return 0;
}
