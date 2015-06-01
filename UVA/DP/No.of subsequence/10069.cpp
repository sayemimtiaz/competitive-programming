
#include<cstdio>
#include<cstring>
using namespace std;
char memo[10005][105][105];
char a[50000];
void add(char *s1,char *s2)
{
	char tmp[10000],res[10000];
	long l1,l2,i,temp,m,n,sum,hold,j;
	l1=strlen(s1);
	l2=strlen(s2);
	if(l2>l1)
	{
		temp=l1;
		l1=l2;
		l2=temp;
		strcpy(tmp,s1);
		strcpy(s1,s2);
		strcpy(s2,tmp);
	}
	m=l1-1;
	n=l2-1;
	for(i=0,hold=0;i<l1;i++)
	{
		if(n>=0)
		sum=(s1[m--]-'0')+(s2[n--]-'0')+hold;
		else
		sum=(s1[m--]-'0')+hold;
		res[i]=sum%10+'0';
		hold=sum/10;
	}
	if(hold)
		res[i++]=hold+'0';
	for(j=i-1;j>=0;j--)
		a[i-1-j]=res[j];
	a[i]='\0';
    
}
int main()
{
    long kase,i,j,l1,l2;
    char s1[10005],s2[105];
    scanf("%ld",&kase);
    getchar();
    while(kase--)
    {
      gets(s1);
      gets(s2);
      l1=strlen(s1);
      l2=strlen(s2);
      for(i=0;i<=l2;i++)
        strcpy(memo[0][i],"0"); 
      for(i=1;i<=l1;i++)
        strcpy(memo[i][0],"0");
      for(i=1;i<=l1;i++)
       {for(j=1;j<=l2;j++)
       {
        if(j>i)
         strcpy(memo[i][j],"0");
         else
         {
         strcpy(memo[i][j],memo[i-1][j]);
         if(s1[i-1]==s2[j-1])
         {
         if(j==1)
         {
           add(memo[i][j],"1");
           strcpy(memo[i][j],a);
         }
           add(memo[i][j],memo[i-1][j-1]);
           strcpy(memo[i][j],a);
         }
         }
       }
       }
      printf("%s\n",memo[l1][l2]);
    }
    return 0;
}
