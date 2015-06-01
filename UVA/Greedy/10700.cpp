#include<stdio.h>
#include<stdlib.h>
long double num[200],cpy[200];
char sign[200];
long N,S;
void ager(char ch)
{
	long i;
	for(i=0;i<S;i++)
	{
		if(sign[i]==ch)
		{
			if(ch=='*')
				cpy[i+1]*=cpy[i];
			else
				cpy[i+1]+=cpy[i];
			cpy[i]=-1;
		}
	}
}
void pore(char ch)
{
	long i,j,got,in[3];
	for(i=0;i<S;i++)
	{
		if(sign[i]==ch)
		{
				got=0;
				for(j=0;j<N;j++)
				{
					if(cpy[j]!=-1)
					{
						in[got++]=j;
					}
					if(got==2)
						break;
				}
				if(ch=='+')
				cpy[in[1]]+=cpy[in[0]];
				else
					cpy[in[1]]*=cpy[in[0]];
				cpy[in[0]]=-1;
			}
		}
}
int main()
{
	long kase,i,j;
	char ch[100],str[1000];
	scanf("%ld",&kase);
	getchar();
	while(kase--)
	{
		j=N=S=0;
		gets(str);
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]=='*'||str[i]=='+')
			{
				ch[j]='\0';
				num[N]=atoi(ch);
				cpy[N]=num[N];
				N++;
				sign[S++]=str[i];
				j=0;
			}
			else
				ch[j++]=str[i];
		}
		ch[j]='\0';
		num[N]=atoi(ch);cpy[N]=num[N];N++;
		ager('+');
		pore('*');
		printf("The maximum and minimum are ");
		printf("%0.Lf ",cpy[N-1]);
		for(i=0;i<N;i++)
			cpy[i]=num[i];
		ager('*');
		pore('+');
		printf("and %0.Lf.\n",cpy[N-1]);

	}
	return 0;
}