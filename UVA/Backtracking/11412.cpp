#include<stdio.h>
#include<string.h>
char a[10],b[10],c[500][10],guess1[100],guess2[100];
long k=0,n1_1,n1_2,n2_1,n2_2;
bool vis[10];
void check(long how)
{
     if(how==4)
     {strcpy(c[k++],b);return;}
     long i;
     for(i=0;i<6;i++)
     {
       if(!vis[i])
       {
         vis[i]=1;
         b[how]=a[i];
         check(how+1);
         vis[i]=0;
       }
     }
}
bool seek()
{
     bool flag1[200]={0};
     bool flag2[200]={0};
     long x1,y1,i,j,x2,y2;
     for(j=0;j<4;j++)
     { flag1[guess1[j]]=flag2[guess2[j]]=1;}
    for(i=0;i<k;i++)
    {
        x1=y1=x2=y2=0;
       for(j=0;j<4;j++)
       {
          if(c[i][j]==guess1[j])
            x1++;
          else if(flag1[c[i][j]])
            y1++;
          if(c[i][j]==guess2[j])
            x2++;
          else if(flag2[c[i][j]])
            y2++;
       }
       if(x1==n1_1&&y1==n1_2&&x2==n2_1&&y2==n2_2)
        return 1;
    }
    return 0;    
}
int main()
{
    b[4]='\0';
    a[0]='R';a[1]='G';a[2]='B';a[3]='Y';a[4]='O';a[5]='V';
    check(0);
    long kase;
    scanf("%ld",&kase);
    while(kase--)
    {
       scanf("%s %ld %ld",&guess1,&n1_1,&n1_2);
       scanf("%s %ld %ld",&guess2,&n2_1,&n2_2);
       if(seek())
         printf("Possible\n");
       else
         printf("Cheat\n");
    }
    return 0;
}
