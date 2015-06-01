#include<stdio.h>
#include<string.h>
#include<iostream.h>
char str[1000002];
bool yes;
int main()
{
	char a;
	long i,j,min,max,n,m,h=1,p;
	while(cin>>str)
	{
		if(strlen(str)==0)
			break;
		scanf("%ld",&p);
		for(i=0;i<p;i++)
		{
		
			scanf("%ld %ld",&m,&n);
			min=(m<n)?m:n;
			max=(m>n)?m:n;
			a=str[min];
			yes=1;
			for(j=min+1;j<=max;j++)
			{
				if(str[j]!=a)
				{
					yes=0;
					break;
				}
				else
					a=str[j];
			}
			if(i==0)
			{
			printf("Case %ld:",h);
			cout<<endl;
		    h++;
			}
			if(yes==1)
			printf("Yes");
			else
				printf("No");
			cout<<endl;
			}
		
	}
	return 0;
}

