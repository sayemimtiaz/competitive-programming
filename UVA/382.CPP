#include<iostream.h>

 int main()
  {
    long int a;
	 int g=0;
	while(cin>>a)
	{
		if(a==0)
			break;
		long int sum=0;
     for(int i=1;i<=a/2;i++)
	  {
	    if(a%i==0)
		{
		   sum=sum+i;
		}
	  }
	cout.setf(ios::right);
	if(g==0)
	{
		g=1;
    cout<<"PERFECTION OUTPUT\n";
	}
	cout.width(5);
	  if(sum==a)
		  cout<<a<<"  PERFECT\n";
	  else if(sum>a)
		  cout<<a<<"  ABUNDANT\n";
	  else if(sum<a)
	      cout<<a<<"  DEFICIENT\n";
    }
	cout<<"END OF OUTPUT\n";
    return 0;
  }