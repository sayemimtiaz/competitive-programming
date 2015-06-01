#include<stdio.h>
#define MAXN 30
int c[MAXN][MAXN];
int s1[MAXN],s2[MAXN],N;
void lcs()
{
	int i,j;
	for(i=0;i<=N;i++)
		c[i][0]=0;
	for(i=0;i<=N;i++)
		c[0][i]=0;
	for(i=1;i<=N;i++)
		for(j=1;j<=N;j++)
		{
			if(s1[i]==s2[j])
				c[i][j]=c[i-1][j-1]+1;
			else if(c[i-1][j]>=c[i][j-1])
				c[i][j]=c[i-1][j];
			else
                c[i][j]=c[i][j-1];
		}
	printf("%d\n",c[N][N]);
}
int main()
{
    int i,t;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
	{
	 scanf("%d",&t);
	 s1[t]=i;
    }
    while(~scanf("%d",&t))
    {
      s2[t]=1;
      for(i=2;i<=N;i++)
      {
	   scanf("%d",&t);
	   s2[t]=i;
      }
	   lcs();
    }
	return 0;
}
