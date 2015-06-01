#include<stdio.h>
#include<string.h>
int main()
{
	char line[60000],s[60000],temp,h[60000];
	long len,i,j,k,l,max,f,t,g[10000];
	while(gets(line))
	{
		len=strlen(line);
		k=0;
		long b[10000]={0};
		int u=0;
		for(i=0;i<len;i++)
		{
			if(b[i]==0&&((line[i]>='a'&&line[i]<='z')||(line[i]>='A'&&line[i]<='Z')))
			{
				t=1;
				for(j=i+1;j<len;j++)
				{
					if(line[i]==line[j])
					{
						b[j]=1;
						t++;
					}
				}
				if(u==0)
				{
					u=1;
					max=t;
				}
				else if(t>max)
				{
					max=t;
				}
				s[k]=line[i];
				g[k]=t;
				k++;

			}
		}
		f=0;
		for(i=0;i<k;i++)
		{
			if(max==g[i])
			{
				h[f]=s[i];
				f++;
			}
		}
		for(i=0;i<f;i++)
		{
			for(j=i+1;j<f;j++)
			{
				if(h[i]>h[j])
				{
					temp=h[i];
					h[i]=h[j];
					h[j]=temp;
				}
			}
		}
		for(i=0;i<f;i++)
			printf("%c",h[i]);
		printf(" %ld\n",max);
	}
	return 0;
}
