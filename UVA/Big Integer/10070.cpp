#include<iostream.h>
#include<string.h>
char str[10000000];
long product(long num)
{
	long i,hold;
	for(i=0,hold=0;i<strlen(str);i++)
	{
		hold=(hold*10+(str[i]-'0'))%num;
	}
	return hold;
}
int main()
{
	bool flag=0,ord=0;
	long a,b,c;
	while(cin>>str)
	{
		bool leap=0;
		ord=1;
		a=product(4);
		b=product(100);
		c=product(400);
		if(flag)
			cout<<endl;;
		flag=1;
		if ((!a && b) || !c)
		{
         leap=1;
          ord=0;
           cout << "This is leap year.\n";
		}
		a=product(15);
         if (!a)
		 {
         ord=0;
         cout << "This is huluculu festival year.\n";
		 }
		 a=product(55);
         if (leap && !a)
		 {
           ord=0;
        cout << "This is bulukulu festival year.\n";
		 }
    if (ord)
       cout << "This is an ordinary year.\n"; 

	}
	return 0;
}