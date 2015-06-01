#include<stdio.h>
#include<string.h>
#include<math.h>
#include<iostream.h>
int b[100000],flag;
int main()
{
	char a;
	long j,i,c;
	double val;
	while(1)
	{
		a=getchar();
		if(a=='~')
			break;
		i=1;
		c=0;
		while(1)
		{
			scanf("%c",&a);
			if(a=='#')
				break;
			if(a==' ')
			{
				if(i==1)
				{
					cout<<"*";
					flag=1;
				}
				else if(i==2)
					flag=0;
				else
				{
					cout<<"#";
					i=i-2;
					for(j=c;j<c+i;j++)
						b[j]=flag;
					c=i;
				}
				i=0;
			}

			else
			i++;
		}
		//cout<<b[i]<<endl;
		c=j-1;
		val=0;
		for(i=0;i<j;i++)
		{
			val+=(b[i]*pow(2,c));
			c--;
		}
		printf("%0.lf\n",val);
	}
	return 0;
}