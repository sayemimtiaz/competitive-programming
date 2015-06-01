#include<stdio.h>
#include<math.h>
#define SIZE 10000500
long d[SIZE],c,a[SIZE];
bool prime[SIZE];
long fac(long n)
{
     bool flag=0;
     long i,s,prev,fr;
      fr=s=1;
      for(i=0;i<c&&a[i]<n&&prime[n];)
          {
            if(n%a[i]==0)
            {
               if(flag&&prev==a[i])
                   fr++;
               else if(flag)
               {
                    s*=(fr+1);
                    fr=1;
               }
               flag=1;
               prev=a[i]; 
               n/=a[i];
            }
            else
              i++;
        }
        if(prev==n)
          fr++;
        else
        {
         s*=(fr+1);fr=1;}
        s*=(fr+1);
        return s;

}
void sieve(long N)
{
     long i,j,prev,dv;
     long M=sqrt(N);
	for(i=4;i<=N;i+=2)
		prime[i]=1;
	a[0]=2;c=1;
	for(i=3;i<=N;i+=2)
	{
		if(!prime[i])
		{
           // if(c<168)         
            a[c++]=i;
            if(c==10000)
             printf("%ld\n",i);
            if(i<=M)
			for(j=i*i;j<=N;j+=2*i)
				prime[j]=1;
		}
	}
	d[1]=1;prev=1;
	printf("%ld\n",c);
	/*for(i=2;i<=1000000;i++)
	{
     if(prime[i])
	 dv=fac(i);
 	else
 	dv=2;
	 if(dv>=prev)
	 {
         prev=dv;
         d[i]=i;
      }
      else
      d[i]=d[i-1];
    }*/
}
int main()
{
    long kase,i,n;
    sieve(112000);
    scanf("%ld",&kase);
    while(kase--)
    {
        scanf("%ld",&n);
        printf("%ld\n",d[n]);
    }
    return 0;
}
