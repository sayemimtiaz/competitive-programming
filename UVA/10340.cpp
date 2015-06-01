#include<iostream.h>
#include<string.h>
char s[1000000],t[1000000];
int main()
{
	long i,j,l1,l2,cnt;
	while(cin>>s>>t)
	{
		l1=strlen(s);
		l2=strlen(t);
		j=cnt=0;
		for(i=0;i<l1;i++)
		{
			for(;j<l2;j++)
				if(s[i]==t[j])
				{
					cnt++;
					break;
				}
			j++;
		}
		if(cnt==l1)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}