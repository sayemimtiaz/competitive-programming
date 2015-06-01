#include<stdio.h>
#include<string.h>
 long long nway[12000];
int main()
{
	long i,j,c ,n,a;
	long coin[30];
	for(i=1;i<=21;i++)
	 coin[i]=i*i*i;
	nway[0]=1;
		for(i=1;i<22;i++)
		{
			c=coin[i];
			for(j=c;j<10000;j++)
				nway[j]+=nway[j-c];
		}
	while(scanf("%ld",&n)==1)
	{
		printf("%lld\n",nway[n]); 
	}
	return 0;
}
