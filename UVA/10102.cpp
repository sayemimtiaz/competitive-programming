#include<iostream.h>
#include<stdlib.h>
char grid[200][200];
int main()
{
	long i,j,k,l,min,max,cost,n;
	while(cin>>n)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>grid[i][j];
			}
		}
		max=-1000000;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				min=1000000000;
				if(grid[i][j]=='1')
				{
					for(k=0;k<n;k++)
					{
						for(l=0;l<n;l++)
						{
							if(grid[k][l]=='3')
							{
								cost=abs(i-k)+abs(j-l);
						    	if(min>cost)
								min=cost;
							}
						}
					}
					if(max<min)
						max=min;
				}
			}
		}
	cout<<max<<endl;

	}
	return 0;
}