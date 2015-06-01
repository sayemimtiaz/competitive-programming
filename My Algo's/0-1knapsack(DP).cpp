#include<stdio.h>
long w[2000],p[2000][2000],v[2000];
char s[2000][2000];
void print(long i,long j)
{
	if(i==0||j==0)
		return;
	if(s[i][j]=='1')
	{
		print(i-1,j-w[i]);
		printf("%ld %ld\n",w[i],v[i]);
	}
	else
		print(i-1,j);
}
int main()
{
	long n,i,j,k,w1,w2;
	scanf("%ld",&n);
	for(i=1;i<=n;i++)
		scanf("%ld %ld",&w[i],&v[i]);
	scanf("%ld",&k);
	for(i=0;i<=k;i++)
		p[0][i]=0;
	for(i=0;i<=n;i++)
		p[i][0]=0;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=k;j++)
		{   
		    w1=p[i-1][j];
			w2=(w[i]<=j)?v[i]+p[i-1][j-w[i]]:0;
			if(w1<w2)
			{
				p[i][j]=w2;
				s[i][j]='1';
			}
			else
			{
				p[i][j]=w1;
				s[i][j]='2';
			}
			
		}
	} 
	printf("%ld\n",p[n][k]);
	print(n,k);
	return 0;
}
