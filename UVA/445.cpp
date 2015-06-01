#include<stdio.h>
#include<iostream.h>
int main()
{
	char ch;
	int sum=0,i;
	while((ch=getchar())!=EOF)
	{
		if(ch>='0'&&ch<='9')
		{
			sum+=(ch-'0');
			continue;
		}
		else if(ch=='!'||ch=='\n')
			cout<<endl;
		else
		{
			for(i=0;i<sum;i++)
			{
				if(ch=='b')
					cout<<" ";
				else
					cout<<ch;
			}
		}
		sum=0;
	}
	return 0;
}