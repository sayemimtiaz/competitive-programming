#include<iostream.h>
#include<string.h>
#include<math.h>
bool isprime(int n)
{
	if(n==1)
		return false;
	if(n==2)
		return true;
	if(n%2==0)
		return false;
	for(int i=3;i<=sqrt(n)+1;i+=2)
		if(n%i==0)
			return false;
	return true;
}
int main()
{
	char a[3000],s[3000];
	int test,i,j,k,count,len;
	cin>>test;

	for(i=1;i<=test;i++)
	{
		cin>>a;
		len=strlen(a);
			int index=0;
	int b[3000]={0};
		for(j=0;j<len;j++)
		{
			count=1;
			if(b[j]==0)
			{
			for(k=j+1;k<len;k++)
			{
				if(a[j]==a[k])
				{
					b[k]=1;
					count++;
				}
			}
			if(isprime(count))
			{
				s[index]=a[j];
				index++;
			}
			}
		}
	for(j=0;j<index;j++)
	{
		for(k=j+1;k<index;k++)
		{
			if(s[j]>s[k])
			{
				char temp=s[j];
				s[j]=s[k];
				s[k]=temp;
			}
		}
	}
	cout<<"Case "<<i<<": ";
	if(index!=0)
	{
	for(j=0;j<index;j++)
	{
		cout<<s[j];
	}
	}
	else
		cout<<"empty";
	cout<<endl;
}
return 0;
}
