/*输入某年某月某日，判断这一天是这一年的第几天？
程序分析：以3月5日为例，应该先把前两个月的加起来，然后再加上5天即本年的第几天，特殊
 情况，闰年且输入月份大于3时需考虑多加一天*/
#include <stdio.h>

int month_days(int *month_d,int y,int m);
int is_leap_year(int y);

int main(){
	int month_d[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	int y,m,d;
	int days=0;

	while(~scanf("%d%d%d",&y,&m,&d)){
		days=month_days(month_d,y,m)+d;
		printf("days=%d\n",days);
	}
	return 0;
}

int month_days(int *month_d,int y,int m){
	int i,days=0;
	for(i=0;i<m-1;i++){
		days+=month_d[i];
	}
	if(is_leap_year(y)){
		days++;
	}
	return days;
}

int is_leap_year(int y){
	return y%400==0||y%4==0&&y%100!=0;
}