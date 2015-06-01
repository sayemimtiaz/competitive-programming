#include<stdio.h>
#include<memory.h>
struct T
{
	long wl,wr,dl,dr;
}tree[100000];
bool flag;
long i;
bool vis[100000];
long verse(long next)
{
	long j;
	if(!tree[next].wl)
	{
		for(j=next+1;j<i;j++)
		{
			if(!vis[j])
			{
			vis[j]=1;
		  tree[next].wl=verse(j);
		  break;
			}
		}
	}
	if(!tree[next].wr)
	{
		for(j=next+1;j<i;j++)
		{
			if(!vis[j])
			{
			vis[j]=1;
		  tree[next].wr=verse(j);
		  break;
			}
		}
	}
	if((tree[next].wl*tree[next].dl)!=(tree[next].wr*tree[next].dr))
	{
		flag=1;
	}
	return (tree[next].wl+tree[next].wr);
}
int main()
{
	char str[60000];
	long kase;
	bool p=0;
	scanf("%ld",&kase);
	getchar();
	getchar();
	while(kase--)
	{
		i=0;
		while(gets(str)&&str[0]!='\0')
		{
			sscanf(str,"%ld %ld %ld %ld",&tree[i].wl,&tree[i].dl,&tree[i].wr,&tree[i].dr);
			i++;
		}
		memset(vis,0,sizeof(vis));
		flag=0;
		verse(0);
		if(p)
			printf("\n");
		p=1;
		if(flag)
			printf("NO");
		else
			printf("YES");
		printf("\n");

	}
	return 0;
}