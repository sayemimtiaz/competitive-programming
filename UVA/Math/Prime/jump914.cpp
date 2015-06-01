#include<stdio.h>
#include<math.h>
#include<string.h>
bool flag[1000000];


long a[1000000],c,cnt[1000000];
void sieve()
{
	long n=1000000,i,j,r,k;
	k=sqrt(n);
	for(i=4;i<=n;i+=2)
        flag[i]=1;
	a[0]=2;
	c=1;
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
int main()
{
	long t,u,l,p,max,m,i,d,e;
 bool flag;
 sieve();
scanf("%ld",&t);
	while(t--)
	{
		scanf("%ld %ld",&l,&u);
		p=0;
		memset(cnt,0,sizeof(cnt));
		max=-100000000;
		m=-100000000;
		flag=0;
		long pr=0;
		for(i=0;i<c&&a[i]<=u;i++)
		{
			if(a[i]>=l)
			{
				pr++;
				if(flag)
				{
				d=a[i]-p;
				cnt[d]++;
				if(max<d)
					max=d;
				if(cnt[d]>m)
				{
					m=cnt[d];
					e=d;
				}
				p=a[i];
				}
				else
				{
					flag=1;
					p=a[i];
				}
			}
		}
		flag=0;
	  if(pr<2)
			flag=1;
		else
		{
		
		for(i=1;i<=max;i++)
		{
		 if(i!=e&&cnt[i]&&cnt[i]==cnt[e])
			{
				flag=1;
				break;
			}
		}
		}
		if(flag)
			printf("No jumping champion\n");
		else

		printf("The jumping champion is %ld\n",e);
	}
	return 0;

	}
