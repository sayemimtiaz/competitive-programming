#include<stdio.h>
#include<string.h>
int main()
{
	long x[]={0,0,0,-1,1};
	long y[]={0,-1,1,0,0};
	long ka=1,d,a[10000],b[10000],r,c,i,j,n,l,s,e;
	bool f,f1,f2;
	while(1)
	{
		scanf("%ld %ld %ld",&r,&c,&n);
		if(!r&&!c&&!n)
			break;
		for(i=0;i<n;i++)
		{
			scanf("%ld %ld",&a[i],&b[i]);
		}
		scanf("%ld %ld",&s,&e);
		f=1;
		for(i=0;i<5;i++)
		{
			f1=0;
			l=s+x[i];
			d=e+y[i];
			if(l>=0&&l<r&&d>=0&&d<c)
			{
				for(j=0;j<n;j++)
				{
					if(a[j]==l||b[j]==d)
						f1=1;

				}
				if(!f1)
				{
					f=0;
					break;
				}
			}
		}
		printf("Case %ld:",ka++);
		if(!f)
			printf(" Escaped again! More 2D grid problems!");
		else
			printf(" Party time! Let's find a restaurant!");
	 printf("\n");
	}
	return 0;
}