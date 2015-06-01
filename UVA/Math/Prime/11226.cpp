#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
long  a[10000100],b[1000000],c;
bool flag[10000100];
void sieve(long n)
{
    long  k,i,j,r;
    k=sqrt(n)+1;
    memset(flag,0,sizeof(flag));
    flag[1]=1;
    a[0]=2;
    c=1;
    for(i=4;i<=n;i+=2)
        flag[i]=1;
    for(i=3;i<=n;i+=2)
    {
       if(flag[i]==0)
       {
          a[c++]=i;
          if(k>=i)
          {
              r=i+i;
              for(j=i*i;j<=n;j+=r)
                 flag[j]=1;
           }
         }
      }
}
void fac()
{
	long i,j,n,sum;
	for(i=2;i<=500000;i++)
	{
		if(flag[i]==0)
			b[i]=i;
		else
		{
			n=i;
			sum=0;
			for(j=0;j<126&&n>=a[j];)
			{
				if(n%a[j]==0)
				{
					sum+=a[j];
					n/=a[j];
				}
				else
					j++;
			}
			if(n!=1)
				sum+=n;
			b[i]=sum;
		}
	}
}
int main()
{
	long i,d,cnt,kas,kase,n,m,temp;
	sieve(500000);
	fac();
	scanf("%ld",&kase);
	kas=1;
	while(kase--)
	{
		scanf("%ld %ld",&n,&m);
		if(n>m)
		{
			temp=n;
			n=m;
			m=temp;
		}
		long max=-10000;
		for(i=n;i<=m;i++)
		{
			d=i;
			cnt=1;
			while(1)
			{
				if(d==b[d])
					break;
				d=b[d];
				cnt++;
			}
			if(cnt>max)
				max=cnt;
		}
		printf("Case #%ld:\n%ld\n",kas++,max);
	}
	return 0;
}