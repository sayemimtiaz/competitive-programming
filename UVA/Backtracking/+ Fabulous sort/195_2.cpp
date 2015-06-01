#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int man[100000];
int cmp(char x,char y)
{
	return man[x]<man[y];
}
int main()
{
	long len,kase,i,j,k;
	k=1;
	for(i='A',j='a';i<='Z';i++,j++)
	{
		man[i]=k;
		man[j]=k+1;
		k+=2;
	}
	char seq[1000];
	scanf("%ld",&kase);
	getchar();
	while(kase--)
	{
		gets(seq);
		len=strlen(seq);
	    sort(seq,seq+len,cmp);
		do
		{
				printf("%s\n",seq);
		}
        while(next_permutation(seq,seq+len,cmp));
		
	}
	return 0;
}