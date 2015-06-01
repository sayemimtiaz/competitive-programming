#include<stdio.h>
int main()
{
	long l,i,dist,d,savedist;
	char ch,save;
	bool flag,fl,yes;
	while(scanf("%ld",&l)==1&&l)
	{
		getchar();
		flag=yes=fl=0;
		for(i=0;i<l;i++)
		{
			ch=getchar();
			if(ch=='.')
				continue;
			if(ch=='Z')
			{
				flag=1;
				dist=0;
			}
			else if(!flag)
			{
				if(!yes)
				{
				  savedist=i+1;
				  save=ch;
				  yes=1;
				}
				else
				{
					if(ch!=save)
					{
						d=i+1-savedist;
						if(!fl)
						{
							fl=1;
							dist=d;
						}
						else if(dist>d)
							dist=d;

					}
					 savedist=i+1;
				      save=ch;
				}
			}
		}
		printf("%ld\n",dist);
	}
	return 0;
}
