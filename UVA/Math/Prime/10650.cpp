#include<stdio.h>
#include<math.h>
#include<string.h>
long a[100000],c=0;
bool flag[100000];
long y[10000][50],j=0,b=0;
void sieve(long n)
{
	c=0;
	memset(flag,0,sizeof(flag));
	long i,k;
	long m=sqrt(n)+1;
	flag[0]=flag[1]=1;
	for(i=4;i<=n;i+=2)
		flag[i]=1;
	a[c]=2;
	c=1;
	for(i=3;i<=n;i+=2)
	{
		if(flag[i]==0)
		{
			a[c++]=i;
			if(c<200)
			 printf("%ld\n",i);
			if(m>=i)
			{
				for(k=i*i;k<=n;k+=2*i)
					flag[k]=1;
			}
		}
	}
}
void precal()
{
	long cnt,i,k,d;
	bool fl;
	fl=0;
	cnt=0;
	j=0;
	k=2;
	for(i=0;i<c;)
		{
				  cnt++;
				if(cnt==3)
				{
					if(a[i]-a[i-1]==a[i-1]-a[i-2])
					{
						d=a[i]-a[i-1];
						fl=1;
						y[j][0]=a[i-2];y[j][1]=a[i-1];
					}
					else
					{
						i=i-1;
						cnt=0;
						continue;
					}
				}
				if(fl&&(a[i]-a[i-1])==d)
				{
					y[j][k]=a[i];
					k++;
				}
				else if(fl)
				{
					y[j][k]=-1;
					k=2;
					j++;
					i--;
					cnt=0;
					fl=0;
					continue;
				}
			i++;
		}
}
void find(long d)
{
	long i,k;
	bool fl;
	fl=0;
	for(i=0;i<j;i++)
	{
		if(d==y[i][0])
		{
			fl=1;
			break;
		}
	}
	if(fl)
	{
		for(k=0;y[i][k]!=-1;k++);
		if(y[i][k-1]<=b)
			fl=1;
		else
			fl=0;
		if(fl)
		{
		for(k=0;y[i][k]!=-1;k++)
		{
			if(k!=0)
				printf(" ");
			printf("%ld",y[i][k]);
		}
		printf("\n");
		}
	}
}
int main()
{
	long s,i,temp;
	sieve(32000);
	precal();
	while(1)
	{
		scanf("%ld %ld",&s,&b);
		if(s==0&&b==0)
			break;
		if(s>b)
		{
			temp=s;
			s=b;
			b=temp;
		}
		for(i=s;i<=b;i++)
		{
			if(flag[i]==0)
				find(i);
		}
	}
	return 0;
}
