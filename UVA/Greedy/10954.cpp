#include<stdio.h>
long a[6000],n;
void minheap(long i)
{
	long left,right,temp,point;
	left=2*i;
	right=left+1;
	point=i;
	if(left<=n&&a[left]<a[i])
		point=left;
	if(right<=n&&a[right]<a[point])
		point=right;
	if(point!=i)
	{
		temp=a[i];
		a[i]=a[point];
		a[point]=temp;
		minheap(point);
	}

}
void buildheap()
{
	long i;
		for(i=n/2;i>=1;i--)
			minheap(i);
}

int main()
{
	long res,add,i,temp;
	while(1)
	{
		scanf("%ld",&n);
		if(!n)
			break;
		for(i=1;i<=n;i++)
			scanf("%ld",&a[i]);
		buildheap();
		res=0;
		long j=0;
		for(;;)
		{
			temp=a[1];
			a[1]=a[n];
			a[n]=temp;
			n--;
			minheap(1);
			j++;
			if(j%2==0)
			{
				j=0;
				add=a[n+2]+a[n+1];
				res+=add;
				a[++n]=add;
				buildheap();
			}
			if(n==0)
				break;

		}
		printf("%ld\n",res);
	}
	return 0;
}
