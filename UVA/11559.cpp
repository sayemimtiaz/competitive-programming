#include<stdio.h>
int main()
{
	bool f,f1,f2,count;
	long n,b,h,w,i,j,hl,a,min;
	while(scanf("%ld %ld %ld %ld",&n,&b,&h,&w)==4)
	{
		f=1;
		f2=0;
		for(i=0;i<h;i++)
		{
			f1=0;
			scanf("%ld",&hl);
			if((n*hl)<=b)
				f1=1;
			count=0;
			for(j=0;j<w;j++)
			{
				scanf("%ld",&a);
				if(f1)
				{
					if(a>=n)
						count=1;
				}
			}
			if(f1&&count)
			{
				f2=1;
				a=n*hl;
				if(f)
				{
					f=0;
					min=a;
				}
				else if(a<min)
					min=a;
			}
		}
		if(f2)
			printf("%ld",min);
		else
			printf("stay home");
		printf("\n");

	}
	return 0;
}