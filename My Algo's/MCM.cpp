#include<stdio.h>
#define INFINITY 100000000
long m[100][100],s[100][100],n,a[1000];
void mcm()
{
	long i,j,k,l,q;
	for(i=1;i<=n-1;i++)
		m[i][i]=0;
	for(i=2;i<=n-1;i++)
	{
		for(j=1;j<=n-i+1;j++)
		{
			k=j+i-1;
			m[j][k]=INFINITY;
			for(l=j;l<k;l++)
			{
				q=m[j][l]+m[l+1][k]+a[j-1]*a[l]*a[k];
				if(q<m[j][k])
				{
					m[j][k]=q;
					s[j][k]=l;
				}
			}
		}
	}
	printf("%ld\n",m[1][n-1]);
}
void input()
{
	long i;
	scanf("%ld",&n);
	for(i=0;i<n;i++)
		scanf("%ld",&a[i]);
}
int main()
{
	input();
	mcm();
	return 0;
}
