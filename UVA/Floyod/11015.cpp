#include<stdio.h>
#include<string.h>	
 long path[100][100];
 long q[100][100];
int main()
{
	char name[100][100];
	long a,b,w,kase=1,i,m,n,sum,c;

	while(1)
	{
		scanf("%ld %ld",&n,&m);
		if(!n)
			break;
		for(a=0;a<n;a++)
			scanf("%s",name[a]);
		memset(path,0,sizeof(path));
	for(a=0;a<m;a++)
	{
		scanf("%ld %ld %ld",&b,&c,&w);
		path[b-1][c-1]=path[c-1][b-1]=w;
	}
	for(a=0;a<n;a++)
		for(b=0;b<n;b++)
		{
			if(path[a][b]==0)
				q[a][b]=20000000;
			else
				q[a][b]=path[a][b];
		}
	for(a=0;a<n;a++)
	{
		for(b=0;b<n;b++)
		{
			for(w=0;w<n;w++)
			{
				if(q[b][w]>(q[b][a]+q[a][w]))
						q[b][w]=q[b][a]+q[a][w];
			}
		
		}
	}
		for(a=0;a<n;a++)
		{
			sum=0;
			for(b=0;b<n;b++)
			{
				if(a!=b&&q[a][b]<20000000)
					sum+=q[a][b];
			}
			if(a==0)
			{
				i=a;
				w=sum;
			}
			else if(w>sum)
			{
				i=a;
				w=sum;
			}
		}
		printf("Case #%ld : %s\n",kase++,name[i]);
	}
		return 0;
	}



