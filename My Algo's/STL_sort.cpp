#include<cstdio>
#include<algorithm>
using namespace std;
struct S
{
   char str[20];
   long v;
}H[1000];
bool cmp(long a,long b)
{
     //Use < to sort in increasing order
     return a>b;
}
bool cmp1(S a,S b)
{
     //Use < to sort in increasing order
     return a.v<b.v;
}
bool cmp2(double a,double b)
{
     //Use < to sort in increasing order
     return a<b;
}
int main()
{
    long n,a[1000],b[1000],i;
    double d[1000];
    while(scanf("%ld",&n)==1)
    {
      for(i=0;i<n;i++)
      {
       scanf("%ld",&a[i]);
       b[i]=a[i];
       }
      //By default Sort function
      sort(a,a+n);
      for(i=0;i<n;i++)
       printf("%ld ",a[i]);
       printf("\n");
      //Using defined Compare function
      sort(b,b+n,cmp);
      for(i=0;i<n;i++)
       printf("%ld ",b[i]);
      printf("\n");
      for(i=0;i<n;i++)
       scanf("%s %ld",H[i].str,&H[i].v);
       //Multifield_sort
       //sort(H,H+n,cmp1);
       //Stable sort
       stable_sort(H,H+n,cmp1);
       for(i=0;i<n;i++)
        printf("%s %ld\n",H[i].str,H[i].v);
        for(i=0;i<n;i++)
          scanf("%lf",&d[i]);
        //Sorting floating point data
        sort(d,d+n,cmp2);
        for(i=0;i<n;i++)
          printf("%lf ",d[i]);
    }
    return 0;
}
