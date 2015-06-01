#include<stdio.h>
int main()
{
	int i,j,add,a,b,max,w;
	double f;
	j=1;
	while(1)
	{
			int q[120][120]={0};
				int path[120][120]={0};
		for(i=0;;i++)
		{
			scanf("%d %d",&a,&b);
			path[a-1][b-1]=1;
			a=(a>b)?a:b;
			if(i==0)
			{
				max=a;	
			}
			else if(a>max)
				max=a;

			if(a==0&&b==0)
				break;
		}
		if(a==0&&b==0&&i==0)
			break;
	
	
	for(a=0;a<max;a++)
	{
		for(b=0;b<max;b++)
		{
			if(path[a][b]==0)
				q[a][b]=30000;
			else
				q[a][b]=path[a][b];
		}
	}
	for(a=0;a<max;a++)
	{
		for(b=0;b<max;b++)
		{
			for(w=0;w<max;w++)
			{
				if(q[b][w]>(q[b][a]+q[a][w]))
						q[b][w]=q[b][a]+q[a][w];
			}
		
		}
	}
	add=0;
	i=0;
	for(a=0;a<max;a++)
		{
			for(b=0;b<max;b++)
			{
				if(a!=b&&q[a][b]!=30000)
				{
					i++;
				add+=q[a][b];
				}
			}
		}
	f=add/(double)i;
	printf("Case %d: average length between pages = %0.3lf clicks\n",j++,f);
	}
		return 0;
	}



