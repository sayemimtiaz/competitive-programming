#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct T
{
	char ch;
	long vl;
}gr[1000000];
char str[1000000],st[1000000],ch[1000000];
int cmp(const void *a,const void *b)
{
	T *x=(T*)a;
	T *y=(T*)b;
	return (x->ch-y->ch);
}
int main()
{
	char savend;
	long i,j,len,value,loctr,locend,index;
	bool got;
	while(gets(st))
	{
		j=0;
		for(i=0;st[i]!='\0';i++)
		{
			if(st[i]==' ')
				continue;
			str[j++]=st[i];
		}
		str[j]='\0';
		long flag[1000]={0};
		long val[1000]={0};
		savend='+';
		got=0;
		value=0;
		index=1;
		loctr=locend=0;
		for(i=0;i<j;i++)
		{
			if(str[i]!='+'&&str[i]!='-'&&!flag[str[i]])
				{
					gr[index-1].ch=str[i];
					gr[index-1].vl=str[i]-96;
					val[index]=str[i]-96;
					flag[str[i]]=index++;
				}
			if(str[i]=='+'||str[i]=='-')
			{
				if(str[i]==savend&&locend>loctr)
				{
					if((i-2)>=0&&str[i-2]!='-'&&str[i-2]!='+')
					{
						if(savend=='+')
						{
						   val[flag[str[i-2]]]++;
						   gr[flag[str[i-2]]-1].vl=val[flag[str[i-2]]];
						}
						else
						{
							 val[flag[str[i-2]]]--;
							 gr[flag[str[i-2]]-1].vl=val[flag[str[i-2]]];
						}
						got=0;
					}
					else
					{
							if(!flag[str[i+1]])
							{
								gr[index-1].ch=str[i+1];
					            gr[index-1].vl=str[i+1]-96;
								val[index]=str[i+1]-96;
								flag[str[i+1]]=index++;
							}
						if(savend=='+')
						{
						   val[flag[str[i+1]]]++;
						   gr[flag[str[i+1]]-1].vl=val[flag[str[i+1]]];
						}
						else
						{
							 val[flag[str[i+1]]]--;
							 gr[flag[str[i+1]]-1].vl=val[flag[str[i+1]]];
						}
						got=1;

					}
				}
				savend=str[i];
				locend=i+1;
			}
			else
			{
				if(got)
				{
					if((i-3)>=0)
					{
						if(str[i-3]=='+')
							value+=val[flag[str[i]]];
						else
							value-=val[flag[str[i]]];
					}
					else 
						value+=val[flag[str[i]]];
					got=0;
				}
				else
				{
				if(savend=='+')
				    value+=(str[i]-96);
				else
				    value-=(str[i]-96);
				}
				loctr=i+1;
			}
		}
		qsort(gr,index-1,sizeof(T),cmp);
		printf("Expression: %s\n%4cvalue = %ld\n",st,' ',value);
		for(i=1;i<index;i++)
			printf("%5c = %ld\n",gr[i-1].ch,gr[i-1].vl);
	}
	return 0;
}