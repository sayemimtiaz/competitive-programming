#include<stdio.h>
#include<string.h>
char f[10000];
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
}
main()
{
  int n,d;
  while(1)
  {
	  scanf("%d %d",&n,&d);
	  if(n==0&&d==0)
		  break;
	   int k;
 strcpy(f,"1");
 for(k=1;k<=d;k++)
	  multiply(n);
 int len=strlen(f);
  for(k=len-1;k>=0;k--)
	  printf("%c",f[k]);
	  printf("\n");
  }


return 0;
}
