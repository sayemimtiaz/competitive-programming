#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define SIZE 1000000
bool flag[SIZE];
double a[SIZE],al[SIZE];
long c=0,d=0;
int cmp(const void *a,const void *b)
{
	double *x=(double*)a;
	double *y=(double *)b;
	if(*x>*y)
		return 1;
	else if(*x<*y)
		return -1;
	return 0;
}
void sieve(double n)
{
	long i,j,r;
	double m=sqrt(n);
	flag[0]=flag[1]=1;
	for(i=4;i<=n;i+=2)
		flag[i]=1;
	a[0]=2;
	c=1;
	for(i=3;i<=n;i+=2)
	{
		if(flag[i]==0)
		{
			a[c++]=i;
			if(m>=i)
			{
				r=i+i;
				for(j=i*i;j<=n;j+=r)
					flag[j]=1;
			}
		}
	}
}
void almost()
{
	long i,j;
	 double x;
	for(i=0;i<c;i++)
	{
		for(j=2;;j++)
		{
			x=pow(a[i],j);
			if(x>=1000000000000)
				break;
			al[d++]=(double)x;
		}
		if(j==2)
			break;
	}
	qsort(al,d,sizeof(double),cmp);
}
int main()
{
	sieve(1000000);
	almost();
	 double n,low,high,cnt;
	 long i;
	scanf("%lf",&n);
	while(n--)
	{
		cnt=0;
		scanf("%lf %lf",&low,&high);
		for(i=0;i<d&&al[i]<=high;i++)
			if(al[i]>=low)
				cnt++;
		printf("%0.lf\n",cnt);
	}
	return 0;
}