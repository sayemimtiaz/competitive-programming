#include<stdio.h>
#include<math.h>
#define SIZE 3000000

bool prime[SIZE];
int a[5000],c,d[SIZE],f[SIZE],r[SIZE];

int fac(int n)
{
	int j;
	for(j=0;a[j]<n;j++)
	     if(n%a[j]==0)
	      return a[j];
}
void sieve(long n)
{
	long i,j;
	long m=sqrt(n);
	for(i=4;i<=n;i+=2)
		prime[i]=1;
	a[0]=2;
	c=1;
	for(i=3;i<=n;i+=2)
	{
		if(!prime[i])
		{    
            if(c<278)     
            a[c++]=i;
			if(m>=i)
				for(j=i*i;j<=n;j+=2*i)
					prime[j]=1;
		}
	}
	d[0]=1;d[1]=1;d[2]=1;f[1]=1;f[2]=1;
	for(i=3;i<2703663;i++)
	{
       if(!prime[i])
        f[i]=1;
       else
        f[i]=1+f[i/fac(i)];
       d[i]=d[i-1]+f[i];
    }
}
int main()
{
    int a,b,kase,e,m;
    sieve(3000000);
    scanf("%d",&kase);
    while(kase--)
    {
       scanf("%d",&a);
       b=2;e=2703662;
       while(b<=e)
       {
         m=(b+e)/2;
         if(d[m]==a)
          break;
         if(d[m]<a&&d[m+1]>a)
          break;
         if(d[m]<a)
          b=m+1;
         else
          e=m-1;
       }
       printf("%d\n",m+1);
    }
    return 0;
}
