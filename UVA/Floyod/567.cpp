#include<stdio.h>
#include<string.h>
int path[200][200],q[200][200],s[10000],d[20000];
int main()
{
	int a,b,w,n,f,h;
	h=1;
	while(scanf("%d",&n)==1)
	{
		memset(path,0,sizeof(path));
		b=0;
		while(1)
		{
			if(b==19)
				break;
			if(b)
					scanf("%d",&n);
		for(a=0;a<n;a++)
		{
			scanf("%d",&f);
			path[b][f-1]=1;
			path[f-1][b]=1;
		}
		b++;
	
		}
	
	for(a=0;a<20;a++)
	{
		for(b=0;b<20;b++)
		{
			if(path[a][b]==0)
				q[a][b]=30000;
			else
				q[a][b]=1;
		}
	}
	for(a=0;a<20;a++)
	{
		for(b=0;b<20;b++)
		{
			for(w=0;w<20;w++)
			{
				if(q[b][w]>(q[b][a]+q[a][w]))
						q[b][w]=q[b][a]+q[a][w];
			}
		
		}
	}
	scanf("%d",&n);
	for(w=0;w<n;w++)
	{
		scanf("%d %d",&s[w],&d[w]);	
		
	}
	
	printf("Test Set #%d\n",h++);
	for(w=0;w<n;w++)
	{
		printf("%2d to %2d: %d\n",s[w],d[w],q[s[w]-1][d[w]-1]);
	}
			printf("\n");
	}
		return 0;
	}



