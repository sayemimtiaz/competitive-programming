
#include<ctype.h>
#include<string.h>
#include<stdio.h>
int main()
{
	char a[100];
	int s1,s2;
	int i,len,b;
	double r;
	while(gets(a))
	{
		len=strlen(a);
		s1=0;
		for(i=0;i<len;i++)
		{
			a[i]=toupper(a[i]);
			if(a[i]>='A'&&a[i]<='Z')
			{
				s1+=(a[i]-64);
				while((b=s1/10))
				{
				s1=s1%10;
				s1+=b;
				}
			}
		}
		gets(a);
		s2=0;
		len=strlen(a);
		for(i=0;i<len;i++)
		{
			a[i]=toupper(a[i]);
			if(a[i]>='A'&&a[i]<='Z')
			{
				s2+=(a[i]-64);
				while((b=s2/10))
				{
				s2=s2%10;
				s2+=b;
				}
			}
		}
		if(s1==0||s2==0)
			printf("0.00 %%\n");
		else
		{
		if(s1>s2)
		r=s2/(double)s1;
		else
			r=s1/(double)s2;
		r*=100;
		printf("%0.2lf %%\n",r);
		}
	}
	return 0;
}

