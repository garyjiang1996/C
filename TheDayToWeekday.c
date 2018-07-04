#include <stdio.h>
#define TRUE 1
#define FALSE 0

unsigned char lunar_year(int y){
	if((y%4==0&&y%100!=0)||y%400==0)
		return TRUE;
	else
		return FALSE;
} 

void output_weekday(int y,int day){
	int s;
	y--;
	s=y+y/4-y/100+y/400+day;
	
	switch(s%7){
		case 0:printf("Sunday");break;
		case 1:printf("Monday");break;
		case 2:printf("Tuesday");break;
		case 3:printf("Wednesday");break;
		case 4:printf("Thursday");break;
		case 5:printf("Friday");break;
		case 6:printf("Saturday");break;
	}
}

int main(){
	int y,m,d;
	//printf("input year month day:");
	scanf("%d%d%d",&y,&m,&d);	
	
	if(lunar_year(y)){
		switch(m){
			case 1:break;
			case 2:d+=31;break;
			case 3:d+=60;break;
			case 4:d+=91;break;
			case 5:d+=121;break;
					
			case 6:d+=152;break;
			case 7:d+=182;break;
			case 8:d+=213;break;
			case 9:d+=244;break;
			case 10:d+=274;break;
			
			case 11:d+=305;break;
			case 12:d+=335;break;
			default:break;			
		}	
	}else{
		switch(m){
			case 1:break;
			case 2:d+=31;break;
			case 3:d+=59;break;
			case 4:d+=90;break;
			case 5:d+=120;break;
					
			case 6:d+=151;break;
			case 7:d+=181;break;
			case 8:d+=212;break;
			case 9:d+=243;break;
			case 10:d+=273;break;
			
			case 11:d+=304;break;
			case 12:d+=334;break;
			default:break;
		}
	}
	output_weekday(y,d);
	return 0;
}
