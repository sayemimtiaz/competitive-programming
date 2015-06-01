#include<iostream.h>
#include<string.h>
void fibo(long n)
{
	char a[10000]={"0"},b[10000]={"1"},c[10000],t[10000],max_s[10000],min_s[10000];
	long l1,l2,i, j,k,m,sum,hold,max,min;
	for(i=1;i<=n;i++)
	{
		l1=strlen(a);
		l2=strlen(b);
		if(l1>l2)
		{
			max=l1;
			min=l2;
			strcpy(max_s,a);
			strcpy(min_s,b);
		}
		else
		{
			max=l2;
			min=l1;
			strcpy(max_s,b);
			strcpy(min_s,a);
		}
		k=min-1;
		m=0;
		hold=0;
		for(j=max-1;j>=0;j--)
		{
			if(k<0)
			sum=(max_s[j]-'0')+hold;
			else
			{
				sum=(max_s[j]-'0')+(min_s[k]-'0')+hold;
				k--;
			}
			t[m]=sum%10+'0';
			hold=sum/10;
			m++;
		}
		if(hold!=0)
		{
		  t[m]=hold+'0';
		  m++;
		}
		t[m]='\0';
		k=m-1;
		for(j=0;j<m;j++)
		{
			c[j]=t[k];
			k--;
		}
		c[j]='\0';
		strcpy(a,b);
		strcpy(b,c);

	}
	cout<<c;
}
int main()
{
	long n;
	while(cin>>n)
	{
		fibo(n+1);
		cout<<"\n";
	}
	return 0;
}