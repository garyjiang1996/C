# include<stdio.h>
# include<math.h>

int main()
{
	double a,b,c,det,x1,x2;
	scanf("%lf%lf%lf",&a,&b,&c);
	det=b*b-4*a*c;

	x1=(-b+sqrt(det))/(2*a);
	x2=(-b-sqrt(det))/(2*a);

	if(sqrt(det)>0)
		printf("x1=%lf,x2=%lf\n",x1,x2);
	if(fabs(det)<1e-6)
	{
		printf("x1=%lf,x2=%lf\n",x1,x2);
	}
	if(sqrt(det)<0)
		printf("there is no roots\n");
	return 0;
	
}
