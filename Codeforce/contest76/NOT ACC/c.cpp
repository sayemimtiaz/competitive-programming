#include<cstdio>
using namespace std;
int main()
{
    long a,b,n,m,res,i,j;
        while(~scanf("%ld %ld %ld %ld",&n,&m,&a,&b))
    {
       res=0;
       if(a==b)
        res=1;
       else
       {
       res=0;j=0;i=a;
       if((a-1)%m)
       {res++;
       for(j=1,i=a;i%m;i++,j++);}
       if(b>i&&b%m)
       {j++;res++;
       for(i=b;(i-1)%m;i--,j++);
       }
       if(j<(b-a+1))
        res++;
        }
        printf("%ld\n",res);
    }
    return 0;
}
