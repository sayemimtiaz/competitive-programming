#include<stdio.h>
int main()
{
	long n;
	double x,y,a,b;
	while(1)
	{
		scanf("%ld",&n);
		if(!n)
			break;
		scanf("%lf %lf",&a,&b);
		while(n--)
		{
		   scanf("%lf %lf",&x,&y);
		   if(x==a||y==b)
			   printf("divisa");
		   else if(x>a)
		   {
			   if(y>b)
				   printf("NE");
			   else
				   printf("SE");
		   }
		   else if(x<a)
		   {
			   	   if(y>b)
				   printf("NO");
			   else
				   printf("SO");
		   }
		   printf("\n");
		}
	}
	return 0;
}
