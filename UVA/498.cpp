#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	char a[10000],b[10000],ch,c[10000];
	long flag,i,x[20000],j,k,l,l1,l2,e,y[10000],t;
	while(gets(a))
	{
		gets(b);
		l1=strlen(a);
		l2=strlen(b);
		j=0;
		k=0;
		for(i=0;i<=l1;i++)
		{
			if(a[i]=='\0'||a[i]==' ')
			{
				c[j]='\0';
				x[k]=atol(c);
				k++;
				j=0;
			}
			else
			{
				c[j]=a[i];
				j++;
			}
		}
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
		for(i=0;i<l;i++)
		{
			e=0;
			t=0;
			for(j=k-1;j>=0;j--)
			{
				e=e+(pow(y[i],j))*x[t];
				t++;
			}
			if(i<l-1)
			printf("%ld ",e);
		}
		printf("\n");
	}
	return 0;
}
			
