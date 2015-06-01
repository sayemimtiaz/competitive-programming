#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
#define SIZE 10000
typedef vector<long>vi;
typedef queue<long>qi;
vi gr[SIZE];
qi q;
bool yes;
long par[SIZE];
bool vis[SIZE];
void init()
{
	while(!q.empty())
		q.pop();
	memset(vis,0,sizeof(vis));
	memset(par,0,sizeof(par));
}
void bfs(long c,long a)
{
	long i,b,next;
	q.push(a);
	vis[a]=1;
	while(!q.empty())
	{
		b=q.front();
		if(b==c)
			yes=1;
		q.pop();
		for(i=0;i<gr[b].size();i++)
		{
			next=gr[b][i];
			if(!vis[next])
			{
				vis[next]=1;
				q.push(next);
				par[next]=b;
			}
		}
	}
}
void print_path(long a,long b)
{
	if(!b)
		return;
	print_path(a,par[b]);
	if(b!=a)
		printf(" ");
	printf("%ld",b);
}
int main()
{
	long i,n,a,b,j,len;
	char str[60000],ch[60000];
	while(scanf("%ld",&n)==1)
	{
		getchar();
		while(n--)
		{
			j=0;
			gets(str);
			len=strlen(str);
			for(i=0;i<=len;i++)
			{
				if(str[i]=='-')
				{
					ch[j]='\0';
					a=atol(ch);
					j=0;
				}
				else if(str[i]>='0'&&str[i]<='9')
					ch[j++]=str[i];
				else
				{
					if(j)
					{
						ch[j]='\0';
						b=atol(ch);
						gr[a].push_back(b);

					}
					j=0;
				}
			}
		}
		bool flag=0;
		scanf("%ld",&n);
		printf("-----\n");
		while(n--)
		{
			yes=0;
			scanf("%ld %ld",&a,&b);
			bfs(b,a);
			if(yes)
			print_path(a,b);
			else
				printf("connection impossible");
			printf("\n");
			init();
		}
		printf("-----\n");
		for(i=0;i<SIZE;i++)
			gr[i].clear();
	}
	return 0;
}