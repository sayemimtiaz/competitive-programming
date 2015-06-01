#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
vector<long>A,B;
#define SIZE 5000
long cc,aa[SIZE];
bool prime[SIZE];
void fac(long n,bool flag)
{
     long i;
      for(i=0;i<cc&&aa[i]<n;)
          {
            if(n%aa[i]==0)
            {
               if(flag)
                A.push_back(aa[i]); 
                else
                 B.push_back(aa[i]); 
               n/=aa[i];
            }
            else
              i++;
        }
        if(flag)
            A.push_back(n); 
        else
            B.push_back(n); 
}
void sieve(long N)
{
     long i,j,prev,dv;
     long M=sqrt(N);
	for(i=4;i<=N;i+=2)
		prime[i]=1;
	aa[0]=2;cc=1;
	for(i=3;i<=N;i+=2)
	{
		if(!prime[i])
		{
            aa[cc++]=i;
            if(i<=M)
			for(j=i*i;j<=N;j+=2*i)
				prime[j]=1;
		}
	}
	
}
int main()
{
    long kase,i,a,b,c,j,t,min;
    sieve(3163);
    bool flag[6000];
    scanf("%ld",&kase);
    while(kase--)
    {
        scanf("%ld %ld",&a,&c);
        if(c%a)
         { printf("NO SOLUTION\n");continue;}
        b=c/a;
        
        memset(flag,0,sizeof(flag));
        fac(a,1);fac(b,0);
        for(i=0;i<B.size();i++)
        {
           for(j=A.size()-1;j>=0;j--)
           {
             if(!flag[j]&&B[i]==A[j])
             {flag[j]=1; B.push_back(A[j]);b*=A[j];break;}
           }
        }
        if(c%b==0)
        printf("%ld\n",b);
        else
         printf("NO SOLUTION\n");
        A.clear();
        B.clear();
    }
    return 0;
}
