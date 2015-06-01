#include<stdio.h>
long w[2000],p[2000][2000],v[2000];
int main()
{
	long c,sum,n,i,j,k,w1,w2,kase;
	scanf("%ld",&kase);
	while(kase--)
	{
	scanf("%ld",&n);
	for(i=1;i<=n;i++)
		scanf("%ld %ld",&v[i],&w[i]);
	scanf("%ld",&c);
	sum=0;
	while(c--)
	{
		scanf("%ld",&k);
	for(i=0;i<=k;i++)
		p[0][i]=0;
	for(i=0;i<=n;i++)
		p[i][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{
			w1=p[i-1][j];
			w2=(w[i]<=j)?v[i]+p[i-1][j-w[i]]:0;
			if(w1<w2)
				p[i][j]=w2;
			else
				p[i][j]=w1;
			
		}
	} 
	sum+=p[n][k];
	}
	printf("%ld\n",sum);
	}
	return 0;
}