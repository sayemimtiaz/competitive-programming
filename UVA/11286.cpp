#include<stdio.h>
#include<string.h>
struct S
{
	long a[5];
}s[12000];
void sort(long n)
{
	long i,j,temp;
	for(i=0;i<5;i++)
		for(j=i+1;j<5;j++)
			if(s[n].a[i]>s[n].a[j])
			{
				temp=s[n].a[i];
				s[n].a[i]=s[n].a[j];
				s[n].a[j]=temp;
			}
}
int main()
{
	long n,i,j,l,max,final,p;
	bool flag[20000],found,yes;
	while(scanf("%ld",&n)==1&&n)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<5;j++)
			{
			   scanf("%ld",&s[i].a[j]);
			}
		    sort(i);
		}
		p=max=-1000000;
		memset(flag,0,sizeof(flag));
		for(i=0;i<n;i++)
		{
			yes=0;
			final=0;
			if(!flag[i])
			{
			for(j=i+1;j<n;j++)
			{
				found=0;
				for(l=0;l<5;l++)
				{
					if(s[i].a[l]!=s[j].a[l])
					{
							found=1;
							break;
					}
				}
				if(!found)
				{
					flag[j]=1;
					if(!yes)
					{
						yes=1;
						final+=2;
					}
					else
						final++;
				}
			}
			if(p<final)
			{
				p=final;
				max=final;
			}
			else if(final==p)
				max+=p;
			}
		}
		if(max<=0)
			max=n;
		printf("%ld\n",max);

	}
	return 0;
}