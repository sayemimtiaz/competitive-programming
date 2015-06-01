#include<stdio.h>
#include<math.h>
#define SIZE 1000500
int c,a[SIZE];
bool prime[SIZE];

void sieve(long N)
{
     int i,j,prev,dv;
     int M=sqrt(N);
	for(i=4;i<=N;i+=2)
		prime[i]=1;
	a[0]=2;c=1;
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
int main()
{
    int i,n,b,cc;
    bool flag;
    sieve(1000009);
    while(scanf("%d",&n)&&n)
    {
        b=n/2;
        printf("%d:\n",n);
        flag=0;
        for(i=0;i<c&&a[i]<=b;i++)
        {
          cc=n-a[i];
          if(!prime[cc])
          {
            printf("%d+%d\n",a[i],cc);
            flag=1;
            break;
          }
        }
        if(!flag)
         printf("NO WAY!\n");
    }
    return 0;
}
