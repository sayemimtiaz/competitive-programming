#include<iostream.h>
#include<math.h>
#include<stdlib.h>
int comp(const void *a,const void *b)
{
	long *x=(long*)a;
	long *y=(long*)b;
	return *x-*y;
}
int main()
{
	int t;
	long a[1000],val,i,j;
	bool flag;
	cin>>t;
	while(t--)
	{
		i=0;
		while(1)
		{
			cin>>a[i];
			if(!a[i])
				break;
			i++;
		}
		val=0;
		flag=true;
		qsort(a,i,sizeof(long),comp);
		for(j=i-1;j>=0;j--)
		{
			val+=(2*pow(a[j],(i-j)));
			if(val>5000000)
			{
				flag=false;
				break;
			}
		}
		if(flag==true)
			cout<<val;
		else
			cout<<"Too expensive";
		cout<<endl;
	
	}
	return 0;
}
