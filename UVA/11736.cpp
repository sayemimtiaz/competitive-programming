#include<stdio.h>
#include<string.h>
char sl[300][50],mm[300][50],final[200];
void reverse(char *from,char *to)
{
     long len=strlen(from);
     long l;
     for(l=0;l<len;l++)
      to[l]=from[len-l-1];
      to[len]='\0';
}
void mul(long k)
{
     char cur[1000],res[1000];
     long l,i,hold,a,j,len,len1;
     cur[0]='1';cur[1]='\0';
  for(l=1;l<=k;l++)
  {
   len=strlen(cur);j=0;
  for(i=len-1,hold=0;i>=0;i--)
  {
     a=(cur[i]-'0')*2+hold;
     res[j++]=a%10+'0';
     hold=a/10;
  }
  if(hold)
   res[j++]=hold+'0';
  res[j]='\0';
  reverse(res,cur);
  }
  len=strlen(final);
  len1=strlen(cur);j=0;
   for(l=len-1,i=len1-1,hold=0;l>=0||i>=0;)
  {
    if(l>=0&&i>=0)
    { a=(cur[i]-'0')+(final[l]-'0')+hold;i--;l--;}
     else if(l>=0)
    { a=(final[l]-'0')+hold;l--;}
    else
    { a=(cur[i]-'0')+hold;i--;}
     res[j++]=a%10+'0';
     hold=a/10;
  }
  if(hold)
   res[j++]=hold+'0';
   res[j]='\0';
   reverse(res,final);
}
int main()
{
    long b,v,i,j,k,l,sv[220],q;
    char str[1000];
    while(~scanf("%ld %ld",&b,&v))
    {
        for(i=0;i<v;i++)
            scanf("%s %ld",sl[i],&sv[i]);            
        for(i=0;i<v;i++)
        {
          k=(sv[i]*b)-1;
          final[0]='0';final[1]='\0';
          for(j=0;j<sv[i];j++)
          {
             scanf("%s",str);
             for(l=0;str[l]!='\0';l++)
             { if(str[l]!='0')
                mul(k);
                k--;
             }
          }
          strcpy(mm[i],final);               
        }
        scanf("%ld",&q);
        while(q--)
        {
          scanf("%s",str);
          printf("%s=",str);
          for(i=0;i<v;i++)
           if(!strcmp(str,sl[i]))
           {printf("%s",mm[i]);break;}
          printf("\n");
        } 
    }                 
    return 0;
}
