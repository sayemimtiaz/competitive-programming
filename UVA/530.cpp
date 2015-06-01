#include<iostream.h>
long a[1000000],b[1000000];
int main()
{
	  long n,r,i,j,k,max,min,l,c;
	  unsigned  long long res;
	bool flag;
	while(1)
	{
	cin>>n>>r;
		if(!n&&!r)
			break;
		c=n-r;
		if(!r||!c)
			res=1;
		else if(c==1||r==1)
			res=n;
		else
		{
		max=(c>r)?c:r;
		min=(c>r)?r:c;
		j=0;
		for(i=1;i<=n;i++)
		{
			if(i>max)
			{
				a[j]=i;
				j++;
			}
		}
		n=1;
		l=0;
		for(i=2;i<=min;i++)
		{
			flag=false;
			for(k=j-1;k>=0;k--)
			{
				if(a[k]%i==0)
				{
					flag=true;
					a[k]=a[k]/i;
					break;
				}
			}
			if(!flag)
			{
				b[l]=i;
				l++;
			}
		}
		res=1;
		for(i=0;i<j;i++)
		{
			res=res*a[i];
			for(k=0;k<l;k++)
			{
				if(b[k]&&res%b[k]==0)
				{
					res=res/b[k];
					b[k]=0;
				}
			}
		}
		}
		cout<<res<<endl;

	}
	return 0;
}