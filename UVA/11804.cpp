#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct T
{
	char s[30];
	long a,d;
}gr[10];
int cmp(const void *a,const void *b)
{
	T *x=(T*)a;
	T *y=(T*)b;
	return (strcmp(x->s,y->s));
}
int main()
{
	long i,j,k,l,m,pi,pj,pk,pl,pm,sum,def,save_a,save_d,kase,kas=1;
	bool yes;
	scanf("%ld",&kase);
	while(kase--)
	{
		for(i=0;i<10;i++)
			scanf("%s %ld %ld",gr[i].s,&gr[i].a,&gr[i].d); 
		qsort(gr,10,sizeof(T),cmp);
		save_a=-100000000;
		save_d=100000000;
		for(i=0;i<6;i++)
			for(j=i+1;j<7;j++)
				for(k=j+1;k<8;k++)
					for(l=k+1;l<9;l++)
						for(m=l+1;m<10;m++)
						{
							sum=gr[i].a+gr[j].a+gr[k].a+gr[l].a+gr[m].a;
							def=gr[i].d+gr[j].d+gr[k].d+gr[l].d+gr[m].d;
							if(sum>save_a)
							{
								pi=i;pj=j;pk=k;pl=l;pm=m;
								save_a=sum;
								save_d=sum=def;
							}
							else if(sum==save_a&&def<save_d)
							{
								pi=i;pj=j;pk=k;pl=l;pm=m;
								save_a=sum;
								save_d=sum=def;
							}
						}
		int flag[100]={0};
		flag[pi]=flag[pj]=flag[pl]=flag[pk]=flag[pm]=1;
		sum=def=0;
		for(i=0;i<10;i++)
			if(!flag[i])
			{
				sum+=gr[i].a;
				def+=gr[i].d;
			}
		if(sum==save_a)
		{
			if(save_d<def)
				yes=1;
			else 
				yes=0;
		}
		else
			yes=1;
		printf("Case %ld:\n",kas++);
		sum=0;
		if(yes)
		{
			printf("(%s, %s, %s, %s, %s)\n(",gr[pi].s,gr[pj].s,gr[pk].s,gr[pl].s,gr[pm].s);
			for(i=0;i<10;i++)
				if(!flag[i])
				{
					printf("%s",gr[i].s);
					sum++;
					if(sum!=5)
						printf(", ");
				}
			printf(")\n");
		}
		else
		{
			printf("(");
			for(i=0;i<5;i++)
			{
					printf("%s",gr[i].s);
					if(i!=4)
						printf(", ");
			}
			printf(")\n(");
			for(i=5;i<10;i++)
			{
					printf("%s",gr[i].s);
					if(i!=9)
						printf(", ");
			}
			printf(")\n");
		}

			
	}
	return 0;
}