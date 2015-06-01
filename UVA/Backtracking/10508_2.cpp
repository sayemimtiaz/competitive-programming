#include<stdio.h>
#include<string.h>
void push(long);
long pop();
void call(long);
void init();
void reinit(long);
long check(long);
bool flag[2000],prin[20000],vis[20000];
bool order[2000][2000];
long top,stack[1000000],m,n;
char str[2000][2000];
int main()
{
	long i;
	while(scanf("%ld %ld",&m,&n)==2)
	{
		for(i=0;i<m;i++)
			scanf("%s",str[i]);
		init();
		call(0);
	}
	return 0;
}
void init()
{
	memset(flag,0,sizeof(flag));
	memset(order,0,sizeof(order));
	memset(prin,0,sizeof(prin));
	top=0;
}
void reinit(long pos)
{
	long i;
	for(i=0;i<n;i++)
		if(!order[pos][i])
			flag[i]=0;
		memset(order,0,sizeof(order));
	prin[pos]=0;
}
void call(long pos)
{
	while(pos!=1)
	{
		pos=check(pos);
		if(pos==-1)
		{
		  pos=pop();
	      reinit(pos);
		}
	}
	push(1);
	prin[1]=1;
	long i;
	for(i=0;i<top;i++)
	{
		if(prin[stack[i]])
		  printf("%s\n",str[stack[i]]);
	}
}
long check(long pos)
{
	long i,j,cnt,p;
	if(!prin[pos])
	{
	push(pos);
	prin[pos]=1;
	for(i=0;i<m;i++)
	{
		if(i!=pos)
		{
			cnt=0;
		for(j=0;j<n;j++)
		{
		  if(str[pos][j]!=str[i][j])
		  {
			  p=j;
			  cnt++;
		  }
		}
		if(cnt==1)
		{
			if(flag[p])
				continue;
			order[pos][p]=1;
			flag[p]=1;
			return i;
		}
		}
	}
	return -1;
	}
}
void push(long d)
{
	stack[top++]=d;
}
long pop()
{
	top--;
	return stack[top];
}