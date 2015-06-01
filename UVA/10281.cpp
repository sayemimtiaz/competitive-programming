#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	char str[10000];
	double d,s,h,m,cur,ph,pm,ps,pcur,scur,len,sps;
	bool flag=1;
	while(gets(str))
	{
		len=strlen(str);
		if(len==8)
		{
			sscanf(str,"%lf:%lf:%lf",&h,&m,&s);
			s=(h*3600)+(m*60)+s;
			d=pcur+((s-ps)*cur)/3600;
			printf("%s %0.2lf km\n",str,d);
		}
		else
		{
			sscanf(str,"%lf:%lf:%lf %lf",&ph,&pm,&ps,&cur);
			if(flag)
			{
				pcur=0;
				flag=0;
			}
			else
				pcur+=((((ph*3600)+(pm*60)+ps)-sps)*scur)/3600;
			ps=(ph*3600)+(pm*60)+ps;
			scur=cur;
			sps=ps;
		}

	}
	return 0;
}