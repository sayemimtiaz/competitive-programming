#include<stdio.h>
long a[10000];
int main()
{
	long i,j,u,v,n,k,dead;
	while(scanf("%ld %ld",&n,&k)==2&&(n||k))
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			   a[j]=j+1;
			dead=0;
			u=i-1;
			while(dead<n-1)
			{ 
                 for(j=1;j<=k;)
                 {u=(u+1)%n;
                  if(a[u])j++;}
                 v=u;
                 for(j=1;j<=k;)
                 {v=(v+1)%n;
                  if(a[v]&&u!=v)j++;}
                  a[u]=a[v];
                  a[v]=0;
                  dead++;
            }
            if(!dead)
             u=i;
		    if(a[u]==1)
		     break;
		}
		printf("%ld\n",i+1);
	}
	return 0;
}
