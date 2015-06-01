#include<string.h>
#include<stdio.h>
char R[5009][1230];
void fibo(int n)
{
	char a[10000]={"0"},b[10000]={"1"},c[10000],t[10000],max_s[10000],min_s[10000];
	int l1,l2, i,j,k,m,sum,hold;
	strcpy(R[0],a);
	strcpy(R[1],b);
	l1=l2=1;
	for(i=2;i<=n;i++)
	{
		k=l1-1;
		m=0;
		hold=0;
		for(j=l2-1;j>=0;j--)
		{
			if(k<0)
			sum=(b[j]-'0')+hold;
			else
			{
				sum=(b[j]-'0')+(a[k]-'0')+hold;
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
		l1=l2;
		l2=m;
		strcpy(R[i],c);
	}
}
int main()
{
	int n;
	fibo(5001);
	while(~scanf("%d",&n))
	{
       printf("The Fibonacci number for %d is %s\n",n,R[n]);
	}
	return 0;
}
