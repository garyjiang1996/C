/*
	this program aims to calc 2 date's diff_day
	input date(yyyy-mmmm-dd) asume date2 is latter than date1
 */
#include <stdio.h>
#include <stdlib.h>

struct date{
	int year;
	int month;
	int day;
};

void input_date(struct date *dt);
int diff_day(struct date *dt1,struct date *dt2);
int leap_year(int y);

int main(){
	struct date dt1,dt2;
	//printf("input (year month day):\n");
	input_date(&dt1),input_date(&dt2); //assume dt1<dt2
	printf("diff days=%d\n",diff_day(&dt1,&dt2));
	return 0;
}

void input_date(struct date *dt){
	scanf("%d%d%d",&dt->year,&dt->month,&dt->day);
}

int diff_day(struct date *dt1,struct date *dt2){
	int i,j,days,month_d[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	days=0;

	for(i=dt1->year;i<=dt2->year-1;i++){
		if(leap_year(i)){
			days+=366;
		}else{
			days+=365;
		}
	}
	for(j=dt1->month-1;j<dt2->month-1;j++){
		days+=month_d[j];
	}
	if(dt2->month>2&&leap_year(dt2->year)){
		days++;
	}
	days+=dt2->day-dt1->day;
	return days;
}

int leap_year(int y){
	return y%4==0&&y%100!=0||y%400==0;
}