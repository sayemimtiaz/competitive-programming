#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
long p;
struct S
{
	char str[50];
	 long val;
}s[100];
int cmp(const void *a,const void *b)
{
	S *x=(S*)a;
	S *y=(S*)b;
	return (strcmp(x->str,y->str));
}
long binser(char *ch)
{
	long b,e;
	long m;
	b=0;
	e=p-1;
	while(b<=e)
	{
		m=(b+e)/2;
		if(!strcmp(s[m].str,ch))
			return m;
		else if(strcmp(s[m].str,ch)>0)
			e=m-1;
		else
			b=m+1;
	}
	return 10;
}
int main()
{
	char c[50000],sign[50000],ch[50000];
	long after,before,len,i,j,k,g,pos,com,n;
	while(scanf("%ld %ld",&p,&g)==2)
	{
		for(i=0;i<p;i++)
		{
			scanf("%s %ld.%ld",s[i].str,&before,&after);
			s[i].val=before*10+after;
		}
		qsort(s,p,sizeof(S),cmp);
		getchar();
		for(i=0;i<g;i++)
		{
			gets(ch);
			len=strlen(ch);
			j=0;
			com=0;
		    bool Nflag=0;
			for(k=0;k<=len;k++)
			{
				if(ch[k]==' '||ch[k]=='\0')
				{
					c[j]='\0';
					if(j!=0&&c[0]!='+')
					{
						if(c[0]=='<'||c[0]=='>'||c[0]=='=')
						{
							Nflag=1;
							strcpy(sign,c);
						}
						else if(Nflag)
							n=atol(c);
						else
						{
							pos=binser(c);
							com+=s[pos].val;
						}
					}
					j=0;
				}
				else
					c[j++]=ch[k];
			}
			n=n*10;
			bool result;
			    if ( !strcmp (sign, "<") )
        result = (com < n) ? true : false;

    else if ( !strcmp (sign,  ">") )
        result = (com> n) ? true : false;

    else if ( !strcmp (sign, "<=") )
        result = (com <= n) ? true : false;

    else if ( !strcmp (sign, ">=") )
        result = (com >= n) ? true : false;

    else if ( !strcmp (sign, "=") )
        result = (com == n) ? true : false;

    else result = false;
			if(result)
				printf("Guess #%ld was correct.\n",i+1);
			else
			printf("Guess #%ld was incorrect.\n",i+1);
		}
	}
	return 0;
}