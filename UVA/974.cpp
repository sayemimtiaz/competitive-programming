#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
long s[1000000]={0};
void precal()
{
	long i,j,k,a,c,d;
	char b[10000],e[10000],f[10000],g[10000];
	for(i=9;i<=40000;i++)
	{
		bool yes=0;
		a=i*i;
		j=0;
		while(a)
		{
			e[j++]=a%10+'0';
			a/=10;
		}
		for(k=j-1;k>=0;k--)
			b[j-1-k]=e[k];
		b[j]='\0';
		a=0;
		while(a<j)
		{
		f[a]=b[a];
		f[a+1]='\0';
		c=atol(f);
		strcpy(g,&b[a+1]);
		d=atol(g);
		if(c+d==i&&c>0&&d>0)
		{
			yes=1;
			s[i]=i;
		}
		a++;
		if(yes)
			break;
		}
	}
}
int main()
{
	bool yes;
	long i,j,kas,a,b;
	precal();
	scanf("%ld",&kas);
	for(i=1;i<=kas;i++)
	{
		yes=0;
		scanf("%ld %ld",&a,&b);
		if(i!=1)
			printf("\n");
		printf("case #%ld\n",i);
		for(j=a;j<=b;j++)
			if(s[j])
			{
				yes=1;
				printf("%ld\n",j);
			}
		if(!yes)
			printf("no kaprekar numbers\n");

	}
	return 0;
}
