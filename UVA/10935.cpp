#include<stdio.h>
int queue[30000],front,rear;
void enqueue(int a)
{
	queue[rear]=a;
	rear++;
}
int dequeue()
{
	if(front==rear-1)
		return 0;
	front++;

	return queue[front-1];
}

int main()
{
	int n,i,j,a,dis[3000];
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			break;
		front=rear=0;
		for(i=1;i<=n;i++)
			enqueue(i);
		i=1;
		j=0;
		while(a=dequeue())
		{
			if(i==1)
			{
				dis[j]=a;
				j++;
				i=2;
			}
			else if(i==2)
			{
				i=1;
				enqueue(a);
			}
		}
		printf("Discarded cards:");
		for(i=0;i<j;i++)
		{
			printf(" %d",dis[i]);
			if(i<j-1)
				printf(",");
		}
		printf("\n");
		printf("Remaining card: %d\n",queue[front]);
	}
	return 0;
}
