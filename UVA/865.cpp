#include<stdio.h>
#include<string.h>
char str[100000][100];
int main()
{
    int kase,i,j,k;
    char m[300];
    bool flag=0;
    scanf("%d",&kase);
    getchar();
    getchar();
    while(kase--)
    {
      memset(m,'\0',sizeof(m));
      i=0;
      while(gets(str[i])&&str[i][0]!='\0')
       i++;
      for(j=0;str[0][j]!='\0';j++)
       m[str[0][j]]=str[1][j];
      if(flag)
       printf("\n");
      else
      flag=1;
      printf("%s\n%s\n",str[1],str[0]);
      for(j=2;j<i;j++,printf("\n"))
       for(k=0;str[j][k]!='\0';k++)
         if(m[str[j][k]]!='\0')
          printf("%c",m[str[j][k]]);
         else
          printf("%c",str[j][k]);
    }
    return 0;
}
