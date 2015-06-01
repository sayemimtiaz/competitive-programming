#include<stdio.h>
long memo[100][100];
long recurs(long n,long k)
{
	if(memo[n][k])
		return memo[n][k];
	if(k==1)
		return 1;
	else
	{
		long i,res=0;
	  for(i=0;i<=n;i++)
		 res=(res+recurs(n-i,k-1))%1000000;
	  memo[n][k]=res;
	}
	return memo[n][k];

}
int main()
{
	long N,K,i,j;
	while(scanf("%ld %ld",&N,&K)==2&&(N||K))
	{
		for(i=0;i<=100;i++)
			for(j=0;j<=100;j++)
			memo[i][j]=0;
		if(!K)
			printf("0\n");
		else
		printf("%ld\n",recurs(N,K));
	}
	return 0;
}