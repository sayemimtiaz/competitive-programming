#include<stdio.h>
long s[1000000];
int main()
{
	char str[5000];
	long i,cnt,t;
	bool flag;
	while(gets(str))
	{
		bool used[5000]={0};
		t=cnt=0;
		flag=0;
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]=='('||str[i]=='{'||str[i]=='['||str[i]=='<')
			{
				cnt++;
				s[t++]=str[i];
				if(str[i]=='('&&str[i+1]=='*')
				{
					used[i+1]=1;
					s[t++]=str[i+1];
					i++;
				}
			}
			else if(str[i]=='*'&&!used[i]&&str[i+1]==')')
			{
				cnt++;
				i++;
				if(!t)
				{
					flag=1;
					break;
				}
				t--;
				if(s[t--]!='*'||s[t]!='(')
				{
						flag=1;
						break;
				}
			}
			else if(str[i]==')')
			{
				cnt++;
				if(!t)
				{
					flag=1;
					break;
				}
				t--;
				 if(s[t]!='(')
				{
					flag=1;
					break;
				}
			}
			else if(str[i]=='}')
			{
				cnt++;
				if(!t)
				{
					flag=1;
					break;
				}
				t--;
				if(s[t]!='{')
				{
					flag=1;
					break;
				}
			}
			else if(str[i]=='>')
			{
				cnt++;
		        if(!t)
				{
					flag=1;
					break;
				}
				t--;
				if(s[t]!='<')
				{
					flag=1;
					break;
				}
			}
			else if(str[i]==']')
			{
				cnt++;
				if(!t)
				{
					flag=1;
					break;
				}
				t--;
				if(s[t]!='[')
				{
					flag=1;
					break;
				}
			}
			else
			{
				cnt++;
				}
		}
		if(!flag&&t)
		{
			cnt++;
			flag=1;
		}
		if(flag)
			printf("NO %ld\n",cnt);
		else
			printf("YES\n");

	}
	return 0;
}