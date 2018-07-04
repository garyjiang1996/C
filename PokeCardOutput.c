#include<stdlib.h>
#include<stdio.h>

void output1(int user[][13],char *c_kind);
void output2(int user[][13],char *c_kind);

int main(){
	int card[52];
	int user[4][13];
	int hand1,hand2,hand3,hand4; 
	char c_kind[13]={'A','2','3','4','5','6','7','8','9','0','J','Q','K'};
	int i,j;
	int roll,is_new;
	
	i=j=0;
	hand1=hand2=hand3=hand4=0;
	
	while(i++<52){
		roll=rand()%52;
		for(is_new=1;j<i&&is_new;j++){
			if(roll==card[j]){
				is_new=0;
				break;
			}
		}
		if(is_new){
			switch(i%4){
				case 0:
					user[0][hand1++]=roll;
					break;
				case 1:
					user[1][hand2++]=roll;
					break;
				case 2:
					user[2][hand3++]=roll;
					break;
				case 3:
					user[3][hand4++]=roll;
					break;
				default:break;
			}
		}
	}
		output2(user,c_kind);
	return 0;
}
//按玩家输出 
void output1(int user[][13],char *c_kind){
	int i,j,temp,temp2;
	for(i=0;i<4;i++){
		printf("user%d's card':\n",i);
		for(j=0;j<13;j++){
			temp=user[i][j]%13;
			temp2=user[i][j]/13;
			switch(temp2){
				case 0:printf("Spade:%c ",c_kind[temp]);break;
				case 1:printf("heart:%c ",c_kind[temp]);break;
				case 2:printf("plum:%c ",c_kind[temp]);break;
				case 3:printf("diamond:%c ",c_kind[temp]);break;
			}
		}
		printf("\n");
	}
} 
//按花色输出 
void output2(int user[][13],char *c_kind){
	int i,j;
	for(i=0;i<4;i++){
		printf("\n\nuser%d's card':",i+1);
		printf("\nSpade:");
		for(j=0;j<13;j++){
			if(user[i][j]/13==0){
				printf("%c",c_kind[user[i][j]%13]);
			}
		}
		printf("\nHeart:");
		for(j=0;j<13;j++){
			if(user[i][j]/13==1){
				printf("%c",c_kind[user[i][j]%13]);
			}
		}
		printf("\nDiamond:");
		for(j=0;j<13;j++){
			if(user[i][j]/13==2){
				printf("%c",c_kind[user[i][j]%13]);
			}
		}
		printf("\nPlum:");
		for(j=0;j<13;j++){
			if(user[i][j]/13==3){
				printf("%c",c_kind[user[i][j]%13]);
			}
		}
	}
}
