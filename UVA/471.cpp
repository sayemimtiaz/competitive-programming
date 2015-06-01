#include<stdio.h>
#define MAX 9876543210
bool unique(unsigned long long n)
{
	unsigned long long a;
	bool flag[20]={0};
	while(n)
	{
		a=n%10;
		if(flag[a])
			return 0;
		flag[a]=1;
		n/=10;

	}
	return 1;
}
int main()
{
	bool flag=0;
	unsigned long long kase,n,s1,s2,upto;
	scanf("%llu",&kase);
	while(kase--)
	{
		scanf("%llu",&n);
		if(flag)
			printf("\n");
		flag=1;
		upto=MAX/n;
		for(s2=1;s2<=upto;s2++)
			if(unique(s2))
			{
				s1=s2*n;
				if(s1>MAX)
					break;
				if(unique(s1))
				printf("%llu / %llu = %llu\n",s1,s2,n);
			}
	}
	return 0;
}