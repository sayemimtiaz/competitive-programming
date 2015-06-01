#include<iostream.h>
#include<string.h>
int main()
{
	int i,j,r,c,e,a,b,loop,count,step[30][30];
	bool flag,vis[30][30];
	char grid[30][30],s[30];
	char symbol[4]={'N','E','S','W'};
	int x[4]={-1,0,1,0};
	int y[4]={0,1,0,-1};
	while(1)
	{
		cin>>r>>c>>e;
		if(!r&&!c&&!e)
			break;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				cin>>grid[i][j];
			}
		}
		a=0;
		b=e-1;
		count=0;
		flag=0;
		memset(vis,0,sizeof(vis));
		while(1)
		{
			if(a<0||a>=r||b<0||b>=c)
			{
				cout<<count<<" step(s) to exit";
				break;
			}
			
			if(vis[a][b])
			{
				loop=1+count-step[a][b];
				count-=loop;
				cout<<count<<" step(s) before a loop of "<<loop<<" step(s)";
				break;
			}
			count++;
			step[a][b]=count;
			vis[a][b]=1;
			for(i=0;i<4;i++)
				if(symbol[i]==grid[a][b])
					break;
			a=a+x[i];
			b=b+y[i];
		}
		cout<<endl;

	}
	return 0;
}