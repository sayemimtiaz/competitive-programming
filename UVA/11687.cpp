#include<stdio.h>
#include<string.h>
char str[1000009];
int main()
{
    int len;
    while(scanf("%s",str)&&str[0]!='E')
    {
      len=strlen(str);
      if(str[0]=='1'&&str[1]=='\0')
       printf("1\n");
      else if(len<2)
       printf("2\n");
      else if(len<10)
       printf("3\n");
      else
       printf("4\n");
    }
    return 0;
}
