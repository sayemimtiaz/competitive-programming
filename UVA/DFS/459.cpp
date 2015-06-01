#include<stdio.h>
#include<string.h>
int arr[500][500],visited[600];
long stack[600],top,node;
void push(long data)
{
	stack[top]=data;
	top++;
}
long pop()
{
	top--;
	return stack[top];
}
void dfs(long n)
{
	push(0);
	push(n);
	visited[n-1]=1;
	long a,i;
	while(a=pop())
	{
		a--;
		for(i=0;i<=node;i++)
			if(arr[a][i]&&!visited[i])
			{
				visited[i]=1;
				push(i+1);
			}
	}
}

long find_pos(char c)
{
			long j=0;
		for(long i='A';i<='Z';i++)
		{
			if(i==(int)c)
			{
				break;
			}
			j++;
		}
		return j;
}
int main()
{
	char c,d,s[100];
	long kase,count,a,b,i;
	bool h=0;
	scanf("%ld\n",&kase);
	while(kase--)
	{
		memset(arr,0,sizeof(arr));
		scanf("%c",&c);
		d=getchar();
		node=find_pos(c);
		while(	gets(s))
		{
		
			if(strlen(s)==0)
				break;
			c=s[0];
			d=s[1];
			a=find_pos(c);
			b=find_pos(d);
			arr[a][b]=1;
			arr[b][a]=1;

		
		}
	
		count=0;
		top=0;
		memset(visited,0,sizeof(visited));
		for(i=0;i<=node;i++)
		{
			if(visited[i]==0)
			{
				count++;
				dfs(i+1);
			}
		}
		if(h)
			printf("\n");
		h=1;
		printf("%ld\n",count);
	}
	return 0;
}