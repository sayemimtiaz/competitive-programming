#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool con[1000][1000],vis[1000],found;
char a[10000],b[1000];
long j;
void check(long how,long k)
{
	long i,m;
	if(how==j)
	{
		for(i=0;i<k;i++)
			if(b[i]!=' ')
			for(m=i+1;m<k;m++)
		      if(b[m]!=' '&&con[b[i]][b[m]])
				return;
		b[k]='\0';
		found=1;
		printf("%s\n",b);
		return;
	}
	for(i=0;i<j;i++)
	{
		if(!vis[i]&&!con[b[how-1]][a[i]])
		{
		vis[i]=1;
		b[k]=' ';
	    b[k+1]=a[i];
		check(how+1,k+2);
		vis[i]=0;
		}
	}
}
int main()
{
	bool flag,fla=0;
	long i,kase;
	char ch,str[50000];
	scanf("%ld",&kase);
	getchar();
	while(kase--)
	{
		getchar();
		gets(str);
		flag=1;
		j=0;
		memset(vis,0,sizeof(vis));
		for(i=0;str[i]!='\0';i++)
			if(str[i]>='A'&&str[i]<='Z')
				a[j++]=str[i];
		memset(con,0,sizeof(con));
		gets(str);
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]>='A'&&str[i]<='Z')
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
		found=0;
		sort(a,a+j);
		if(fla)
			printf("\n");
		fla=1;
		for(i=0;i<j;i++)
		{
		   b[0]=a[i];
		   vis[i]=1;
		   check(1,1);
		   vis[i]=0;
		}
		if(!found)
			printf("NO\n");
	}
	return 0;
}