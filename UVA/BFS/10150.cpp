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
long p[SIZE],n,e,s;
char word[100000][20];
long find(char *s)
{
	long i;
	for(i=0;i<n;i++)
		if(!strcmp(s,word[i]))
			return i;
	return -1;
}
bool bfs(long start)
{
	long i,next,u;
	p[start]=0;
	vis[start]=1;
	q.push(start);
	bool flag=0;
	while(!q.empty())
	{
		u=q.front();
		if(u==e)
			flag=1;
		q.pop();
		for(i=0;i<gr[u].size();i++)
		{
			next=gr[u][i];
			if(!vis[next])
			{
				q.push(next);
				vis[next]=1;
				p[next]=u;
			}
		}
	}
	return flag;
}
void print(long i)
{
	if(i==s)
	{
		printf("%s\n",word[i]);
		return;
	}
	print(p[i]);
	printf("%s\n",word[i]);
}
int main()
{
	char so[10000],de[10000],str[10000];
	long i,j,k,l1,l2,cnt;
		n=0;
		while(gets(word[n]))
		{
			if(strlen(word[n])==0)
				break;
			 n++;
		}
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
			for(i=0;i<n;i++)
				p[i]=i+1;
			s=find(so);
			e=find(de);
			if(s==-1||e==-1)
			{
					printf("No solution.\n");
					continue;
			}
		    if(f)
	    	printf("\n");
		    f=1;
			if(bfs(s))
			   print(e);
			else
				printf("No solution.\n");
		}
	return 0;
}