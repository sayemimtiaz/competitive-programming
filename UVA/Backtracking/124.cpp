#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool con[1000][1000],vis[1000];
char a[10000],b[1000];
long j;
void check(long how)
{
	long i,k;
	if(how==j)
	{
		for(i=0;i<j;i++)
			for(k=i+1;k<j;k++)
		      if(con[b[i]][b[k]])
				return;
		b[j]='\0';
		printf("%s\n",b);
		return;
	}
	for(i=0;i<j;i++)
	{
		if(!vis[i]&&!con[b[how-1]][a[i]])
		{
		vis[i]=1;
	    b[how]=a[i];
		check(how+1);
		vis[i]=0;
		}
	}
}
int main()
{
	bool flag,fla=0;
	long i;
	char ch,str[50000];
	while(gets(str))
	{
		flag=1;
		j=0;
		memset(vis,0,sizeof(vis));
		for(i=0;str[i]!='\0';i++)
			if(str[i]>='a'&&str[i]<='z')
				a[j++]=str[i];
		memset(con,0,sizeof(con));
		gets(str);
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]>='a'&&str[i]<='z')
				if(flag)
				{
					flag=0;
				ch=str[i];
				}
			   else
			   {
				   flag=1;
				   con[str[i]][ch]=1;
			   }
		}
		sort(a,a+j);
		if(fla)
			printf("\n");
		fla=1;
		for(i=0;i<j;i++)
		{
		   b[0]=a[i];
		   vis[i]=1;
		   check(1);
		   vis[i]=0;
		}
	}
	return 0;
}