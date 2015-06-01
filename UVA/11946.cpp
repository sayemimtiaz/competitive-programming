#include<stdio.h>
int main()
{
    char M[100],str[1000];
    int i,kase;
    bool flag=0;
    M[3]='E';M[0]='O';M[1]='I';
    M[4]='A';M[9]='P';M[8]='B';
    M[5]='S';M[7]='T';M[2]='Z';M[6]='G';
    scanf("%d",&kase);
    getchar();
    while(kase--)
    {
      if(flag)
       printf("\n");
      else
       flag=1;
      while(gets(str)&&str[0]!='\0')
      {
        for(i=0;str[i]!='\0';i++)
         if(str[i]>='0'&&str[i]<='9')
          printf("%c",M[str[i]-'0']);
         else
          printf("%c",str[i]);
         printf("\n");
      }
    }
    return 0;
}
