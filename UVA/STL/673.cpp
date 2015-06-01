#include<cstdio>
#include<stack>
using namespace std;
stack<char>s;
int main()
{
	char ch,a;
	bool flag;
	long n;
	scanf("%ld",&n);
	getchar();
	while(n--)
	{
		flag=0;
		while(ch=getchar())
		{
			if(ch=='\n')
				break;
			if(ch=='('||ch=='[')
			    s.push(ch);
			else
			{
				if(s.empty())
					flag=1;
				else
				{
					a=s.top();
					s.pop();
					if(ch==')'&&a!='(')
						flag=1;
					else if(ch==']'&&a!='[')
						flag=1;
				}
			}
		}
		if(!flag)
		{
			if(s.empty())
				printf("Yes\n");
			else
				printf("No\n");
		}
		else
			printf("No\n");
		while(!s.empty())
			s.pop();
	}
	return 0;
}