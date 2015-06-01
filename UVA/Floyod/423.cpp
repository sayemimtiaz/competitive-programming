#include<stdio.h>	
#include<string.h>
#include<stdlib.h>
 long path[101][101];
 long q[101][101];
int main()
{

	long num_node,w,a,b,max;
	char im[1000];

	while(scanf("%ld",&num_node)==1)
	{
		memset(path,0,sizeof(path));
		for(a=1;a<num_node;a++)
		{
			for(b=0;b<a;b++)
			{
			    scanf("%s",im);
			    w=atol(im);
		       	path[a][b]=w;
				path[b][a]=w;
			}
		}
	for(a=0;a<num_node;a++)
	{
		for(b=0;b<num_node;b++)
		{

			if(path[a][b]==0)
				q[a][b]=200000;
			else
				q[a][b]=path[a][b];
		}
	}
	for(a=0;a<num_node;a++)
	{
		for(b=0;b<num_node;b++)
		{
			for(w=0;w<num_node;w++)
			{
				if(q[b][w]>(q[b][a]+q[a][w]))
						q[b][w]=q[b][a]+q[a][w];
			}
		
		}
	}
	w=1;
		for(a=1;a<num_node;a++)
		{
				if(q[0][a]<200000)
				{
				if(w)
				{
					w=0;
					max=q[0][a];
				}
				else if(max<q[0][a])
					max=q[0][a];
				}
		}
		printf("%ld\n",max);
	}
		return 0;
	}



