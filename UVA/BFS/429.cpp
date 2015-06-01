#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
#define SIZE 1000000
typedef queue<long>qi;
typedef vector<long>vi;
qi q;
vi gr[SIZE];
bool vis[SIZE];
long d[SIZE],n;
char word[10000][15];
long find(char *s)
{
	long i;
	for(i=0;i<n;i++)
		if(!strcmp(s,word[i]))
			return i;
	return -1;
}
void bfs(long start)
{
	long i,next,u;
	d[start]=0;
	vis[start]=1;
	q.push(start);
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(i=0;i<gr[u].size();i++)
		{
			next=gr[u][i];
			if(!vis[next])
			{
				q.push(next);
				vis[next]=1;
				d[next]=d[u]+1;
			}
		}
	}
}
int main()
{
	char so[10000],de[10000],str[10000];
	long m,i,kase,j,k,l1,l2,s,e,cnt;
	bool flag=0;
	scanf("%ld",&kase);
	for(m=0;m<kase;m++)
	{
		n=0;
		while(scanf("%s",word[n])==1&&strcmp(word[n],"*"))
			n++;
		getchar();
		for(i=0;i<n;i++)
		{
			l1=strlen(word[i]);
			for(j=i+1;j<n;j++)
			{
				l2=strlen(word[j]);
				if(l1==l2)
				{
					cnt=0;
					for(k=0;k<l1;k++)
						if(word[i][k]!=word[j][k])
							cnt++;
					if(cnt<=1)
					{
						gr[i].push_back(j);
						gr[j].push_back(i);
					}
				}
			}
		}
		bool f=0;
		while(gets(str))
		{
			if(strlen(str)==0)
				break;
			sscanf(str,"%s %s",so,de);
			memset(vis,0,sizeof(vis));
			s=find(so);
			e=find(de);
			bfs(s);
		   if(flag&&!f)
	    	printf("\n");
		    f=1;
			printf("%s %s %ld\n",so,de,d[e]);
		}
		flag=1;
		for(i=0;i<n;i++)
		{
		   d[i]=0;
		   gr[i].clear();
		}
	}
	return 0;
}