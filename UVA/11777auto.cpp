#include<iostream.h>
int main()
{
	long t1,t2,final,att,c1,c2,c3,small,b1,b2;
	int test;
	cin>>test;
	for(int i=1;i<=test;i++)
	{
		cin>>t1>>t2>>final>>att>>c1>>c2>>c3;
		b1=(c1>c2)?c1:c2;
		small=(c1>c2)?c2:c1;
		b2=(c3>small)?c3:small;
		small=(b1+b2)/2;
		small=t1+t2+final+att+small;
		cout<<"Case "<<i<<": ";
		if(small>=90)
			cout<<"A";
		else if(small>=80)
			cout<<"B";
		else if(small>=70)
			cout<<"C";
		else if(small>=60)
			cout<<"D";
		else
			cout<<"F";
		cout<<endl;
	}
	return 0;
}