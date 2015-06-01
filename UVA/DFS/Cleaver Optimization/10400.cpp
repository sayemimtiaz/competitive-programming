#include<stdio.h>
#include<memory.h>
char O[1000];
long t,p,a[1000];
bool flag,memo[120][65000];
void check(long result,long how,long s)
{
	if(flag)
		return;
	long i,d,c;
	if(how==p-1)
	{
		if(result==t)
		{
			flag=1;
			printf("%ld",a[0]);
			for(i=0;i<how;i++)
				printf("%c%ld",O[i],a[i+1]);
			printf("=%ld",t);
		}
		return;
	}
	d=result+a[s];
		if(d<=32000)
		{
			c=(d<0)?(64001+d):d;
		  if(!memo[s][c])
		  {
		  O[how]='+';
		  memo[s][c]=1;
		  check(d,how+1,s+1);
		  }
		}
	    d=result-a[s];
		if(d>=-32000)
		{
		  c=(d<0)?(64001+d):d;
		  if(!memo[s][c])
		  {
			  O[how]='-';
		  memo[s][c]=1;
		  check(d,how+1,s+1);
		  }
		}
		d=result*a[s];
		
		if(d<=32000&&d>=-32000)
		{
			c=(d<0)?(64001+d):d;
			if(!memo[s][c])
			{
			memo[s][c]=1;
		  O[how]='*';
		  check(d,how+1,s+1);
			}
		}
		d=result/a[s];
		if((d<=32000&&d>=-32000)&&(result%a[s])==0)
		{
			 c=(d<0)?(64001+d):d;
			if(!memo[s][c])
			{
			memo[s][c]=1;
		  O[how]='/';
		  check(d,how+1,s+1);
			}
		}
		
}
int main()
{
	long kase,i;
	scanf("%ld",&kase);
	while(kase--)
	{
		memset(memo,0,sizeof(memo));
		flag=0;
		scanf("%ld",&p);
		for(i=0;i<p;i++)
			scanf("%ld",&a[i]);
		scanf("%ld",&t);
		check(a[0],0,1);
		if(!flag)
			printf("NO EXPRESSION");
		printf("\n");
	}
	return 0;
}