#include<stdio.h>
#include<string.h>
long w[1000000],l[1000000];
int main()
{
	double r;
	char a[3]={'r','p','s'};
	char b[3]={'p','s','r'};
	long c,d,e,f,i,j,im;
	char s1[1000],s2[1000];
	bool flag,inter;
	flag=false;
	while(1)
	{
		scanf("%ld",&c);
		if(!c)
			break;
		scanf("%ld",&d);
		im=c*d*(c-1);
		im=im/2;
		memset(w,0,sizeof(w));
		memset(l,0,sizeof(l));
		for(i=0;i<im;i++)
		{
			scanf("%ld %s %ld %s",&e,s1,&f,s2);
			if(s1[0]!=s2[0])
			{
			for(j=0;j<3;j++)
			{
				if(a[j]==s1[0])
				{
					if(b[j]==s2[0])
					{
						w[f]++;
						l[e]++;
					
					}
					else
					{
						w[e]++;
						l[f]++;
					
					}
						break;
				}
			}
			}
		}
		if(flag)
			printf("\n");
		flag=true;
		for(i=1;i<=c;i++)
		{
			if(w[i]==0&&l[i]==0)
				printf("-\n");
			else
			{
			r=w[i]/(double)(w[i]+l[i]);
			printf("%0.3lf\n",r);
			}
		}

	}
	return 0;
}