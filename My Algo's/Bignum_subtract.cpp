#include<stdio.h>
#include<string.h>
#define SIZE 50000
char a[SIZE],b[SIZE];
void minus()
{
     long len1,len2,i,j,templen,s,hold;
     char temp[SIZE],res[SIZE];
     bool put=0;
     len1=strlen(a);
     len2=strlen(b);
     if((len1<len2)||(len1==len2&&strcmp(a,b)<0))
     {   put=1;
        templen=len1;
        len1=len2;
        len2=templen;
        strcpy(temp,a);
        strcpy(a,b);
        strcpy(b,temp);
     }
     j=0;
     len1--;len2--;
     for(hold=0;len1>=0;len1--,len2--)
     {
         if(len2>=0)
         s=a[len1]-(b[len2]+hold);
         else
         s=(a[len1]-'0')-hold;
         if(s<0)
         {
          hold=1;
          temp[j++]=10+s+'0';
          }
          else
          {
              hold=0;
            temp[j++]=s+'0';
            }
     }
     for(i=j-1;i>=0;i--)
      res[j-1-i]=temp[i];
     res[j]='\0';
     for(i=0;res[i]=='0'&&res[i]!='\0';i++);
     strcpy(temp,&res[i]);
     if(put)
      putchar('-');
     if(temp[0]=='\0')
      printf("0\n");
      else
    printf("%s\n",temp);
}
int main()
{
    long kase;
    scanf("%ld",&kase);
    getchar();
    while(kase--)
    {
    gets(a);gets(b);
    minus();
    }
    return 0;
}
