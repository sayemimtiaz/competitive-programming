#include<stdio.h>
int main()
{
	int h=0;
	int n,a[10000],i,j,k,l,m,o;
	while(1)
	{
		scanf("%d",&n);
		if(!n)
			break;
		if(h)
				printf("\n");
		h=1;

		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n-5;i++)
			for(j=i+1;j<n-4;j++)
				for(k=j+1;k<n-3;k++)
					for(l=k+1;l<n-2;l++)
						for(m=l+1;m<n-1;m++)
							for(o=m+1;o<n;o++)
								printf("%d %d %d %d %d %d\n",a[i],a[j],a[k],a[l],a[m],a[o]);
	
	}
	return 0;
}