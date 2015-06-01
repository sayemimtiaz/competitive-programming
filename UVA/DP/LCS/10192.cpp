#include<stdio.h>
#include<string.h>
int c[1000][1000],b[1000][1000];
char s1[10000],s2[10000];
long  lcs()
{
	int m,n,i,j;
	m=strlen(s1);
	n=strlen(s2);
	for(i=0;i<=m;i++)
		c[i][0]=0;
	for(i=0;i<=n;i++)
		c[0][i]=0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(s1[i-1]==s2[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;

			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
			}
			else
			{
                c[i][j]=c[i][j-1];
			}
		}
	}
	return c[m][n];
}

int main()
{
	long r,kas=1;
	while(1)
	{
		gets(s1);
		if(s1[0]=='#')
			break;
		gets(s2);
	    r=lcs();
		printf("Case #%ld: you can visit at most %ld cities.\n",kas++,r);
	}
	return 0;
}
