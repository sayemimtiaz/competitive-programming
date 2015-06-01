#include<stdio.h>
#include<string.h>
long a[1000000],len[1000000];
int main()
{
	long ka=1,i,j,k;
	long max;
	while(1)
	{
		scanf("%ld",&a[0]);
		if(a[0]==-1)
			break;
		i=1;
		while(1)
		{
			scanf("%ld",&a[i]);
			if(a[i]==-1)
				break;
			i++;
		}
		memset(len,0,sizeof(len));
		max=0;
		for(j=0;j<i-1;j++)
			for(k=j+1;k<i;k++)
				if(a[k]<a[j])
				if(len[j]+1>len[k])
				{
					len[k]=len[j]+1;
					if(max<len[k])
						max=len[k];
				}
				if(ka!=1)
					printf("\n");
				printf("Test #%ld:\n  maximum possible interceptions: %ld\n",ka++,max+1);
	}
			

	return 0;
}