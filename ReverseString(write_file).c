#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverse(char* s){
    char t;
    char* p = s;
    char* q = s+strlen(s)-1;

    while(q > p){
        t = *p ;
        *p++ = *q;
        *q-- = t ;
    }
    return s ;
}

int main(){
	FILE *fp;
	char s[10];
	
	fp=fopen("a1","w");
	gets(s);
	reverse(s);
	puts(s);
	fputs(s,fp);
	fclose(fp);
	return 0;
}
