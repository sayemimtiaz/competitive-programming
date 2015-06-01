#include<stdio.h>
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
	long *x=(long*)a;
	long *y=(long*)b;
	return (*x-*y);
}
int main()
{
	long C,S,i,j,a[100],odd,kas=1,k;
	double am,sum,res,cm;
	while(scanf("%ld %ld",&C,&S)==2)
	{
		sum=0;
		for(i=0;i<S;i++)
		{
			scanf("%ld",&a[i]);
			sum+=a[i];
		}
		am=sum/(double)C;
		qsort(a,S,sizeof(long),cmp);
		odd=(C*2)-S;
		if(odd>S)
			odd=S;
		res=0;
		printf("Set #%ld\n",kas++);
		for(i=0,j=S-1;i<odd;i++,j--)
		{
			printf("%2ld: %ld\n",i,a[j]);
			cm=a[j]-am;
			if(cm<0)
				cm=-cm;
			res+=cm;
		}
		for(k=0;i<C;i++,j--,k++,odd++)
		{
			printf("%2ld:",i);
			if(odd<S)
			{
			printf(" %ld %ld",a[k],a[j]);
			cm=(a[k]+a[j])-am;
			if(cm<0)
				cm=-cm;
			res+=cm;
			}
			else
				res+=am;
			printf("\n");
		}
		printf("IMBALANCE = %0.5lf\n\n",res);
	}
	return 0;
}