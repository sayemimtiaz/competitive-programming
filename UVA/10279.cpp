#include<iostream.h>
int main()
{
	char a[100][100],c[100][100];
	long b[100][100],i,j;
	long row,kase;
	bool h=0;
	bool fl=0;
	cin>>kase;
	while(kase--)
	{
		cin>>row;
		for(i=0;i<row;i++)
		{
			for(j=0;j<row;j++)
			{
				cin>>a[i][j];
			}
		}
		bool flag=0;
		for(i=0;i<row;i++)
		{
		   for(j=0;j<row;j++)
		   {
				cin>>c[i][j];
				if(c[i][j]=='x'&&a[i][j]=='*')
					flag=1;
		   }
		}
		for(i=0;i<row;i++)
		{
			for(j=0;j<row;j++)
			{
				b[i][j]=0;
				if(c[i][j]=='x')
				{
						if(a[i][j-1]=='*'&&(j-1)>=0)
						{
							b[i][j]++;
						}
						if(a[i][j+1]=='*'&&(j+1)<row)
						{
								b[i][j]++;
						}
						if(a[i-1][j]=='*'&&(i-1)>=0)
						{
								b[i][j]++;
						}
						if(a[i-1][j+1]=='*'&&(i-1)>=0&&(j+1)<row)
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
						if(a[i+1][j+1]=='*'&&(i+1)<row&&(j+1)<row)
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
				if(fl)
			cout<<endl;
		fl=1;
		if(flag)
		{
			for(i=0;i<row;i++)
			{
				for(j=0;j<row;j++)
				{
				if(a[i][j]=='*')
					cout<<'*';
				else if(c[i][j]=='x')
					cout<<b[i][j];
				else
					cout<<'.';
				}
			cout<<endl;
			}
		}
		else
		{
		for(i=0;i<row;i++)
		{
		
			for(j=0;j<row;j++)
			{
				 if(c[i][j]=='x')
					cout<<b[i][j];
				else
					cout<<'.';
			}
			cout<<endl;
		}
		}
	}
	return 0;
}