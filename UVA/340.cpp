#include<stdio.h>
#include<string.h>
long res_x[1000000],res_y[1000000];
int main()
{
	bool t1[10000],t2[10000];
	long ori[10000],a[10000];
	long n,i,j,k,count,strong,weak,kas=1;
	while(1)
	{
		scanf("%ld",&n);
		if(!n)
			break;
		for(i=0;i<n;i++)
			scanf("%ld",&ori[i]);
		k=0;
		while(1)
		{
			count=0;
		  for(i=0;i<n;i++)
		  {
			scanf("%ld",&a[i]);
			if(!a[i])
				count++;
		  }
		  if(count==n)
			  break;
		  memset(t1,0,sizeof(t1));
		  memset(t2,0,sizeof(t2));
		  strong=weak=0;
		  for(i=0;i<n;i++)
			  if(ori[i]==a[i])
			  {
				  t1[i]=t2[i]=1;
				  strong++;
			  }
		  for(i=0;i<n;i++)
		  {
			  if(!t1[i])
			  {
			  for(j=0;j<n;j++)
			  {
				  if(!t2[j]&&ori[i]==a[j])
				  {
					  t1[i]=t2[j]=1;
					  weak++;
					  break;
				  }
			  }
			  }
		  }
			res_x[k]=strong;
			res_y[k]=weak;
			k++;
		}
		printf("Game %ld:\n",kas++);
		for(i=0;i<k;i++)
			printf("%4c(%ld,%ld)\n",' ',res_x[i],res_y[i]);
	}
	return 0;
}