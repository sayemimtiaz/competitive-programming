#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct S
{
	long mem[1005];
	long how;
}team[1005];
struct P
{
	long mem[1005];
	long head,tail;
	long prio;
}Q[1005];
int cmp(const void *a,const void *b)
{
	long *x=(long*)a;
	long *y=(long*)b;
	return *x-*y;
}
bool binser(long a,long n)
{
	long s,e,m;
	s=0;e=team[a].how-1;
	while(s<=e)
	{
		m=(s+e)/2;
		if(team[a].mem[m]==n)
			return 1;
		else if(team[a].mem[m]>n)
			e=m-1;
		else
			s=m+1;
	}
	return 0;
}
int main()
{
	char str[1000],cmnd[1000];
	long t,i,j,temp[1005],hw,num,kas=1,save,p;
	while(scanf("%ld",&t)==1&&t)
	{
		for(i=0;i<t;i++)
		{
			scanf("%ld",&hw);
			team[i].how=hw;
			for(j=0;j<hw;j++)
				scanf("%ld",&temp[j]);
			qsort(temp,hw,sizeof(long),cmp);
			for(j=0;j<hw;j++)
				team[i].mem[j]=temp[j];
			Q[i].head=Q[i].tail=0;
		}
	    printf("Scenario #%ld\n",kas++);
		getchar();
		p=0;
		while(gets(str)&&strcmp(str,"STOP"))
		{
			sscanf(str,"%s %ld",cmnd,&num);
			
			if(!strcmp(cmnd,"ENQUEUE"))
			{
				for(i=0;i<t;i++)
				{
					if(binser(i,num))
					{
						if(Q[i].head==Q[i].tail)
						{
							p++;
						   Q[i].prio=p;
						}
						Q[i].mem[Q[i].tail++]=num;
						break;
					}
				}
			}
			else
			{
				save=p+1;j=-1;
				for(i=0;i<t;i++)
				{
					if(Q[i].head!=Q[i].tail&&save>Q[i].prio)
					{
						save=Q[i].prio;
						j=i;
					}
				}
				if(j!=-1)
					printf("%ld\n",Q[j].mem[Q[j].head++]);
			}
		}
		printf("\n");
	}
	return 0;
}