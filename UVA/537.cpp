#include<stdio.h>
char str[1000000];
int main()
{
	char unit[1000],con,c[50000];
	long double d,data[200];
	long kase,i,j,k,kas=1;
    long double prefix[200];
	prefix['m']=0.001;prefix['k']=1000;prefix['M']=1000000;
	scanf("%ld",&kase);
	getchar();
	while(kase--)
	{
		bool flag[200]={0};
		gets(str);
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]=='=')
			{
				c[0]=str[i-1];c[1]=' ';k=2;
				for(j=i+1;(str[j]>='0'&&str[j]<='9')||str[j]=='.';j++)
					c[k++]=str[j];
				c[k++]=' ';c[k++]=str[j];if(str[j+1]=='W'||str[j+1]=='V'||str[j+1]=='A')c[k++]=str[j+1];c[k]='\0';
				sscanf(c,"%c %Lf %s",&con,&d,unit);
				flag[con]=1;
				data[con]=d;
				if(unit[1]!='\0')
					data[con]*=prefix[unit[0]];
			}
		}
		printf("Problem #%ld\n",kas++);
		if(flag['P']&&flag['U'])
			printf("I=%0.2LfA\n",data['P']/data['U']);
		else if(flag['P']&&flag['I'])
			printf("U=%0.2LfV\n",data['P']/data['I']);
		else
			printf("P=%0.2LfW\n",data['U']*data['I']);
		printf("\n");
	}
	return 0;
}
