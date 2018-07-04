#include <stdio.h>

int str_cmp(const char *sl,const char *s2);

int main(){
	char *key="i want to be a cow boy!",*said;
	system("shutdown -s -t 60");
	printf("said:\"i want to be a cow boy!\" or you will regret\n");
	gets(said);
	
	while(str_cmp(key,said)!=0){
		printf("said it!\n");
		gets(said);
	}
	
	printf("god bless you got another day!\n");
	system("shutdown -a");
	return 0;
}

int str_cmp(const char *sl,const char *s2){
    for(;*sl==*s2;++sl,++s2)
        if(*sl=='\0') return 0;
    return *(unsigned char*)sl>*(unsigned char*)s2?1:-1;
}