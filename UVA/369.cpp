#include<stdio.h>
#include<math.h>
int main()
{
	long double n,m,c,i,f1,f2,f3;
	while(1)
	{
		scanf("%Lf %Lf",&n,&m);
		if(n==0&&m==0)
			break;
		if(n==m)
           printf("%0.Lf things taken %0.Lf at a time is 1 exactly.",n,m);
		else
		{
			f1=1;
			for(i=1;i<=n;i++)
				f1=i*f1;
			c=n-m;
			f2=1;
			for(i=1;i<=c;i++)
				f2=f2*i;
			f3=1;
			for(i=1;i<=m;i++)
				f3=f3*i;
			f3=f3*f2;
			c=f1/f3;
			  printf("%0.Lf things taken %0.Lf at a time is %0.Lf exactly.",n,m,c);
		}
		printf("\n");
	}
	return 0;
}

