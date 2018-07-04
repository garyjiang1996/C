#include <stdio.h>

enum MONTH{january,february,march,april,may,june,july,august,september,october,november,december};
enum WEEK_DAY{sunday,monday,tuesday,wednesday,thursday,friday,saturday};
int month_d[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int calc_weekday(int year,int day);
void output_calender(int year,int first_day);
void ouput_month(int month);
void output_weekday(int weekday);
int leap_year(int year);

int main(){
	int year;
	while(~scanf("%d",&year)){	
		output_calender(year,calc_weekday(year,1));
	}
	system("pause");
	return 0;
}

int calc_weekday(int year,int day){
	year--;
	return (year+year/4-year/100+year/400+day)%7;
}

void output_calender(int year,int first_day){
	int i,j,k,t,cnt;
	char week_title[]=" SUN MON TUE WED TUE FRI SAT";
	//char week_title[]=" 周日 周一 周二 周三 周四 周五 周六";
	
	cnt=first_day+1;	
	if(leap_year(year)){
		month_d[1]=29;
	}
	for(i=0;i<12;i++){
		ouput_month(i);
		printf("\n%s\n",week_title);
		for(k=0;k<first_day;k++){
			printf("    ");
		}
		for(j=1;j<=month_d[i];j++){
			printf("%4d",j);
			t=cnt%7;
			if(t==0){
				printf("\n");
			}
			cnt++;
		}
		first_day=t;
		if(t!=0){
			printf("\n");
		}
	}
}

void ouput_month(int month){
	switch(month){
		case january:printf("Aanuary:");break;
		case february:printf("February:");break;
		case march:printf("March:");break;
		case april:printf("April:");break;
		case may:printf("May:");break;
		case june:printf("June:");break;
		case july:printf("July:");break;
		case august:printf("August:");break;
		case september:printf("September:");break;
		case october:printf("October:");break;
		case november:printf("November:");break;
		case december:printf("December:");break;
	}
		// switch(month){
		// case january:printf("一月:");break;
		// case february:printf("二月:");break;
		// case march:printf("三月:");break;
		// case april:printf("四月:");break;
		// case may:printf("五月:");break;
		// case june:printf("六月:");break;
		// case july:printf("七月:");break;
		// case august:printf("八月:");break;
		// case september:printf("九月:");break;
		// case october:printf("十月:");break;
		// case november:printf("十一月:");break;
		// case december:printf("十二月:");break;
	// }
}

void output_weekday(int weekday){
		switch(weekday){
		case monday:printf("Monday ");break;
		case tuesday:printf("Tuesday ");break;
		case wednesday:printf("Wednesday ");break;
		case thursday:printf("Thursday ");break;
		case friday:printf("Friday ");break;
		case saturday:printf("Saturday ");break;
		case sunday:printf("Sunday ");break;
		default:break;
		// switch(weekday){
		// case monday:printf("周一 ");break;
		// case tuesday:printf("周二 ");break;
		// case wednesday:printf("周三 ");break;
		// case thursday:printf("周四 ");break;
		// case friday:printf("周五 ");break;
		// case saturday:printf("周六 ");break;
		// case sunday:printf("周日 ");break;
		// default:break;
	}
}

int leap_year(int y){
	return y%4==0&&y%100!=0||y%400==0;
}