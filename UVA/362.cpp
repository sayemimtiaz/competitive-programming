#include<iostream.h>
#include<math.h>
int main()
{
	long byte,sum,s,i,j,set=1,rem,a[10000];
	double sec;
	while(1)
	{
		cin>>byte;
		if(!byte)
			break;
		i=sum=0;
		while(1)
		{
			if(sum==byte)
				break;
			cin>>a[i];
			sum+=a[i];
			i++;
		}
		sum=0;
		s=0;
		if(set!=1)
			cout<<endl;
		cout<<"Output for data set "<<set<<", "<<byte<<" bytes:\n";
		set++;
		for(j=1;j<=i;j++)
		{
			if(j%5!=0)
			 sum+=a[j-1];
			else
			{
				sum+=a[j-1];
				s+=sum;
				rem=byte-s;
				sum/=5;
				if(sum==0)
					cout<<"   Time remaining: stalled";
				else
				{
				sec=rem/(double)sum;
				sec=ceil(sec);
				cout<<"   Time remaining: "<<sec<<" seconds";
				}
				sum=0;
				cout<<endl;
			}
		}
		cout<<"Total time: "<<i<<" seconds\n";
	}
	return 0;
}



