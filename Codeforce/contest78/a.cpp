#include<stdio.h>
#include<string.h>
int main()
{
    int len;
    char *pch,str[5000],part1[5000],part2[5000];
    while(gets(str))
    {
      pch=strtok(str,".");
      strcpy(part1,pch);
      pch=strtok(NULL," ");
      strcpy(part2,pch);
      len=strlen(part1);
      if(part1[len-1]=='9')
      {printf("GOTO Vasilisa.\n");continue;}
      if(part2[0]<'5')
       printf("%s\n",part1);
      else
      {
          part1[len-1]++;
          printf("%s\n",part1);
      }
    }
    return 0;
}
