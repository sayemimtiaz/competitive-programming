#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
char line[100000];
int main()
{
	double tot;
	long kase,n,j,m,val[200],loc,len,k,i;
	char ch[200],c;
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%ld",&n);;
		for(j=0;j<n;j++)
		{
			getchar();
			scanf("%c %ld",&ch[j],&val[j]);
		}
		scanf("%ld",&m);
		getchar();
		tot=0.00;
		for(j=0;j<m;j++)
		{
			i=0;
		   while(c=getchar())
		   {
			   if(c=='\n')
				   break;
			   line[i++]=c;
		   }
		   vector<char>v(line,line+i);
		    pair<vector<char>::iterator,vector<char>::iterator> bounds;

		   sort(v.begin(),v.end());
		   for(k=0;k<n;k++)
		   {
			   bounds=equal_range(v.begin(),v.end(),ch[k]);
			   tot+=((long)(bounds.second-v.begin())-(long)(bounds.first-v.begin()))*val[k];
		   }
		}
			printf("%0.2lf$\n",(tot/100));
	}
	return 0;
}