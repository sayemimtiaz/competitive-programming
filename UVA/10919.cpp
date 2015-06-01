#include<iostream.h>
#include<string.h>
char s[1000][100];
int main()
{
	char t[10000];
	long a,b,c,d,i,j,count,k,complete;
	while(1)
	{
	
		cin>>a;
		if(!a)
			break;
		cin>>b;
		for(i=0;i<a;i++)
			cin>>s[i];
		complete=0;
		long im =0;
		for(i=0;i<b;i++)
		{
			count=0;
			cin>>c>>d;
			im+=d;
			for(j=0;j<c;j++)
			{
		
				cin>>t;
				if(count!=d)
				{
				for(k=0;k<a;k++)
				{
					if(strcmp(t,s[k])==0)
					{
						count++;
						break;
					}
				}
				}
			}
			if(count==d)
			{
				complete+=count;
			}
		}
		if(complete==im)
			cout<<"yes";
	else
			cout<<"no";
		cout<<endl;
	}
	return 0;
}