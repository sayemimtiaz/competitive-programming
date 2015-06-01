#include<stdio.h>
#include<string.h>
	int path[120][120],q[120][120];

		
int main()
{
	
		int b,a,i,c[500],j,w,node,count;
	while(1)
	{
		scanf("%d",&node);
		if(node==0)
			break;
      memset(path,0,sizeof(path));
	  while(1)
		{
			scanf("%d",&b);
			if(b==0)
				break;
			while(1)
			{
				scanf("%d",&a);
				if(a==0)
					break;
				path[b-1][a-1]=1;
			}
		}
	for(i=0;i<node;i++)
	{
		for(j=0;j<node;j++)
		{
			if(path[i][j]==0)
				q[i][j]=20000;
			else
				q[i][j]=path[i][j];
		}
	}
	for(i=0;i<node;i++)
	{
		for(j=0;j<node;j++)
		{
			for(w=0;w<node;w++)
			{
				if(q[j][w]>(q[j][i]+q[i][w]))
						q[j][w]=q[j][i]+q[i][w];
			}
		
		}
	}

			scanf("%d",&a);
		for(i=0;i<a;i++)
			scanf("%d",&c[i]);
		for(i=0;i<a;i++)
		{
			count=0;
			for(j=0;j<node;j++)
				if(q[c[i]-1][j]>=20000)
					count++;
			printf("%d",count);	
			for(j=0;j<node;j++)
				if(q[c[i]-1][j]>=20000)
					printf(" %d",j+1);
					printf("\n");
		}
	

	}
	return 0;
}
