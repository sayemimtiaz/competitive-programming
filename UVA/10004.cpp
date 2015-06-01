#include<stdio.h>
int arr[200][200];
int queue[1000],color[1000];
int front,rear;
void enqueue(int data)
{
	queue[rear]=data;
	rear++;
}
int dequeue()
{
	if(front==rear+1)
		return 0;
	int data=queue[front];
	front++;
	return data;
}
void initnode(int n)
{
	front=rear=0;
	for(int i=0;i<n;i++)
	{
		color[i]=0;
	}
}
void bfs(int n)
{
	initnode(n);
	enqueue(1);
	color[0]=1;
	int a,i,j;
	int flag=0;
	while(a=dequeue())
	{   
		a--;
		if(color[a]==1)
			j=2;
		else
			j=1;
		for(i=0;i<n;i++)
			if(arr[a][i])
			{
				if(color[i]==j)
					continue;
				else if(color[i]==0)
					color[i]=j;
				else
				{
					flag=1;
					break;
				}
				enqueue(i+1);
			}
		if(flag==1)
			break;
	}
	if(flag==1)
		printf("NOT BICOLORABLE.");
	else
			printf("BICOLORABLE.");
}

		
int main()
{
	int i,j,a,b;
	int num_node,num_edge;
	while(1)
	{
	scanf("%d",&num_node);
	if(num_node==0)
		break;
		scanf("%d",&num_edge);
	for(i=0;i<num_node;i++)
		for(j=0;j<num_node;j++)
			arr[i][j]=0;
	for(i=0;i<num_edge;i++)
	{
		scanf("%d %d",&a,&b);
		arr[a][b]=1;
		arr[b][a]=1;
	}
	bfs(num_node);
	printf("\n");
	}
	return 0;
}
