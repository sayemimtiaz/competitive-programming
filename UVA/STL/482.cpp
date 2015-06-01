#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>
#include<cstdlib>
using namespace std;
struct e
{
    long ori;
    string to;
} b[10000];
long m;
char ch[1000000],s[1000000];
bool cmp (e x, e y)
{
    if ( x.ori < y.ori ) return true;
    return false;
}
void separate(char *a,bool id)
{
	m=0;
	long i,len,j=0;
	len=strlen(a);
	for(i=0;i<=len;i++)
	{
		if(a[i]==' '||a[i]=='\0')
		{
			ch[j]='\0';
			if(j!=0)
			{
			if(id)
			{
			   b[m++].ori=atol(ch);
			}
			else
				b[m++].to=ch;
			}
			j=0;
		}
		else
			ch[j++]=a[i];
	}
}
int main()
{
	bool flag=0;
	long i,kase,j;
	scanf("%ld",&kase);
    getchar();
	while(kase--)
	{
		gets(s);
		gets(s);
		separate(s,1);
		gets(s);
		separate(s,0);
		 sort (b, b + m, cmp);

		if(flag)
			printf("\n");
		flag=1;
		for(i=0;i<m;i++)
			cout<<b[i].to<<endl;
		
	}
	return 0;
}




