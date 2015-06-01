#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define MAX 2000
void reverse(char *from,char *to)
{
     int len=strlen(from);
     int l;
     for(l=0;l<len;l++)
      to[l]=from[len-l-1];
      to[len]='\0';
}
void Bmult(char *first,char *sec,char *result)
{
     char F[MAX],S[MAX],temp[MAX];
     int f_len,s_len,f,s,r,t_len,hold,res;
     f_len=strlen(first);
     s_len=strlen(sec);
     reverse(first,F);
     reverse(sec,S);
     t_len=f_len+s_len;
     r=-1;
     for(f=0;f<t_len;f++)
      temp[f]='0';
     temp[f]='\0';
     for(s=0;s<s_len;s++)
     {
        hold=0;
        for(f=0;f<f_len;f++)
        {
           res=(F[f]-'0')*(S[s]-'0')+hold+(temp[f+s]-'0');
           temp[f+s]=res%10+'0';
           hold=res/10;
           if(f+s>r)
            r=f+s;
        }
        while(hold!=0)
        {
           res=hold+temp[f+s]-'0';
           hold=res/10;
           temp[f+s]=res%10+'0';
           if(f+s>r)
            r=f+s;
           f++;
        }
     }
     for(;r>0&&temp[r]=='0';r--);
     temp[r+1]='\0';
     reverse(temp,result);
}
int Bminus(char *large,char *small,char *result)
{
     char L[MAX],S[MAX];
     int l,s,now,hold,diff;
     l=strlen(large);
     s=strlen(small);
     if((l<s)||(l==s&&strcmp(large,small)<0))
      return 0;
     reverse(large,L);
     reverse(small,S);
     for(;s<l;s++)
      S[s]='0';
     S[s]='\0';
     for(now=0,hold=0;now<l;now++)
     {
        diff=L[now]-(S[now]+hold);
        if(diff<0)
        {hold=1;result[now]=10+diff+'0';}
        else
         {hold=0;result[now]=diff+'0';}
     }
     for(now=l-1;now>0;now--)
      if(result[now]!='0')
       break;
     result[now+1]='\0';
     reverse(result,L);
     strcpy(result,L);
     return 1;
}
void Bsqrt(char *number,char *result,char *extra)
{
     char left[MAX],after[MAX],who[10],temp[MAX],two[10];
     int num,start,e,mul,r=0,len,l;
     len=strlen(number);
     if(len%2==0)
     {num=10*(number[0]-'0')+number[1]-'0';start=2;}
     else
     {num=number[0]-'0';start=1;}
     mul=sqrt(num);
     result[0]=mul+'0';result[1]='\0';
     if(num-mul*mul==0)
      extra[0]='\0';
     else
     sprintf(extra,"%d",num-mul*mul);
     for(;start<len;start+=2)
     {
       e=strlen(extra);
       extra[e]=number[start];
       extra[e+1]=number[start+1];
       extra[e+2]='\0';
       sprintf(two,"%d",2);
       Bmult(result,two,left);
       l=strlen(left);
       for(mul=9;mul>=0;mul--)
       {
         sprintf(who,"%d",mul);
         strcat(left,who);
         Bmult(left,who,after);
         if(Bminus(extra,after,temp)==1)
         {
             result[++r]=mul+'0';
             result[r+1]='\0';
             strcpy(extra,temp);
             break;
         } 
         else
          left[l]='\0';
       }
     }
   result[++r]='\0';
}
int main()
{
    int kase;
    bool flag=0;
    char fir[MAX],ex[MAX],res[MAX];
    scanf("%d",&kase);
    while(kase--)
    {
      scanf("%s",fir);
      Bsqrt(fir,res,ex);
      if(flag)
       printf("\n");
       flag=1;
      for(int i=0;res[i]!='\0';i++)
       printf("%c",res[i]);
      printf("\n");
    }
    return 0;
}
