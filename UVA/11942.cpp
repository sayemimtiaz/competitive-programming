#include<stdio.h>
int main()
{
	int kase,a,b,i;
	bool d,skip;
	scanf("%d",&kase);
	printf("Lumberjacks:\n");
	while(kase--)
	{
		scanf("%d %d",&a,&b);
		d=(a>b)?1:0;
		skip=0;
		for(i=2;i<10;i++)
		{
			scanf("%d",&a);
			if(!skip)
			 if((d&&a>b)||(!d&&a<b))
				skip=1;
			 b=a;
		}
		if(skip)
			printf("Unordered");
		else
			printf("Ordered");
		printf("\n");
	}
	return 0;
}