#include<stdio.h>
int main()
{
	long r,n,i,j,a;
	j=1;
	while(1)
	{
		scanf("%ld %ld",&r,&n);
		if(r==0&&n==0)
			break;
		long b=r;
		r=r-n;
		int f=0;
		a=0;
		if(r==0||b<n)
		{
			f=1;
			i=0;
		}
		else
		{
		for(i=1;i<=26;i++)
		{
			a+=n;	
			if(a>=r)
			{
				f=1;
				break;
			}
		}
		}
		if(f==1)
			printf("Case %ld: %ld\n",j,i);
		else
			printf("Case %ld: impossible\n",j);
		j++;
	}
	return 0;
}


