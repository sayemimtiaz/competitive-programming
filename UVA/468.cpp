#include<stdio.h>
#include<stdlib.h>
struct T1
{
	long fr;
	char c;
}g1[1000];
struct T2
{
	long fr;
	char c;
}g2[1000];
char str[1000000];
int cmp1(const void *a,const void *b)
{
	T1 *x=(T1*)a;
	T1 *y=(T1*)b;
	return (x->fr-y->fr);
}
int cmp2(const void *a,const void *b)
{
	T2 *x=(T2*)a;
	T2 *y=(T2*)b;
	return (x->fr-y->fr);
}
int main()
{
	bool yes=0;
	char map[200];
	long n,i,k,flag[200],index,l,j;
	scanf("%ld",&n);
	getchar();
	while(n--)
	{
		getchar();
		gets(str);
		
		for(i='a',k='A';i<='z';k++,i++)
		{
			map[i]=char(i);map[k]=char(k);
		}
		for(i=0;i<200;i++)
		{
			flag[i]=-1;flag[k]=-1;
			g1[i].fr=0;g1[k].fr=0;
		}
		j=0;
		for(i=0;str[i]!='\0';i++)
		{
				if(flag[str[i]]!=-1)
					index=flag[str[i]];
				else
				{
					flag[str[i]]=j;
					index=j;j++;
				}
				g1[index].c=str[i];
				g1[index].fr++;
		}
		qsort(g1,j,sizeof(T1),cmp1);
		for(i=0;i<200;i++)
		{
			flag[i]=-1;flag[k]=-1;
			g2[i].fr=0;g2[k].fr=0;
		}
		gets(str);
		k=0;
		for(i=0;str[i]!='\0';i++)
		{
				if(flag[str[i]]!=-1)
					index=flag[str[i]];
				else
				{
					flag[str[i]]=k;
					index=k;k++;
				}
				g2[index].c=str[i];
				g2[index].fr++;
		}
		qsort(g2,k,sizeof(T2),cmp2);
		i=k-1;l=j-1;
		while(i>=0&&l>=0)
		{
			map[g2[i].c]=g1[l].c;
			i--;l--;
		}
		if(yes)
			printf("\n");
		yes=1;
		for(i=0;str[i]!='\0';i++)
			printf("%c",map[str[i]]);
		printf("\n");
	}
	return 0;
}