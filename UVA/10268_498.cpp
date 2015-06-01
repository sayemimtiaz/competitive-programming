#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
	char a[100000],b[100000],c[100000];
	long i,x,j,l,y[100000],t,l2;
	long double e;
int main()
{

	while(gets(a))
	{
		gets(b);
		l2=strlen(b);
		x=atol(a);
		j=0;
		l=0;
		for(i=0;i<=l2;i++)
		{
			if(b[i]=='\0'||b[i]==' ')
			{
				c[j]='\0';
				y[l]=atol(c);
				l++;
				j=0;
			}
			else
			{
				c[j]=b[i];
				j++;
			}
		}
		e=0;
		t=l-1;
		for(i=0;i<l-1;i++)
		{
			e=e+(y[i]*t*(pow(x,t-1)));
			t--;
		}
		printf("%0.Lf\n",e);
	}
	return 0;
}
			
