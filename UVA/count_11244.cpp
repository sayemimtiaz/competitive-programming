#include<iostream.h>
char a[1000][100];
int main()
{
	int i,j,count,flag;
	int row,col;
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
		count=0;
		for(i=0;i<row;i++)
		{
	
			for(j=0;j<col;j++)
			{
					flag=0;	
				if(a[i][j]=='*')
				{
						if(a[i][j-1]=='*'&&(j-1)>=0)
						{
							flag=1;
						}
						if(a[i][j+1]=='*'&&(j+1)<col)
						{
							flag=1;
						}
						if(a[i-1][j]=='*'&&(i-1)>=0)
						{
							flag=1;
						}
						if(a[i-1][j+1]=='*'&&(i-1)>=0&&(j+1)<col)
						{
							flag=1;
						}
						if(a[i-1][j-1]=='*'&&(i-1)>=0&&(j-1)>=0)
						{
							flag=1;
						}
						if(a[i+1][j]=='*'&&(i+1)<row)
						{
							flag=1;
						}
						if(a[i+1][j+1]=='*'&&(i+1)<row&&(j+1)<col)
						{
							flag=1;
						}
						if(a[i+1][j-1]=='*'&&(i+1)<row&&(j-1)>=0)
						{
							flag=1;
						}
				if(flag==0)
				{
				    count++;
				}
				}
			}
		
		}
		cout<<count<<endl;
	}
	return 0;
}