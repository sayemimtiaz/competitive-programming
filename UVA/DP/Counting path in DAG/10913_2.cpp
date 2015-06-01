#include<stdio.h>

#define _for(i,a,b) for(i=a;i<=b;i++)
#define INF -2147483647

int M[75+3][75+3][5+3],G[75+3][75+3];

inline int Boro(int a,int b)
{
       return (a>b)?a:b;
}

int main()
{
    int n,k,i,j,r,g,buf1[75+3][5+3],l,buf2[75+3][5+3],kas=1;
    while(scanf("%d %d",&n,&k)&&(n||k))
    {
      _for(i,1,n)
       _for(j,1,n)
       {
        scanf("%d",&G[i][j]);
         _for(g,0,k)
           M[i][j][g]=INF;
        }
          printf("Case %d: ",kas++);
          if(n<=0)
          {  printf("impossible\n");continue;}
          
       if(G[1][1]<0)
        M[1][1][1]=G[1][1],g=1;
      else
       M[1][1][0]=G[1][1],g=0;
      _for(i,2,n)
      {
        _for(g,0,k)
         if(G[1][i]>=0&&M[1][i-1][g]!=INF)
          M[1][i][g]=M[1][i-1][g]+G[1][i];
         else if(g<k&&M[1][i-1][g]!=INF)
          M[1][i][g+1]=M[1][i-1][g]+G[1][i];
      }
      _for(i,2,n)
      {
       _for(j,1,n)          
        _for(g,0,k)
            if(G[i][j]>=0&&i&&M[i-1][j][g]!=INF)
              M[i][j][g]=M[i-1][j][g]+G[i][j];
            else if(g&&M[i-1][j][g-1]!=INF)
              M[i][j][g]=M[i-1][j][g-1]+G[i][j];
              
        _for(j,1,n)
        _for(g,0,k)
        buf1[j][g]=buf2[j][g]=M[i][j][g];
        
       _for(j,2,n)
           _for(g,0,k)
              if(G[i][j]>=0&&buf1[j-1][g]!=INF)
              buf1[j][g]=Boro(buf1[j-1][g]+G[i][j],buf1[j][g]);
              else if(g&&buf1[j-1][g-1]!=INF)
              buf1[j][g]=Boro(buf1[j-1][g-1]+G[i][j],buf1[j][g]);
     
       for(j=n-1;j>=1;j--)
           _for(g,0,k)
            if(G[i][j]>=0&&buf2[j+1][g]!=INF)
                buf2[j][g]=Boro(buf2[j+1][g]+G[i][j],buf2[j][g]);
            else if(g&&buf2[j+1][g-1]!=INF)
                buf2[j][g]=Boro(buf2[j+1][g-1]+G[i][j],buf2[j][g]);
      _for(j,1,n)
       _for(g,0,k)
         M[i][j][g]=Boro(M[i][j][g],Boro(buf1[j][g],buf2[j][g]));
          
       }
       r=M[n][n][0];
       _for(g,1,k)
        r=Boro(r,M[n][n][g]);
       if(r!=INF)
       printf("%d\n",r);
       else
       printf("impossible\n");
    }
    return 0;
}
