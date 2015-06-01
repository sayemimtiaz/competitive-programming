#include<stdio.h>
#include<string.h>
char f[500];
char factorial[500][1000];
void multiply(int k)
{
 int cin,sum,i;
 int len=strlen(f);
 cin=0;
 i=0;
 while(i<len)
	  {
		sum=cin+(f[i]-'0')*k;
		f[i]=(sum%10)+'0';
		i++;
		cin=sum/10;

		}
  while(cin>0)
	  {
		f[i++]=(cin%10)+'0';
		cin/=10;
	   }
	f[i]='\0';
	for(int j=0;j<i;j++)
		  factorial[k][j]=f[j];
	   factorial[k][i]='\0';
}
void fac()
{
 int k;
 strcpy(f,"1");
 for(k=2;k<=500;k++)
	  multiply(k);
}
void print(int n)
{
   int i,j,count;
   int len =strlen(factorial[n]);
   printf("%d! --\n   ",n);
   for(j=0;j<=9;j++)
   {
	   count=0;
   for(i=len-1;i>=0;i--)
   {
	   if(factorial[n][i]==(j+'0'))
		   count++;

   }
   printf("(%d)    %3d",j,count);
   if(j!=4||j!=9)
	   printf("    ");
   if(j==4)
	   printf("\n   ");

   }

	  printf("\n");
}
int main()
{
  int n;
  factorial[1][0]='1';
 fac();
  while(1)
  {
	  scanf("%d",&n);
	  if(!n)
		  break;
			 print(n);
  }


return 0;
}
