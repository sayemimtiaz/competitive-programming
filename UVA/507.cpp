#include<stdio.h>
long long s[100000];
int main()
{
	long long kas=1,kase,stop,a,max,save,d,savstrt,savend,start,end,sum,i;
	bool endfnd,strtfnd;
	scanf("%lld",&kase);
	while(kase--)
	{
		scanf("%lld",&stop);
		sum=0;
		max=-10000000000000000;
		for(i=1;i<stop;i++)
		{
			scanf("%lld",&a);
			sum+=a;
			if(max<sum)
				max=sum;
			s[i]=sum;
			if(sum<0)
				sum=0;
		}
		if(max<0)
			printf("Route %lld has no nice parts\n",kas++);
		else
		{
		save=-10000000000000000;
		end=start=0;
		strtfnd=endfnd=0;
		for(i=1;i<stop;i++)
		{
				if(!strtfnd&&s[i]>=0)
			{
				start=i;
				strtfnd=1;
			}
			if(s[i]==max)
			{
				end=i+1;
				endfnd=1;
			}
			if(s[i]<0||i==stop-1)
			{
				d=end-start;
				if(endfnd&&d>save)
				{
					savstrt=start;
					savend=end;
					save=d;
				}
				endfnd=strtfnd=0;
			}
		}
		printf("The nicest part of route %lld is between stops %lld and %lld\n",kas++,savstrt,savend);
		}
	}
	return 0;
}