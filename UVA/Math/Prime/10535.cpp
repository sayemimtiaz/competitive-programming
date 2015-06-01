#include<stdio.h>
#include<math.h>
int p[1000000]={0};
long pr[1000000];
int main()
{
	long test,a,b,i,j,count,add;
	a=1000000;
	b=(int)sqrt(a);
	for(i=2;i<=b;i++)
		if(p[i]==0)
		 for(j=i*i;j<1000000;j+=i)
			p[j]=1;
		 count=0;
	for(i=2;i<1000000;i++)
	{
		if(p[i]==0)
		{
			add=0;
			j=i;
			while(j)
			{
				add+=(j%10);
				j=j/10;
				if(j<10)
				{
					add+=j;
					break;
				}
			}
			if(p[add]==0)
				count++;
		}
			pr[i]=count;
	}
	scanf("%ld",&test);
	while(test--)
	{
		scanf("%ld %ld",&a,&b);
		printf("%ld\n",pr[b]-pr[a-1]);
	}
	return 0;
}