#include<stdio.h>
#include<string.h>
long double nway[40000];
long coin[5]={50,25,10,5,1};
int main()
{
	long i,j,n,c;
	while(	scanf("%ld",&n)==1)
	{
		memset(nway,0,sizeof(nway));

		nway[0]=1;
		for(i=0;i<5;i++)
		{
			c=coin[i];
			for(j=c;j<=n;j++)
			{
				nway[j]+=nway[j-c];
			}
		}
		if(nway[n]!=1)
		printf("There are %0.Lf ways to produce %ld cents change.\n",nway[n],n);
		else
			printf("There is only 1 way to produce %ld cents change.\n",n);
	}
	return 0;
}