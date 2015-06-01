#include<stdio.h>
#include<stdlib.h>

int x[10],min,q[10];

bool place(int k,int i)
{
	int j;
	for(j=1;j<k;j++)
		if(x[j]==i||abs(x[j]-i)==abs(j-k))
			return false;
	return true;
}
void nqueen(int k)
{
	int j,i,sum;
	for(j=1;j<=8;j++)
	{
		if(place(k,j))
		{
			x[k]=j;
			if(k==8)
			{
				sum=0;
				for(i=1;i<=8;i++)
                   sum+=((q[i]==x[i])?0:1);
				if(min>sum)
					min=sum;
			}
			else
				nqueen(k+1);
		}
	}
}
int main()
{
	int n,i,j,kas=1;
	while(~scanf("%d",&n))
	{
       min=1000000;
       q[1]=n;
		for(i=2;i<=8;i++)
		  scanf("%d",&n),q[i]=n;
		nqueen(1);
		printf("Case %d: %d\n",kas++,min);
	}
	return 0;
}
