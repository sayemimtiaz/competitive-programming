#include<stdio.h>
#include<string.h>

#define MAX 50000
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
int main()
{
    char temp[MAX],p1[MAX],p2[MAX],result[MAX];
    int n,D,L,Last1,i,j,L1;
    while(~scanf("%s %d",temp,&n))
    {
       j=0;
       for(i=0;temp[i]=='0';i++);
       for(;temp[i]!='.';i++)
        p1[j++]=temp[i];
       p1[j]='\0';  
       L1=j;
       i++;j=0;
       for(;temp[i]!='\0';i++)
        p2[j++]=temp[i];
       p2[j]='\0';
       D=j;
       D*=n;
       strcat(p1,p2);
       result[0]='1';result[1]='\0';
       for(i=1;i<=n;i++)
        Bmult(result,p1,result);
       L=strlen(result);
       Last1=-1;
       for(i=0;i<L;i++)
       {
         if((L-i)>D)
          printf("%c",result[i]);
         else
         {
             if(result[i]!='0')
              Last1=i;
         }
       }
       if(Last1!=-1)
        printf(".");
       if(L1==0)
       {
         L1=D-L;
         for(i=0;i<L1;i++)
          printf("0");
         for(j=0;j<=Last1;j++)
          printf("%c",result[j]);
       }
       else
       {
       for(j=L-D;j<=Last1;j++)
        printf("%c",result[j]);
       }
       printf("\n");
    } 
    return 0;
}
