#include<iostream.h>
#include<string.h>
void fibo(char a[],char b[])
{
	char max_s[1000],min_s[1000];
	long l1,l2,i, j,k,m,sum,hold,max,min;
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
			hold=sum/10;
			if(hold!=0)
			m++;
		}
		if(m==0)
		cout<<"No carry operation.";
		else if(m==1)
			cout<<"1 carry operation.";
		else
			cout<<m<<" carry operations.";
}
int main()
{
	char a[1000],b[1000];
	while(1)
	{
		cin>>a>>b;
		if(*a=='0'&&*b=='0')
			break;
		fibo(a,b);
		cout<<"\n";
	}
	return 0;
}