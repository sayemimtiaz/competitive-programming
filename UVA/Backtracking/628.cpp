#include<stdio.h>
long loc[1000],g;
char dic[200][1000],target[2000];
void check(long pos)
{
	if(pos==g)
	{
		printf("%s\n",target);
		return;
	}
	char c;
	for(c='0';c<='9';c++)
	{
		target[loc[pos]]=c;
		check(pos+1);
	}
}
int main()
{
	char wrd[2000];
	long q,n,i,j,k,l,m;
	while(scanf("%ld",&n)==1)
	{
		getchar();
		for(i=0;i<n;i++)
			gets(dic[i]);
		scanf("%ld",&q);
		getchar();
		for(i=0;i<q;i++)
		{
			gets(wrd);
			if(!i)
				printf("--\n");
			for(j=0;j<n;j++)
			{
				l=g=0;
				for(k=0;wrd[k]!='\0';k++)
				{
					if(wrd[k]=='#')
					{
						for(m=0;dic[j][m]!='\0';m++)
							target[l++]=dic[j][m];
					}
					else
					{
						loc[g++]=l;
						l++;
					}
				}
			    target[l]='\0';
				check(0);
			}
		}
	}
	return 0;
}
