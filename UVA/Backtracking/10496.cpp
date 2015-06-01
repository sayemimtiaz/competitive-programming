#include<stdio.h>
#include<string.h>
int x[]={0,0,-1,1};
int y[]={-1,1,0,0};
bool vis[100][100],rak[100][100],p[100][100];
long min,si,sj,pi,pj,ei,ej;
long  row,col,beep;
bool flag;
void check(long i,long j,long green,long cost)
{
	long a,c,d;
	if(cost>=min)
		return;
	if(!flag)
	{
	if(green==beep)
	{ 
		if(min>cost)
		{
			ei=i;ej=j;
			min=cost;
		}
		return;
	}
	}
	else if(flag)
	{
		if(si==i&&sj==j)
	{ 
		if(min>cost)
		{
			min=cost;
		}
		return;
	}
	}
	for(a=0;a<4;a++)
	{
		c=i+x[a];
		d=j+y[a];
		if(c<=row&&d<=col&&c>0&&d>0&&!vis[c][d])
		{
			vis[c][d]=1;
			if(!flag)
			{
			if(rak[c][d])
			  check(c,d,green+1,cost+1);
			else
				check(c,d,green,cost+1);
			}
			else
				check(c,d,green,cost+1);
			vis[c][d]=0;
		}

	}

}
int main()
{
	long i,a,b,test;
	scanf("%ld",&test);
	while(test--)
	{
    	scanf("%ld %ld",&row,&col);
		memset(vis,0,sizeof(vis));
		memset(rak,0,sizeof(rak));
		scanf("%ld %ld",&si,&sj);
		min=10000000;
		scanf("%ld",&beep);
		for(i=0;i<beep;i++)
		{
			scanf("%ld %ld",&a,&b);
			rak[a][b]=1;
		}
		if(beep==0||(beep==1&&si==a&&sj==b))
		{min=0;a=0;}
		else
		{
		flag=0;
		vis[si][sj]=1;
		check(si,sj,0,0);
		a=min;
		min=100000000;
		flag=1;
		memset(vis,0,sizeof(vis));
		vis[ei][ej]=1;
		check(ei,ej,0,0);
		}
	printf("The shortest path has length %ld\n",min+a);
	}
	return 0;
}