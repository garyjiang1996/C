#include<conio.h> 
#include<stdlib.h> 
#include<stdio.h> 
#include "windows.h"  

void gotoxy(int x,int y) /*定义gotoxy函数*/ 
{} 
	 COORD c;  
	 c.X=x-1;  
	 c.Y=y-1;  
	 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);  
}  

int main() 
{ 
	struct point  
	{  
		int x, y;/*该点位置,x坐标和y坐标*/  
		int Vx, Vy;/*该点在x轴,y轴的速度*/  
	}man; 
	long p; 
	man.x=man.y=20; 
	man.Vx=man.Vy=1; 
	system("cls"); 
	p=100; //p=1000000000000000;
	
	while(p--) 
	{ 
		if(p%5) //p%50000
			continue; 
		gotoxy(man.x, man.y);/*把光标移到指定的坐标*/  
		printf(" ");/*输出一个空格,把先前的字符擦去*/  
		man.x += man.Vx;/*水平方向按x轴的速度运动*/  
		man.y += man.Vy;/*垂直方向按y轴的速度运动*/  
		if(man.x==0||man.x==80) 
			man.Vx*=-1; 
		if(man.y==0||man.y==80) 
			man.Vy*=-1; 
		gotoxy(man.x, man.y);  
		printf("%c\b", 2); /*输出ASCII码值为2的"笑脸"字符*/  
	} 
	getchar (); 
	return 0; 
}
