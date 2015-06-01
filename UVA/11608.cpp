#include<stdio.h>
int main()
{
	int p,cr[12],re[12],i,j;
	j=1;
	while(1)
	{
		scanf("%d",&p);
		if(p<0)
			break;
		for(i=0;i<12;i++)
			scanf("%d",&cr[i]);
		for(i=0;i<12;i++)
			scanf("%d",&re[i]);
		printf("Case %d:\n",j);
		j++;
		for(i=0;i<12;i++)
		{
			if(p>=re[i])
			{
				printf("No problem! :D");
				p=p-re[i];
				p=cr[i]+p;
			}
			else
			{
				printf("No problem. :(");
				p=cr[i]+p;
			}
			printf("\n");
		}
	}
	return 0;
}
