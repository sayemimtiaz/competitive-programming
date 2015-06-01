#include<iostream.h>
int main()
{
	char a[100][100];
	int b[100][100],i,j,x,y;
	int row,col,h=1;
	while(1)
	{
		cin>>row>>col;
		if(row==0&&col==0)
			break;
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				cin>>a[i][j];
			}
		}
		for(i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				b[i][j]=0;
				if(a[i][j]=='.')
				{
						if(a[i][j-1]=='*'&&(j-1)>=0)
						{
							b[i][j]++;
						}
						if(a[i][j+1]=='*'&&(j+1)<col)
						{
								b[i][j]++;
						}
						if(a[i-1][j]=='*'&&(i-1)>=0)
						{
								b[i][j]++;
						}
						if(a[i-1][j+1]=='*'&&(i-1)>=0&&(j+1)<col)
						{
								b[i][j]++;
						}
						if(a[i-1][j-1]=='*'&&(i-1)>=0&&(j-1)>=0)
						{
								b[i][j]++;
						}
						if(a[i+1][j]=='*'&&(i+1)<row)
						{
								b[i][j]++;
						}
						if(a[i+1][j+1]=='*'&&(i+1)<row&&(j+1)<col)
						{
								b[i][j]++;
						}
						if(a[i+1][j-1]=='*'&&(i+1)<row&&(j-1)>=0)
						{
								b[i][j]++;
						}
				}
				else
					b[i][j]=-1;
			}
		}
		if(h!=1)
		cout<<endl;
		cout<<"Field #"<<h<<":\n";
		h++;
	
		for(i=0;i<row;i++)
		{
		
			for(j=0;j<col;j++)
			{
				if(b[i][j]==-1)
					cout<<"*";
				else
					cout<<b[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}