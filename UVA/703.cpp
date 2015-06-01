#include<stdio.h>
int a[120][120];
long si[1000000],sj[1000000],sk[1000000];
int main()
{
	long n,i,j,k,m;
	while(scanf("%ld",&n)==1)
	{
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				scanf("%d",&a[i][j]);
		m=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				for(k=1;k<=n;k++)
				{
					if((i>j&&j>k)||(i<j&&j<k))
					{
					if(a[i][j]&&a[j][k]&&a[k][i])
					{si[m]=i;sj[m]=j;sk[m]=k;m++;}
					else if(i<j&&j<k&&!a[i][j]&&!a[i][k]&&!a[j][k]&&!a[j][i]&&!a[k][j]&&!a[k][i])
						{si[m]=i;sj[m]=j;sk[m]=k;m++;}
					}
				}
			}
		}
		printf("%ld\n",m);
		for(i=0;i<m;i++)
			printf("%ld %ld %ld\n",si[i],sj[i],sk[i]);

	}
	return 0;
}