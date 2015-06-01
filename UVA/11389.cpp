#include<stdio.h>
#include<stdlib.h>
long a[1000000],b[1000000];
int cmp(const void *a,const void *b)
{
	long *x=(long*)a;
    long *y=(long*)b;
	return *x-*y;
}
int main()
{
	long s,c,n,d,r,i,j;
	while(scanf("%ld %ld %ld",&n,&d,&r)==3&&(n||d||r))
	{
		for(i=0;i<2;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%ld",&c);
				if(!i)
					a[j]=c;
				else
					b[j]=c;
			}
		}
		qsort(a,n,sizeof(long),cmp);
		qsort(b,n,sizeof(long),cmp);
		j=n-1;
		s=0;
		for(i=0;i<n;i++)
		{
			c=a[i]+b[j];
			if(c>d)
			{
				c=c-d;
				s+=c*r;
			}
			j--;
		}
		printf("%ld\n",s);
	}
	return 0;
}
