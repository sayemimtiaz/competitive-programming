#include<stdio.h>
int main()
{
	int a[8]={2,3,4,5,6,7,8,9};
	long n,i,kase,j;
	char s[1000];
	bool flag;
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%ld",&n);
		i=0;
		if(n==1||n==0)
		{
			printf("%ld\n",n);
			continue;
		}
		while(n!=1)
		{
			flag=0;
			for(j=7;j>=0;j--)
			{
			if(n%a[j]==0)
			{
				flag=1;
				s[i++]=a[j]+'0';
				n/=a[j];
				break;
			}
			}
			if(!flag)
				break;
		}
		if(flag)
		{
			for(j=i-1;j>=0;j--)
			printf("%c",s[j]);
			printf("\n");
		}
		else
			printf("-1\n");
	}
	return 0;
}
