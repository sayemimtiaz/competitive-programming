#include<stdio.h>
long memo[120][120],penny[120][120],n,k;
long check(long a,long b)
{
     if(memo[a][b]!=-1)
       return memo[a][b];
     long i,c,t1,t2,m;
     m=penny[a][b];
     for(i=1;i<=k;i++)
     {
        t1=t2=penny[a][b];
        c=a+i;
        if(c<n&&penny[c][b]>penny[a][b])
        { t1+=check(c,b);}
        c=b+i;
         if(c<n&&penny[a][c]>penny[a][b])
        { t2+=check(a,c);t1=(t1>t2)?t1:t2;t2=penny[a][b];}
        c=a-i;
        if(c>=0&&penny[c][b]>penny[a][b])
        { t2+=check(c,b);t1=(t1>t2)?t1:t2;t2=penny[a][b];}
        c=b-i;
         if(c>=0&&penny[a][c]>penny[a][b])
        { t2+=check(a,c);t1=(t1>t2)?t1:t2;}
        m=(m>t1)?m:t1;
     }
     memo[a][b]=m;
     return memo[a][b];                 
}
int main()
{
    long kase,i,j;
    bool flag=0;
    scanf("%ld",&kase);
    while(kase--)
    {
        scanf("%ld %ld",&n,&k);
        for(i=0;i<n;i++)
         for(j=0;j<n;j++)
         {
          memo[i][j]=-1;
           scanf("%ld",&penny[i][j]);
         }
         check(0,0);
         if(flag)
           printf("\n");
           flag=1;
         printf("%ld\n",memo[0][0]);
    }
    return 0;
}
