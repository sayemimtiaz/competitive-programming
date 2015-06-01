#include<stdio.h>
int main()
{
	long step,mod,initial,seed,sum_1,sum_2;
	while(scanf("%ld %ld",&step,&mod)==2)
	{
		initial=step%mod;
		seed=initial;
		sum_1=initial;
		while(1)
		{
			seed=(seed+step)%mod;
			
			if(seed==initial)
				break;
				sum_1+=seed;
		
		}
		sum_2=((mod-1)*mod)/2;
     		printf("%10ld%10ld",step,mod);
			if(sum_1==sum_2)
			 printf("    Good Choice");
			else
			   printf("    Bad Choice");
			printf("\n\n");
	}
	return 0;
}
