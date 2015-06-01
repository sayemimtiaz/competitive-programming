#include<stdio.h>
#include<string.h>
#define UP 1
#define SIDE 2
#define  CROSS 3
void print_lcs(int ,int);
int c[1000][1000],b[1000][1000];
char s1[10000],s2[10000];
void lcs()
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
				b[i][j]=CROSS;

			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=UP;
			}
			else
			{
                c[i][j]=c[i][j-1];
				b[i][j]=SIDE;
			}
		}
	}
	printf("%d\n",c[m][n]);
	print_lcs(m,n);
	printf("\n");
}
void print_lcs(int i,int j)
{
	if(i==0||j==0)
		return;
	if(b[i][j]==CROSS)
	{
		print_lcs(i-1,j-1);
		printf("%c",s1[i-1]);
	}
	else if(b[i][j]==UP)
	{
		print_lcs(i-1,j);
	}
	else
		print_lcs(i,j-1);
}
int main()
{
	scanf("%s %s",s1,s2);
	lcs();
	return 0;
}
