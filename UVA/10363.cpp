#include<iostream.h>
#include<stdio.h>
int main()
{
	long kase,d,x,y,i,j,k,x1,y1,s1,s2;
	char ch[10][10],line[100];
	cin>>kase;
	for(k=0;k<kase;k++)
	{
		x=y=0;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				cin>>ch[i][j];
				if(ch[i][j]=='X')
					x++;
				else if(ch[i][j]=='O')
					y++;
			}
		}
		s1=x;s2=y;
		d=x-y;
		if(d==0||d==1)
		{
			bool flag1=0,flag2=0;
			for(i=0;i<3;i++)
			{
				x=y=x1=y1=0;
				for(j=0;j<3;j++)
				{
					if(ch[i][j]=='X')
						x++;
					else if(ch[i][j]=='O')
						y++;
					if(ch[j][i]=='X')
						x1++;
					else if(ch[j][i]=='O')
						y1++;
				}
				if(x==3||x1==3)
				{
					flag1=1;	
				}
				else if(y==3||y1==3)
				{
					flag2=1;
				}
			}
				if(ch[0][0]==ch[1][1]&&ch[1][1]==ch[2][2]&&ch[0][0]=='X')
				{
					flag1=1;
				}
				else if(ch[0][0]==ch[1][1]&&ch[1][1]==ch[2][2]&&ch[0][0]=='O')
				{
					flag2=1;
				}
				 if(ch[0][2]==ch[1][1]&&ch[1][1]==ch[2][0]&&ch[0][2]=='X')
				{
					flag1=1;
				}
				else if(ch[0][2]==ch[1][1]&&ch[1][1]==ch[2][0]&&ch[0][2]=='O')
				{
					flag2=1;
				}
			if(!flag1&&!flag2)
				cout<<"yes";
			else if(flag1&&flag2)
				cout<<"no";
			else if(flag1)
			{
				if(s1==s2+1)
					cout<<"yes";
				else 
					cout<<"no";
			}
			else if(flag2)
			{
				if(s1==s2)
					cout<<"yes";
				else 
					cout<<"no";
			}
		}
		else
		cout<<"no";
		cout<<endl;
	}
	return 0;
}