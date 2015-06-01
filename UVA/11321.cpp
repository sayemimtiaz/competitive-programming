#include<stdio.h>
#include<stdlib.h>
struct S
{
long a,b;
}gr[10004];
int comp(const void *p,const void *q)
{
	S *x=(S*)p;
	S *y=(S*)q;
	if(x->b!=y->b)
		return x->b-y->b;
	if(x->a%2==0&&y->a%2)
		return 1;
	if(x->a%2&&y->a%2==0)
		return -1;
	if(x->a%2&&y->a%2&&x->a<y->a)
		return 1;
	if(x->a%2&&y->a%2&&x->a>y->a)
		return -1;
	if(x->a%2==0&&y->a%2==0&&x->a>y->a)
		return 1;
	if(x->a%2==0&&y->a%2==0&&x->a<y->a)
		return -1;
	return 0;

}
int main()
{
	long i,m,n;
	while(1)
	{
		scanf("%ld %ld",&m,&n);
		if(!m&&!n)
			break;
		for(i=0;i<m;i++)
		{
			scanf("%ld",&gr[i].a);
			gr[i].b=gr[i].a%n;
		}
		qsort(gr,m,sizeof(S),comp);
		printf("%ld %ld\n",m,n);
		for(i=0;i<m;i++)
		{
			printf("%ld\n",gr[i].a);
		}
	}
	printf("0 0\n");
	return 0;
}