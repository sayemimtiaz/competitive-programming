#include<stdio.h>
int queue[100000];
int front,rear;
void enqueue(int n)
{
	queue[rear]=n;
	rear++;
}
int dequeue()
{
	front++;
		return queue[front-1];

}
void set_queue(int n)
{
	front=rear=0;
	for(int i=1;i<=n;i++)
		enqueue(i);
}
int main()
{
	int n,i,j,a;
	while(1)
	{
	    scanf("%d",&n);
		if(!n)
			break;
		for(i=2;;i++)
		{
			set_queue(n);
			
			dequeue();
			for(j=2;;j++)
			{
				if(front==rear-1)
					break;
				if((j-1)%i==0)
		           dequeue();
				else
				{
					a=dequeue();
					enqueue(a);
				}

			}
			if(queue[front]==2)
				break;
		}
		printf("%d\n",i);
	}

	return 0;
}