#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	long a;
	long b;
}record;
record rec[10000];
int comp(const void *u,const void *v)
{
	record *x=(record*)u;
	record *y=(record*)v;
	return x->a-y->a;
}
int main()
{
	long h[10000],init,n,diff,max,day=1,start,i;
	char s[10000];
	while(scanf("%ld",&n)==1)
	{
		getchar();
		init=600;
		max=-1000000000;
		for(i=0;i<n;i++)
		{
			gets(s);
			sscanf (s, "%ld:%d %ld:%d", &h[0], &h[1],&h[2], &h[3]);
			rec[i].a=(h[0]*60)+h[1];
			rec[i].b=(h[2]*60)+h[3];
		}
		qsort(rec,n,sizeof(record),comp);
		for(i=0;i<n;i++)
		{
		diff=rec[i].a-init;
		if(max<diff)
		{
			start=init;
			max=diff;
		}
		init=rec[i].b;
		}
		diff=1080-init;
		if(max<diff)
		{
			start=init;
			max=diff;
		}
      if ( max < 60 )
           printf ("Day #%ld: the longest nap starts at %ld:%.2ld and will last for %ld minutes.\n", day++, start / 60, start % 60, max);
        else
            printf ("Day #%ld: the longest nap starts at %ld:%.2ld and will last for %ld hours and %ld minutes.\n",day++, start / 60, start% 60, max / 60, max % 60);
	}
	return 0;
}