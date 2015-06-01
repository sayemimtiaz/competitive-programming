#include<stdio.h>
int main()
{
	int t,m,f;
	char ch;
	scanf("%d\n",&t);
	while(t--)
	{
		m=f=0;
		while(ch=getchar())
		{
			if(ch=='\n')
				break;
			if(ch=='M')
				m++;
			else if(ch=='F')
				f++;
		}
		if(m==f&&m!=1&&f!=1)
			printf("LOOP");
		else
			printf("NO LOOP");
		printf("\n");
	}
	return 0;
}