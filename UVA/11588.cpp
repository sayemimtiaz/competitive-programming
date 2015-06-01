#include<iostream.h>
#include<string.h>
int main()
{
	char grid[80][80];
	long s[10000],fr[10000];
	bool f;
	long kase,r,c,m,n,i,j,k,l,a,max;
	cin>>kase;
	for(i=1;i<=kase;i++)
	{
		cin>>r>>c>>m>>n;
		memset(fr,0,sizeof(fr));
		f=1;
		j=0;
		for(l=0;l<r;l++)
		{
			for(k=0;k<c;k++)
			{
				cin>>grid[l][k];
				a=(int)grid[l][k]-65;
				fr[a]++;
			if(f)
			{
				f=0;
				max=fr[a];
				s[j++]=max;
			}
			else if(fr[a]>max)
			{
				j=0;
				max=fr[a];
				s[j++]=max;
			}
			else if(fr[a]==max)
			{
				s[j++]=fr[a];
			}
			}
		
		}
		a=0;
		for(k=0;k<j;k++)
		{
			a+=s[k];
		}
		r=(r*c)-a;
		a=(a*m)+(r*n);
		cout<<"Case "<<i<<": "<<a<<endl;

	}
	return 0;
}