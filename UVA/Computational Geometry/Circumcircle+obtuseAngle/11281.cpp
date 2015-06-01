#include<stdio.h>
#include<math.h>

#define PI acos(-1.0)
#define EPS 1e-9
#define sq(a) a*a

inline double MAX(double a,double b)
{
       return (a-b>EPS)?a:b;
}

int main()
{
    int n,m,i,j,F[200];
    char peg;
    double a,b,c,A,B,C,D,H[200],S;
    while(~scanf("%d",&n))
    {
       for(i=0;i<n;i++)
       scanf("%lf",&H[i]);
      scanf("%d",&m);
      peg='A';
      while(m--)
      {
        scanf("%lf %lf %lf",&a,&b,&c);
        S=(a+b+c)/(double)2.0;
        D=(a*b*c)/(double)(2.0*sqrt(S*(S-a)*(S-b)*(S-c)));
        if(sq(a)+sq(b)<sq(c)||sq(a)+sq(c)<sq(b)||sq(c)+sq(b)<sq(a))
         D=MAX(a,MAX(b,c));
         for(j=0,i=0;i<n;i++)
          if(H[i]>=D)
            F[j++]=i;
         if(!j)
          printf("Peg %c will not fit into any holes",peg);
         else{
          printf("Peg %c will fit into hole(s):",peg);  
           for(i=0;i<j;i++)
            printf(" %d",F[i]+1);
            }
            peg++;
            printf("\n");
        
      }
    }
    return 0;
}
