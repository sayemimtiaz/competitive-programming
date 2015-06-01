#include<stdio.h>
#include<string.h>
bool con[100][100];
long n;
bool issqr(long size,long x,long y)
{
	long v1,v2,i,vy,vx;
	v1=n*x+y;
	for(i=1;i<=size;i++)
	{
		v2=v1+1;
		vy=v2-n*x;
		if(vy>=n||!con[v1][v2])
			return 0;
		v1=v2;
	}
	for(i=1;i<=size;i++)
	{
		v2=v1+n;
		vx=(v2-vy)/n;
		if(vx>=n||!con[v1][v2])
			return 0;
		v1=v2;
	}
	for(i=1;i<=size;i++)
	{
		v2=v1-1;
		vy=v2-n*vx;
		if(v2<0||!con[v1][v2])
			return 0;
		v1=v2;
	}
	for(i=1;i<=size;i++)
	{
		v2=v1-n;
		vx=(v2-vy)/n;
		if(vx<0||!con[v1][v2])
			return 0;
		v1=v2;
	}
	return 1;
}
int main()
{
	long inter,i,a,b,v1,v2,j,k,cnt,kas=1;
	char ch;
	bool flag=0;
	while(scanf("%ld",&n)==1)
	{
		scanf("%ld",&inter);
		memset(con,0,sizeof(con));
		for(i=0;i<inter;i++)
		{
			getchar();
			scanf("%c %ld %ld",&ch,&a,&b);
			a--;b--;
			if(ch=='H')
			{
				v1=n*a+b;v2=v1+1;
				con[v1][v2]=con[v2][v1]=1;
			}
			else 
			{
				v1=n*b+a;v2=v1+n;
				con[v1][v2]=con[v2][v1]=1;
			}
		}
		if(flag)
			printf("\n**********************************\n\n");
		flag=1;
		bool got=0;
		printf("Problem #%ld\n\n",kas++);
		for(i=1;i<=n;i++)
		{
			cnt=0;
			for(j=0;j<n;j++)
				for(k=0;k<n;k++)
					if(issqr(i,j,k))
						cnt++;
			if(cnt)
			{
				got=1;
				printf("%ld square (s) of size %ld\n",cnt,i);
			}
		}
		if(!got)
			printf("No completed squares can be found.\n");
	}
	return 0;
}