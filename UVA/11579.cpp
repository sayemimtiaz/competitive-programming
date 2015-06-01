#include<stdio.h>
#include<math.h>
#include<stdlib.h>
long double  a[20000];
int comp(const void *a,const void *b)
{
	
	long double *x=(long double*)a;
long double *y=(long double*)b;
if(*x<*y)
return -1;
else if(*x>*y)
return 1;
return 0;
}
int main()
{
	bool flag;
	long n,kase,j,i;
	long double s,max,t;
	scanf("%ld",&kase);
	while(kase--)
	{
		flag=1;
		scanf("%ld",&n);
		for(i=0;i<n;i++)
			scanf("%Lf",&a[i]);
		qsort(a,n,sizeof(long double),comp);
		for(i=0;i<n-2;i++)
		{
					s=(a[i]+a[i+1]+a[i+2])/2;
					if(s<a[i]||s<a[i+1]||s<a[i+2])
						s=0;
					else
					{
					  s=(s*(s-a[i])*(s-a[i+1])*(s-a[i+2]));
					  s=sqrtl(s);
					}
	
					if(flag)
					{
						flag=0;
						max=s;
					}
					else if(max<s)
						max=s;

			}
			printf("%0.2Lf\n",max);

	}
	return 0;
}
