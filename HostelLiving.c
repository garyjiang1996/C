#include "stdio.h"
#include "stdlib.h"

int calculate(int start,int end,int pay)
{
	int sum;
	sum=end-start;
	return sum;
}

main()
{
	int start,end,pay,s;
	printf("when I arrive the hostle?");
	scanf("%d",&start);
	printf("when will I leave the hostle?");
	scanf("%d",&end);
	printf("how much will I pay everyday?");
	scanf("%d",&pay);
	s=calculate(start,end,pay);
	printf("I will stay :%d days\nI will pay :%d yuan",s,s*pay);
	return 0;
}
