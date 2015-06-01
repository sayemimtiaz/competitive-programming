#include<stdio.h>
#include<math.h>
#include<string.h>
#define SIZE 1000090

int prime[SIZE],tim;
long long c,a[80000],A,B;


void sieve(long long N)
{
     long long i,j;
     long long M=sqrt(N);
	c=1;a[0]=2;
	for(i=3;i<=N;i+=2)
	{
		if(!prime[i])
		{
            a[c++]=i;
            if(i<=M)
			for(j=i*i;j<=N;j+=2*i)
				prime[j]=1;
		}
	}
}	
long long cnnt(long long A,long long B)
{
    // printf("%lld %lld\n",A,B);
     long long i,j,cnt=0,s;
     long long M=sqrt(B);
     for(i=1;i<c&&a[i]<=M;i++)
     {
      s=A/a[i];
      if(A%a[i]) s++;
      if(s%2==0) s++;
      if(s==1) s=3;
      for(j=s*a[i];j<=B;j+=2*a[i]){
       prime[j-A]=tim;
       }
      }
     for(i=A;i<=B;i++)
      if(((i!=2&&i%2)||(i==2))&&prime[i-A]!=tim){ cnt++;}
      return cnt;
}
void fac(long long n,bool ok)
{
     long long i,j,t,cnt=0;
  for(i=0;i<c&&a[i]<=n;i++)
   if(n%a[i]==0){
                 t=n/a[i];
    if(!ok)
    A=a[i],B=t;
    else if(A==a[i])
    {
         
         printf(" area %lld has %lld crates\n",a[i],cnnt(B,t));
    }
    else if(B==a[i])
    {
         
         printf(" area %lld has %lld crates\n",a[i],cnnt(A,t));
    }
    else if(A==t)
    {
         printf(" area %lld has %lld crates\n",A,cnnt(B,a[i]));
    }
    else
      {
         printf(" area %lld has %lld crates\n",B,cnnt(A,a[i]));
    }
    break;
    }
}
int main()
{
    long long kase,i,n,kas=0,a,b;
    sieve(1000009);
    memset(prime,0,sizeof(prime));tim=1;
    scanf("%lld",&kase);
    while(kase--)
    {
        scanf("%lld %lld",&a,&b);
        printf("Case %lld:",++kas);
        fac(a,0);
        fac(b,1);
        tim++;
    }
    return 0;
}
