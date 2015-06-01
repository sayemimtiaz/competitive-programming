#include<stdio.h>
long W[1000],max,N,P,Q;
void check(long pos,long sum,long how)
{
    if(max<how)
		max=how;
	long i;
	for(i=pos+1;i<N;i++)
	{
		if((sum+W[i])<=Q&&(how+1)<=P)
			check(i,sum+W[i],how+1);
	}
}
int main()
{
	long kase,kas=1,i;
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%ld %ld %ld",&N,&P,&Q);
		for(i=0;i<N;i++)
			scanf("%ld",&W[i]);
		max=-100000;		
		for(i=0;i<N;i++)
		{
			if(W[i]<=Q)
			check(i,W[i],1);
		}
		if(max<0)
			max=0;
		printf("Case %ld: %ld\n",kas++,max);
	}
	return 0;
}