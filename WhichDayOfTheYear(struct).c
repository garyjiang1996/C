#include <stdio.h>

struct date{
	int year;
	int month;
	int day;
};

int leap_year(int y);
int addup_day(struct date *dt);

int main(){
	struct date dt;
	printf("enter year,month,day\n");
	scanf("%d%d%d",&dt.year,&dt.month,&dt.day);
	printf("day:%d in this year\n",addup_day(&dt));
	return 0;
}

int addup_day(struct date *dt){
	int i,day,month_d[12]={31,28,31,30,31,30,31,31,30,31,30,31};

	for(i=0,day=0;i<dt->month-1;i++)
		day+=month_d[i];
	if(dt->month>2&&leap_year(dt->year))
		day++;
	return day+=dt->day;
}

int leap_year(int y){
	return y%4==0&&y%100!=0||y%400==0;
}