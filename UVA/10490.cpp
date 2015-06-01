#include<stdio.h>
#include<math.h>
int main()
{
	int a,i;
	int prime[]={2,3,5,7,11,13,17,19,23,29,31};
	long double c;
	bool flag;
	while(1)
	{
		scanf("%d",&a);
		if(a==0)
			break;
		flag=false;
		if(a==11||a==23||a==29)
			printf("Given number is prime. But, NO perfect number is available.");
		else
		{
		for(i=0;i<11;i++)
		{
			if(a==prime[i])
			{
				flag=true;
				c=(pow(2,(a-1))*(pow(2,a)-1));
				printf("Perfect: %0.Lf!",c);
				break;
			}
		}
	
		if(flag==false)
			printf("Given number is NOT prime! NO perfect number is available.");
		}
		printf("\n");
	}
	return 0;
}


