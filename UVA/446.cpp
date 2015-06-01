#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
	char hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	char hex_val[16][10]={"0000","0001","0010","0011","0100","0101","0110","0111","1000","1001",
		"1010","1011","1100","1101","1110","1111"};
	int dec_val[16]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	int t,a1,a2,i,j,k,len;
	char n1[10],n2[10],s;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s %c %s",&n1,&s,&n2);
		len=strlen(n1);
		a1=a2=0;
		if(len==4)
		{
			i=1;
			printf("1");
		}
		else
		{
		for(i=0;i<(13-(len*4));i++)
			printf("0");
		i=0;
		}
		k=len-1;
		for(;i<len;i++)
		{
			for(j=0;j<16;j++)
			{
			   if(n1[i]==hex[j])
			   {
				   a1+=(dec_val[j]*pow(16,k));
				   k--;
				   printf("%s",hex_val[j]);
				   break;
			   }
			}
		}
		printf(" %c ",s);
			len=strlen(n2);
		if(len==4)
		{
			i=1;
			printf("1");
		}
		else
		{
		for(i=0;i<(13-(len*4));i++)
			printf("0");
		i=0;
		}
		k=len-1;
		for(;i<len;i++)
		{
			for(j=0;j<16;j++)
			{
			   if(n2[i]==hex[j])
			   {
				   a2+=(dec_val[j]*pow(16,k));
				   k--;
				   printf("%s",hex_val[j]);
				   break;
			   }
			}
		}
		printf(" = ");
		if(s=='+')
			printf("%d",(a1+a2));
		else
			printf("%d",(a1-a2));
		printf("\n");
	}
	return 0;
}