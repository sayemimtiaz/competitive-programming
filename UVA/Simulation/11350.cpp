#include<stdio.h>
int main()
{
    long M_x,M_y,R_x,R_y,L_x,L_y,i,kase;
    char str[10000];
    scanf("%ld",&kase);
    while(kase--)
    {
        scanf("%s",str);
        i=0;
        L_x=0;L_y=1;M_x=1;M_y=1;R_x=1;R_y=0;
        while(str[i]!='\0')
        {
          if(str[i]=='L')
          {
            R_x=M_x;R_y=M_y;
            M_x+=L_x;M_y+=L_y;
          }
          else
          {
            L_x=M_x;L_y=M_y;
            M_x+=R_x;M_y+=R_y;
          }
          i++;
        }
        printf("%ld/%ld\n",M_x,M_y);
    }
    return 0;
}
