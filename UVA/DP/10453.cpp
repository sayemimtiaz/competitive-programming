#include<stdio.h>
#include<string.h>
#define MIN(a,b) (a<b)?a:b
#define INT_MX 1<<30

int M[1200][1200];
char S[1200][1200],str[1200];
void print(int i,int j)
{
     if(i>j)
      return;
      if(i==j)
      {printf("%c",str[i]);return;}
       if(S[i][j]=='1')
       {
         printf("%c",str[i]);
         print(i+1,j-1);
         printf("%c",str[j]);
       }
     else if(S[i][j]=='2')
     {
          printf("%c",str[i]);
          print(i+1,j);
          printf("%c",str[i]);
     }
     else
     {
         printf("%c",str[j]);
         print(i,j-1);
         printf("%c",str[j]);
     }
}
int main()
{
    int i,j,k,n,t;
    while(gets(str))
    {
       n=strlen(str)-1;
       for(i=0;i<=n;i++)
        for(j=0,k=i;k<=n;k++,j++)
        {
           if(j==k)
           { M[j][k]=0;continue;}
            M[j][k]=INT_MX;
            if(str[j]==str[k])
            M[j][k]=M[j+1][k-1];
            S[j][k]=(1+M[j+1][k]<M[j][k])?'2':'1';
            M[j][k]=MIN(1+M[j+1][k],M[j][k]);
            S[j][k]=(1+M[j][k-1]<M[j][k])?'3':S[j][k];
            M[j][k]=MIN(1+M[j][k-1],M[j][k]);
        }
        printf("%d ",M[0][n]);
        print(0,n);
        printf("\n");
    }
    return 0;
}
