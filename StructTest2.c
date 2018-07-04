#include <stdio.h>

typedef struct Date_{
	int year;
	int month;
	int day;
}Date; 

void show_date(Date *date);
int IsLeap(int year);
int MonthDays(Date d);

int main(){
	//初始化方式
	//Date today={2018,5,26};
	//Date tomorrow={.day=27,.month=5,.year=2018};
	//使用.来访问"结构变量"
	printf("today:%d/%d/%d\n",today.year,today.month,today.day);	
	printf("tomorrow:%d/%d/%d\n",tomorrow.year,tomorrow.month,tomorrow.day);
	printf("enter today's date(year/month/day)\n");
	fflush(stdout);
	Date today,tomorrow;
	scanf("%d/%d/%d",&today.year,&today.month,&today.day);
	
	if(today.day!=MonthDays(today)){
		tomorrow.day=today.day+1;
		tomorrow.month=today.month;
		tomorrow.year=today.year;
	}else if(today.month==12){
		tomorrow.day=1;
		tomorrow.month=1;
		tomorrow.year=today.year+1;
	}else{
		tomorrow.day=1;
		tomorrow.month=today.month+1;
		tomorrow.year=today.year;
	}
	printf("tomorrow:%d/%d/%d\n",tomorrow.year,tomorrow.month,tomorrow.day);
	return 0;
}

int MonthDays(Date d){
	int month_d[]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(IsLeap(d.year)&&d.month==2)
		return ++month_d[1];
	else
		return month_d[d.month-1];
}

int IsLeap(int y){
	if((y%4==0&&y%100!=0)||(y%400==0))
		return 1;
	else
		return 0;
}

void show_date(Date *d){
	printf("date:%d/%d/%d\n",d->year,d->month,d->day);
}