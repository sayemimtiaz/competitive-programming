#include<stdio.h>
#include<string.h>
char dic[2000][2000];
int main()
{
	char wrd[2000];
	long i,j,k,n,kase;
	bool kas=0;
	scanf("%ld",&kase);
	while(kase--)
	{
		scanf("%ld",&n);
		for(i=0;i<n;i++)
			scanf("%s",dic[i]);
		bool ka=0;
		while(scanf("%s",wrd)==1&&strcmp(wrd,"END"))
		{
			if(kas&&!ka)
				printf("\n");
			ka=1;
			k=1;
			bool flag[200]={0};
			long fr[200]={0};
			bool prnd=0,yes;
			for(i=0;wrd[i]!='\0';i++)
			{
				fr[wrd[i]]++;
				flag[wrd[i]]=1;
			}
			printf("Anagrams for: %s\n",wrd);
			for(i=0;i<n;i++)
			{
				long f[200]={0};
				yes=1;
				for(j=0;dic[i][j]!='\0';j++)
				{
					if(!flag[dic[i][j]])
					{
						yes=0;
						break;
					}
				  f[dic[i][j]]++;
				}
				if(yes)
				{	
					for(j=0;wrd[j]!='\0';j++)
					{
				         if(fr[wrd[j]]!=f[wrd[j]])
						 {
							 yes=0;
							 break;
						 }
					}
				}
				if(yes)
				{
					prnd=1;
					printf("%3ld) %s\n",k++,dic[i]);
				}
			}
			if(!prnd)
				printf("No anagrams for: %s\n",wrd);
		}
		kas=1;
	}
	return 0;
}