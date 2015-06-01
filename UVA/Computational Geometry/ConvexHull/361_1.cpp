	#include <algorithm>
	#include<cstdio>
	#include<cmath>
	using namespace std;
	 
    #define MAX(a,b) (a>b)?a:b
    #define MIN(a,b) (a>b)?b:a
	#define MAXI 500
	#define i64 long
	#define sq(x) ((x)*(x))
	 
	struct point {
	    i64 x, y;
	} P[MAXI], C[MAXI], R[MAXI],D[MAXI],P0;
	 
	 long n,Top1,r,Top2;
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
	    if(!d && sqDist(P0, b) > sqDist(P0, a)) return false;
	    return true;
}
	 
void ProcessPolice() 
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
	    C[0] = P[0], C[1] = P[1], C[2] = P[2];
	    for(i=j=3; i<n; i++) {
	        while(j>1&&TriArea2(C[j-2], C[j-1], P[i]) <= 0) j--;
	        C[j++] = P[i];
	    }
	    if(j<3)
	    {
           C[1]=P[1];C[2]=C[n-1];
           j=3;
        }
	    Top1 = j;
}

void ProcessRobber() 
{
	    long i, j, pos = 0;
	    for(i=1; i<r; i++)
	        if(R[i].y<R[pos].y || (R[i].y==R[pos].y && R[i].x<R[pos].x))
	            pos = i;
         point temp;
         temp=R[0];
         R[0]=R[pos];
         R[pos]=temp;
	    P0 = R[0];
	    sort(&R[1], R+r, comp);
	    
     	 
	    D[0] = R[0], D[1] = R[1], D[2] = R[2];
	    for(i=j=3; i<r; i++) {
	        while(j>1&&TriArea2(D[j-2], D[j-1], R[i]) <= 0) j--;
	        D[j++] = R[i];
	    }
	    if(j<3)
	    {
           D[1]=R[1];D[2]=R[r-1];
           j=3;
        }
	    Top2 = j;
}
bool IsCoveredByPolice(long a,long b)
{
    if(Top1<3)
     return 0;
     long c,d;
     P0.x=a;P0.y=b;
    if(Top1==3&&!TriArea2(C[0],C[1],C[2]))
    {
      if(!TriArea2(C[0],C[1],P0))
      {
        c=MIN(C[1].x,C[2].x);
        c=MIN(c,C[0].x);
        d=MIN(C[1].y,C[2].y);
        d=MIN(d,C[0].y);
       if(a>=c&&b>=d)
       {
        c=MAX(C[1].x,C[2].x);
        c=MAX(c,C[0].x);
        d=MAX(C[1].y,C[2].y);
        d=MAX(d,C[0].y);
        if(a<=c&&b<=d)
          return 1;
       }
       }
      return 0;
    }
    long i,sign;
    for(i=0;i<Top1;i++)
    {
      sign=TriArea2(C[i],C[(i+1)%Top1],P0);
      if(sign<0)
       return 0;
    } 
    return 1;
}
bool IsCoveredByRobber(long a,long b)
{
    if(Top2<3)
     return 0;
      P0.x=a;P0.y=b;
      long c,d;
    if(Top2==3&&!TriArea2(D[0],D[1],D[2]))
    {
      if(!TriArea2(D[0],D[1],P0))
      {
      c=MIN(D[1].x,D[2].x);
        c=MIN(c,D[0].x);
        d=MIN(D[1].y,D[2].y);
        d=MIN(d,D[0].y);
       if(a>=c&&b>=d)
       {
       c=MAX(D[1].x,D[2].x);
        c=MAX(c,D[0].x);
        d=MAX(D[1].y,D[2].y);
        d=MAX(d,D[0].y);
        if(a<=c&&b<=d)
       return 1;
       }
       }
      return 0;
    }
    long i,sign;
    for(i=0;i<Top2;i++)
    {
      sign=TriArea2(D[i],D[(i+1)%Top2],P0);
      if(sign<0)
       return 0;
    } 
    return 1;
}
int main()
{
    long i,o,a,b,kas=1;
    bool flag=0;
    while(scanf("%ld %ld %ld",&n,&r,&o)&&(n||r||o))
    {
      for(i=0;i<n;i++)
        scanf("%ld %ld",&P[i].x,&P[i].y);
      for(i=0;i<r;i++)
        scanf("%ld %ld",&R[i].x,&R[i].y);
        Top1=Top2=0;
       if(n>=3)
      ProcessPolice();
      if(r>=3)
      ProcessRobber();
     printf("Data set %ld:\n",kas++);
      while(o--)
      {
        scanf("%ld %ld",&a,&b);
        if(IsCoveredByPolice(a,b))
         printf("%5cCitizen at (%ld,%ld) is safe.\n",' ',a,b);
        else if(IsCoveredByRobber(a,b))
         printf("%5cCitizen at (%ld,%ld) is robbed.\n",' ',a,b);
        else
          printf("%5cCitizen at (%ld,%ld) is neither.\n",' ',a,b);
      }
      printf("\n");
    }
    return 0;
}
