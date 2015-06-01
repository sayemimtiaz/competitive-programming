#include<stdio.h>
#include<stdlib.h>
#include<string.h>
long k;
typedef struct
{
	char s1[50];
	char s2[50];
}record;
record rec[100500];
int comp(const void *a,const void *b)
{
	record *x=(record*)a;
	record *y=(record*)b;
	return (strcmp(x->s2,y->s2));
}
long binser(char *st)
{
	long s,e,m;
	s=0;
	e=k-1;
	while(s<=e)
	{
		m=(s+e)/2;
		if(!strcmp(st,rec[m].s2))
			return m;
		else if(strcmp(st,rec[m].s2)<0)
			e=m-1;
		else
			s=m+1;
	}
	return -1;
}
int main()
{
	char line[10000],ch[10000];
	long pos,i,j,len;
	k=0;
	while(gets(line))
	{
		j=0;
		len=strlen(line);
		if(!len)
			break;
		for(i=0;i<=len;i++)
		{
			if(line[i]==' '||line[i]=='\0')
			{
				ch[j]='\0';
				if(line[i]==' ')
				  strcpy(rec[k].s1,ch);
				else
					 strcpy(rec[k].s2,ch);
				j=0;
			}
			else
				ch[j++]=line[i];
		}
		k++;
	}
	qsort(rec,k,sizeof(record),comp);
	while(gets(line))
	{
		pos=binser(line);
		if(pos==-1)
			printf("eh\n");
		else
		printf("%s\n",rec[pos].s1);
	}
	return 0;
}