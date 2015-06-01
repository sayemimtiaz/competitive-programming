#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
long h[1000000],d=0;
int cmp(const void *a,const void *b)
{
	long *x=(long*)a;
	long *y=(long*)b;
	return *x-*y;
}
void humble()
{
	long i,j,k,l;
	long double x;
	for(i=0;i<31;i++)
	{
		for(j=0;j<20;j++)
		{
			for(k=0;k<14;k++)
			{
				for(l=0;l<12;l++)
				{
					x=pow(2,i)*pow(3,j)*pow(5,k)*pow(7,l);
					if(x>2000000000)
						break;
					h[d++]=(long)x;
				}
			}
					
		}

	}
	qsort(h,d,sizeof(long),cmp);
}
int main()
{
	humble();
	 long n;
	char suffix[100];
	while(scanf("%ld",&n)==1&&n)
	{
		if(n%100==11||n%100==12||n%100==13)
			strcpy(suffix,"th");
		else if(n%10==1)
			strcpy(suffix,"st");
		else if(n%10==2)
		  strcpy(suffix,"nd");
		else if(n%10==3)
			strcpy(suffix,"rd");
		else
			strcpy(suffix,"th");
		printf("The %ld%s humble number is %ld.\n",n,suffix,h[n-1]);
	}
	return 0;
}