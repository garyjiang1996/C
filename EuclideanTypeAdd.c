/*
	one necessary condition of the perfect num:
	plus digital's num eventually sum will =1:
	28:s=2+8=10 10:1+0=1;
	496:4+9+6=19 19:1+9=10 10:1+0=1;
*/
#include <stdio.h>

int main(){
	int x,s,digital;
	s=0;
	
	printf("type in a num and its digital:\n");
	
	while(~scanf("%d%d",&x,&digital)){
		if(x==6){
			printf("true!\n",x);
			continue;
		}
		while(digital--){
			while(x){
				s+=x%10;
				x/=10;
			}		
			if(s==1){
				printf("true!\n");
				s=0;
				break;
			}
			x=s;
			s=0;
		}
	}
	return 0;
}