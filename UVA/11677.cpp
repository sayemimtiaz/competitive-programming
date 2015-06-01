#include<iostream.h>
int main()
{
	int h1,m1,h2,m2;
	while(1)
	{
		cin>>h1>>m1>>h2>>m2;
		if(!h1&&!m1&&!h2&&!m2)
			break;
		h1=(60*h1)+m1;
		h2=(60*h2)+m2;
		if(h1<=h2)
			h1=h2-h1;
		else
		{
			h1=1440-h1;
			h1=h2+h1;
		}
		cout<<h1<<endl;
	}
	return 0;
}

