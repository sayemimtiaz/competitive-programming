#include<stdio.h>
long d[50],v[50],s[1200][1200],p[1200][1200],cnt,e[50];
void print(long i,long j)
{
	if(i==0||j==0)
		return;
	if(s[i][j]=='1')
	{
		print(i-1,j-d[i]);
		printf("%ld %ld\n",e[i],v[i]);
	}
	else
		print(i-1,j);
}
void count(long i,long j)
{
	if(i==0||j==0)
		return;
	if(s[i][j]=='1')
	{
		count(i-1,j-d[i]);
		cnt++;
	}
	else
		count(i-1,j);
}
int main()
{
	bool flag=0;
	long t,w,w1,w2,n,i,j;
	while(scanf("%ld %ld",&t,&w)==2)
	{
		scanf("%ld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%ld %ld",&d[i],&v[i]);
			e[i]=d[i];
			d[i]=d[i]*w+2*d[i]*w;
		}
		for(i=0;i<=t;i++)
			p[0][i]=0;
		for(i=1;i<=n;i++)
			p[i][0]=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=t;j++)
			{
				w1=p[i-1][j];
			    w2=(d[i]<=j)?v[i]+p[i-1][j-d[i]]:0;
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
		if(flag)
			printf("\n");
		flag=1;
		printf("%ld\n",p[n][t]);
		cnt=0;
		count(n,t);
		printf("%ld\n",cnt);
		print(n,t);
	}
	return 0;
}
