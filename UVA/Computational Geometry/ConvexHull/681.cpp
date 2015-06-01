	/*Finding Convex Hull with Firing out the
	Points of same slope.*/
    
    #include <algorithm>
	#include<cstdio>
	#include<cmath>
	using namespace std;
	 
    #define MAX(a,b) (a>b)?a:b
    #define MIN(a,b) (a>b)?b:a
	#define MAXI 2000
	#define i64 double
	#define sq(x) ((x)*(x))
	struct point {
	    i64 x ;
        i64 y;
	} P[MAXI],C[MAXI],R[MAXI],P0;
	 
	 long n,Top;
	// P[] contains all points
	// C[] contains convex hull ccw
	 
i64 TriArea2(point a, point b, point c) 
{
	    return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}
i64 sqDist(point a, point b) 
{
	    return (sq(a.x-b.x) + sq(a.y-b.y));
}
	 
bool comp(point a, point b) 
{
    	    i64 d = TriArea2(P0, a, b);
	    if(d<0) return false;
	    if(!d && sqDist(P0, b) < sqDist(P0, a)) return false;
	    return true;
}
i64 Slope(point a,point b)
{
    return ((a.y-b.y)/(double)(a.x-b.x));
}
void Fire()
{
     long i,j;
     P0 = P[0];
     R[0]=P[0];
     j=1;
     for(i=2;i<n;i++)
     {
        if(Slope(P0,P[i])!=Slope(P0,P[i-1]))
          R[j++]=P[i-1];
     }
     R[j++]=P[i-1];
     n=j;
     
}	 
void ConvexHull() 
{
	    long i, j, pos = 0;
	    for(i=1; i<n; i++)
	        if(P[i].y<P[pos].y || (P[i].y==P[pos].y && P[i].x<P[pos].x))
	            pos = i;
         point temp;
         temp=P[0];
         P[0]=P[pos];
         P[pos]=temp;
	    P0 = P[0];
	    sort(&P[1], P+n, comp);
	    Fire();
	    C[0] = R[0]; C[1] = R[1]; C[2] = R[2];
	    for(i=j=3; i<n; i++) {
	        while(j>1&&TriArea2(C[j-2], C[j-1], R[i]) <= 0) j--;
	        C[j++] = R[i];
	    }
	    Top = j;
}
int main()
{
    long i,k,t,j;
    scanf("%ld",&k);
    printf("%ld\n",k);
    while(k--)
    {
      scanf("%ld",&n);
      for(j=0;j<n-1;j++)
        scanf("%lf %lf",&P[j].x,&P[j].y);
      scanf("%lf %lf",&P[j].x,&P[j].y);
        if(k)
      scanf("%ld",&t);
      if(n>3)
      {
      n--;
      Top=0;
      ConvexHull();
       C[Top]=C[0];Top++;
      }
      else
      {
          for(Top=0;Top<3;Top++)
           C[Top]=P[Top];
      }
      printf("%ld\n",Top);
       for(j=0;j<Top;j++)
        printf("%0.lf %0.lf\n",C[j].x,C[j].y);
     if(k)
      printf("-1\n");
    }
    return 0;
}
