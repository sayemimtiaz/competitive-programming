#include<stdio.h>
int main()
{
	int e,f,c,t,tot;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&e,&f,&c);
		e=e+f;
		tot=0;
		while(1)
		{
			if(e<c)
				break;
			f=e/c;
			e=f+(e%c);
			tot+=f;
		}
		printf("%d\n",tot);
	}
	return 0;
}
