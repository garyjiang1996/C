#include<conio.h> 
#include<stdlib.h> 
#include<stdio.h> 
#include "windows.h"  

void gotoxy(int x,int y) /*����gotoxy����*/ 
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
		int x, y;/*�õ�λ��,x�����y����*/  
		int Vx, Vy;/*�õ���x��,y����ٶ�*/  
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
		gotoxy(man.x, man.y);/*�ѹ���Ƶ�ָ��������*/  
		printf(" ");/*���һ���ո�,����ǰ���ַ���ȥ*/  
		man.x += man.Vx;/*ˮƽ����x����ٶ��˶�*/  
		man.y += man.Vy;/*��ֱ����y����ٶ��˶�*/  
		if(man.x==0||man.x==80) 
			man.Vx*=-1; 
		if(man.y==0||man.y==80) 
			man.Vy*=-1; 
		gotoxy(man.x, man.y);  
		printf("%c\b", 2); /*���ASCII��ֵΪ2��"Ц��"�ַ�*/  
	} 
	getchar (); 
	return 0; 
}
