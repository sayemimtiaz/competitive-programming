#include<stdio.h>
#include<string.h>
char judg[120][10000];
int main()
{
	char in[10000],ch1[10000],ch2[10000];
	long n1,n2,i,j,k,kas=1,match;
	bool flag;
	while(scanf("%ld",&n1)==1&&n1)
	{
		getchar();
		k=0;
		for(i=0;i<n1;i++)
		{
			gets(judg[i]);
			for(j=0;judg[i][j]!='\0';j++)
				if(judg[i][j]>='0'&&judg[i][j]<='9')
					ch1[k++]=judg[i][j];
		}
		ch1[k]='\0';
		scanf("%ld",&n2);
		getchar();
		flag=0;
		match=0;
		k=0;
		for(i=0;i<n2;i++)
		{
			gets(in);
			if(!strcmp(judg[i],in))
				match++;
			for(j=0;in[j]!='\0';j++)
					if(in[j]>='0'&&in[j]<='9')
						ch2[k++]=in[j];
		}
		ch2[k]='\0';
		printf("Run #%ld: ",kas++);
		if(match==n1&&n1==n2)
			printf("Accepted\n");
		else if(strcmp(ch1,ch2))
			printf("Wrong Answer\n");
		else
			printf("Presentation Error\n");
	}
	return 0;
}