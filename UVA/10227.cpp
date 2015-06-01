#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 500
struct t
{
	bool y;
	long c;
	long data[SIZE];
}gr[SIZE];
void init()
{
	long i,j;
	for(i=0;i<120;i++)
	{
			gr[i].y=0;
			gr[i].c=0;
			for(j=0;j<120;j++)
				gr[i].data[j]=0;
	}
}
int main()
{
	bool flag=0;
	long kase,p,t,i,j,k,count,final,a[2],cnt;
	char s[1000];
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%ld %ld",&p,&t);
		getchar();
		init();
		cnt=0;
		while(gets(s))
		{
			if(strlen(s)==0)
				break;
			sscanf(s,"%ld %ld",&a[0],&a[1]);
			if(!gr[a[0]-1].data[a[1]-1])
			{
			gr[a[0]-1].data[a[1]-1]=1;
			gr[a[0]-1].c++;
			if(!gr[a[0]-1].y)
				cnt++;
			gr[a[0]-1].y=1;
			}
		}
		final=0;
		for(i=0;i<p;i++)
		{
			if(gr[i].y==1)
			{

				final++;
			for(j=i+1;j<p;j++)
			{
				count=0;
				if(gr[i].c==gr[j].c)
				{
								
					for(k=0;k<120;k++)
					{
						if(gr[i].data[k]==1&&gr[j].data[k]==1)
							count++;
					}
					if(count==gr[i].c)
						gr[j].y=0;
				}
			}
			}
		}
		if(cnt!=p)
			final++;
		if(flag)
			printf("\n");
		flag=1;
		printf("%ld\n",final);

	}
	return 0;
}