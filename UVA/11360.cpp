
#include<iostream.h>
int main()
{
	char ins[10],a[50][50],copy[500],ch[50][50];
	int z,kase,m,size,k,x,y,i,j;
	k=1;
	cin>>kase;
	while(kase--)
	{
		cin>>size;
		for(i=0;i<size;i++)
			for(j=0;j<size;j++)
			{
				cin>>a[i][j];
				ch[i][j]=a[i][j];
			}
		cin>>m;
		while(m--)
		{
			cin>>ins;
			switch(*ins)
			{
			case 'r':
				cin>>x>>y;
				for(i=0;i<size;i++)
					copy[i]=a[x-1][i];
				for(i=0;i<size;i++)
					a[x-1][i]=a[y-1][i];
				for(i=0;i<size;i++)
					a[y-1][i]=copy[i];
				break;
			case 'c':
				cin>>x>>y;
				for(i=0;i<size;i++)
					copy[i]=a[i][x-1];
				for(i=0;i<size;i++)
					a[i][x-1]=a[i][y-1];
				for(i=0;i<size;i++)
					a[i][y-1]=copy[i];
				break;
			case 'i':
				for(i=0;i<size;i++)
					for(j=0;j<size;j++)
					{
						z=(a[i][j]-'0')+1;
						if(z==10)
						z=0;
						a[i][j]=z+'0';
					}
				break;
			case 'd':
					for(i=0;i<size;i++)
					for(j=0;j<size;j++)
					{
						z=(a[i][j]-'0')-1;
						if(z==-1)
							z=9;
						a[i][j]=z+'0';
					}
				break;
			case 't':
		;			for(i=0;i<size;i++)
					for(j=0;j<size;j++)
						ch[i][j]=a[i][j];
				for(i=0;i<size;i++)
					for(j=0;j<size;j++)
						a[i][j]=ch[j][i];
			
				break;
			}
		}
		
		cout<<"Case #"<<k<<"\n";				
		k++;
		for(i=0;i<size;i++)
		{
			for(j=0;j<size;j++)
				cout<<a[i][j];
			cout<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}
