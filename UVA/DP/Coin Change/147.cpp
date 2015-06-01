#include<stdio.h>
#include<string.h>
 long double nway[10000];
long coin[]={1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
int main()
{
	long i,j,c ,n,a;
	nway[0]=1;
		for(i=0;i<11;i++)
		{
			c=coin[i];
			for(j=c;j<=6000;j++)
			{
				nway[j]+=nway[j-c];
			}
		}
	while(1)
	{
		scanf("%ld.%ld",&n,&a);
		n=n*100+a;
		a=n;
		if(!n)
			break;
		n/=5;
		printf("%6.2Lf%17.0Lf\n",a/(double)100,nway[n]); 
	}
	return 0;
}