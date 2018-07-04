#include <stdio.h>

enum COLOR{RED,GREEN,BLUE,NumCOLORS};
//enum中的值由red=0依次+1
//enum中的类型相当于const int
//c语言中enum的定义就是int类型
void f(enum COLOR c);

int main(){
	int color;
	char *ColorNames[NumCOLORS]={"red","green","blue"};
	char *colorName=NULL;
	
	setvbuf(stdout,NULL,_IONBF,0);
	printf("input color num you like:\n");
	scanf("%d",&color);
	
	if(color>=0&&color<NumCOLORS){
		colorName=ColorNames[color];
	}else{
		colorName="unknown";
	}
	printf("color you like is:%s\n",colorName);
	f(color);
	return 0;
}

void f(enum COLOR c){
	if(c>=0&&c<NumCOLORS)
		printf("color you like is no %d",c);
}