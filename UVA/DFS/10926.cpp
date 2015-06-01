#include<stdio.h>
int arr[100][100];
int stack[1000],visited[1000];
int top;

void push(int data)
{
	stack[top]=data;
	top++;
}
int pop()
{
	top--;
	return stack[top];
}
void initnode(int n)
{
	top=0;
	for(int i=0;i<n;i++)
		visited[i]=0;
}

int  dfs(int n,int c)
{

	push(0);
	push(n+1);
	visited[n]=1;
	int a,i,count=0;;
	while(a=pop())
	{
		count++;
		a--;
		for(i=0;i<c;i++)
			if(arr[a][i]&&!visited[i])
			{
				visited[i]=1;
				push(i+1);
			}
	}
	return count;
}


		
int main()
{
	int i,j,a,b,max;
	int n;
	while(1)
	{
		scanf("%d",&n);
		if(!n)
			break;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				arr[i][j]=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		for(j=0;j<a;j++)
		{
			scanf("%d",&b);
			arr[i][b-1]=1;
		}
	}
	for(i=0;i<n;i++)
	{
		initnode(n);
		a=dfs(i,n);
		if(i==0)
		{
			max=a;
			b=i+1;
		}
		else if(a>max)
		{
			max=a;
			b=i+1;
		}
	}
	printf("%d\n",b);
	}
	return 0;
}
