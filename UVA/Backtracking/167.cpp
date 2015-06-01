#include<stdio.h>
#include<stdlib.h>
long x[100],grid[9][9],max;
bool place(long k,long i)
{
	long j;
	for(j=1;j<k;j++)
		if(x[j]==i||abs(x[j]-i)==abs(j-k))
			return false;
	return true;
}
void nqueen(long k)
{
	long j,i,sum;
	for(j=1;j<=8;j++)
	{
		if(place(k,j))
		{
			x[k]=j;
			if(k==8)
			{
				sum=0;
				for(i=1;i<=8;i++)
					sum+=grid[i][x[i]];
				if(max<sum)
					max=sum;
			}
			else
				nqueen(k+1);
		}
	}
}
int main()
{
	long n,i,j;
	scanf("%ld",&n);
	while(n--)
	{
		max=-100000000;
		for(i=1;i<=8;i++)
		{
			for(j=1;j<=8;j++)
				scanf("%ld",&grid[i][j]);
		}
		nqueen(1);
		printf("%5ld\n",max);
	}
	return 0;
}