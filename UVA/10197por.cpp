#include<iostream.h>
#include<string.h>
char suf[10]={'a','e','i'};
char con[100][100]={"s","mos","is","m"};
char pro[100][100]={"eu","tu","ele/ela","eles/elas"};
int main()
{
	char v1[100],v2[100],root[100];
	int len,i,j,k,dx1,dx2,sp,h=0;
	while(cin>>v1>>v2)
	{
		len=strlen(v1);
		if(h!=0)
			cout<<"\n";
		h=1;
		if(v1[len-1]=='r')
		{
			for(i=0;i<3;i++)
			{
				if(suf[i]==v1[len-2])
				{
					break;
				}
			}
			if(i==3)
					cout<<v1<<" "<<"(to "<<v2<<")\nUnknown conjugation\n";
			else
			{
				for(j=0;j<len-2;j++)
					root[j]=v1[j];
				root[j]='\0';
				cout<<v1<<" "<<"(to "<<v2<<")"<<endl;	
				dx1=dx2=0;
				for(j=0;j<6;j++)
				{
					if(j==3)
					{
						cout<<"n"<<(char)243<<"s";
						sp=3;
					}
					else if(j==4)
					{
						cout<<"v"<<(char)243<<"s";
						sp=3;
					}
					else
					{
					  cout<<pro[dx1];
					  sp=strlen(pro[dx1]);
					  dx1++;
					}
					for(k=0;k<10-sp;k++)
						cout<<" ";
					cout<<root;
					if(j==0)
						cout<<"o";
					else if(j==2)
					{
						if(i==2)
							cout<<"e";
						else
						cout<<suf[i];
					}
					else
					{
						if(j==1&&i==2)
							cout<<"es";
						else if(j==4&&i==2)
							cout<<"is";
						else if(j==5&&i==2)
							cout<<"em";
						else
						{
						cout<<suf[i]<<con[dx2];
						}
						dx2++;
					}
					cout<<endl;
				}
			}


		}
		else
			cout<<v1<<" "<<"(to "<<v2<<")\nUnknown conjugation\n";
	}
	return 0;
}
