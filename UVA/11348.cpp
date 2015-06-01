#include<stdio.h>
#include<string.h>
bool arr[60][10009]={0};
int test[10009],u[10009];
double c[100];
int main()
{
	int kase,s,a,i,j,k,max,l,n,h;
	double r,sum;
	scanf("%d",&kase);
	for(i=1;i<=kase;i++)
	{
		scanf("%d",&n);
		memset(arr,0,sizeof(arr));
		memset(test,0,sizeof(test));
		sum=0;
		for(j=1;j<=n;j++)
		{
			scanf("%d",&s);
		    for(k=1;k<=s;k++)
			{
				scanf("%d",&a);
				arr[j][a]=1;
				if(test[a]!=j&&test[a])
  				  test[a]=-1;
		        else
  				  test[a]=j;
			}

		}
		for(j=1;j<=n;j++)
		{
			c[j]=0;
			for(k=0;k<=10000;k++)
				if(arr[j][k]&&test[k]!=-1)
					c[j]++;
			sum+=c[j];
		}
		printf("Case %d:",i);
		for(j=1;j<=n;j++)
		{
			r=(double)(100.00*c[j])/(double)sum;
        	printf(" %lf%%",r);
		}
		printf("\n");
	}
			return 0;
}
