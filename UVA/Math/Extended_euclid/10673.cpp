#include<stdio.h>
#include<math.h>
 long long x,y;
void ex_eu(long long a,long long b)
{
	long x1;
	if(b>a)
	{
		x1=a;
		a=b;
		b=x1;
	}
      if (b==0)
	  {
		   x=1;
		   y=0;
        return ;
	  }
	    ex_eu(b, a %b);
        x1=x-y*(a / b);
		x=y;
		y=x1;
}
int main()
{
	long double a,b;
	 long long n,c,d,e,f;
	scanf("%lld",&n);
	while(n--)
	{
	scanf("%lld %lld",&c,&d);
		if(c%d==0)
		{
					printf("0 %lld\n",d);
		}
		else
		{
			bool yes=0;
		a=floorl(c/(long double)d);
		b=ceill(c/(long double)d);
		e=(long)a;
		f=(long)b;
		ex_eu(e,f);
		if(x<0)
			x=-x;
		if(y<0)
			y=-y;
		  if(x*a+y*b==1)
			yes=1;
		  else if(-x*a+y*b==1)
		  {
			  yes=1;
			  x=-x;
		  }
		  else if(x*a+(-y)*b==1)
		  {
			  yes=1;
			  y=-y;
		  }
		  else if(-x*a+(-y)*b==1)
		  {
			  yes=1;
			  x=-x;
			  y=-y;
		  }
		  if(!yes)
		  {
			  e=x;
			  x=y;
			  y=e;
			if(x*a+y*b==1);
		  else if(-x*a+y*b==1)
		  {
			  x=-x;
		  }
		  else if(x*a+(-y)*b==1)
		  {
			  y=-y;
		  }
		  else if(-x*a+(-y)*b==1)
		  {
			  x=-x;
			  y=-y;
		  }
		  }

			printf("%lld %lld\n",c*x,c*y);
		}
	}
	return 0;
}