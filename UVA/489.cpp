#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,l1,l2,count_yes,count_no,flag,j;
	char ch,a[10000],b[10000];
	while(1)
	{
		scanf("%d",&n);
		if(n==-1)
			break;
		scanf("%s %s",a,b);
		l1=strlen(a);
		l2=strlen(b);
		count_yes=0;
		count_no=0;
		int t[10000]={0};
		for(i=0;i<l2;i++)
		{
			flag=0;
			for(j=0;j<l1;j++)
			{
				if(b[i]==a[j]&&t[j]==0)
				{
					t[j]=1;
					flag=1;
					count_yes++;
				}
			}
			if(count_yes==l1)
				break;
		
			if(flag==0)
				count_no++;
				if(count_no>=7)
				break;
		}
		printf("Round %d\n",n);
		if(count_yes==l1)
			printf("You win.");
		else if(count_no<7)
			printf("You chickened out.");
		else
			printf("You lose.");
		printf("\n");
	}
	return 0;
}


