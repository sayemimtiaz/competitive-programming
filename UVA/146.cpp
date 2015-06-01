#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	char str[1000], c[1000];
	long len,i,f,count;
	while(gets(str))
	{
		if(strcmp("#",str)==0)
			break;
		strcpy(c,str);
		len=strlen(str);
		next_permutation(str,str+len);
		f=0;
		count=0;
		for(i=0;i<len;i++)
			if(str[i]<c[i])
			{
				f=1;
				break;
			}
			else if(str[i]>c[i])
			{
				f=0;
				break;
			}
			else
				count++;
			if(count==len)
				f=1;
		if(f)
			cout<<"No Successor"<<endl;
		else
		cout<<str<<endl;
	}
	return 0;
}