#include <stdio.h>

struct date{
	int year;
	int month;
	int day;
};

enum WEEK_DAY{sunday,monday,tuesday,wednesday,thursday,friday,saturday};

int calc_weekday(int year,int day);
int addup_day(struct date *dt);
void output_weekday(int weekday);
int leap_year(int y);

int main(){
	struct date dt;
	int weekday;
	
	while(scanf("%d%d%d",&dt.year,&dt.month,&dt.day)==3){	
		//printf("day:%d (this year)\n",addup_day(&dt));
		output_weekday(calc_weekday(dt.year,addup_day(&dt)));
	}
	return 0;
}

int calc_weekday(int year,int day){
	year--;
	return (year+year/4-year/100+year/400+day)%7;
}

int addup_day(struct date *dt){
	int i,day,month_d[12]={31,28,31,30,31,30,31,31,30,31,30,31};

	for(day=i=0;i<dt->month-1;i++)
		day+=month_d[i];
	if(dt->month>2&&leap_year(dt->year))
		day++;
	return day+=dt->day;
}

void output_weekday(int weekday){
		switch(weekday){
		case monday:printf("monday\n");break;
		case tuesday:printf("tuesday\n");break;
		case wednesday:printf("wednesday\n");break;
		case thursday:printf("thursday\n");break;
		case friday:printf("friday\n");break;
		case saturday:printf("saturday\n");break;
		case sunday:printf("sunday\n");break;
		default:break;
	}
}

int leap_year(int y){
	return y%4==0&&y%100!=0||y%400==0;
}