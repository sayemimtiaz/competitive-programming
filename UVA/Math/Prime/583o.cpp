#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
long a[1000000],c;
bool flag[1000000];
void seive(long n)
{
    long k,i,j;
    k=sqrt(n);
    flag[1]=flag[0]=1;
    a[0]=2;
    c=1;
    for(i=4;i<=n;i+=2)
        flag[i]=1;
    for(i=3;i<=n;i+=2)
    {
       if(!flag[i])
       {
          a[c++]=i;
          if(k>=i)
          {
              for(j=i*i;j<=n;j+=2*i)
                 flag[j]=1;
           }
         }
      }
}
int main()
{
     long n,i;
	 bool flag;
     seive(46341);
     while(scanf("%ld",&n)==1&&n)
     {
		 printf("%ld =",n);
         if(n==1||n==-1)
         {
            printf(" -1\n");
            continue;
         }
		 flag=1;
         if(n<0)
		 {
			 flag=0;
			 printf(" -1");
			 n=-n;
		 }
         for(i=0;i<c&&n>=a[i];)
         {
           if(n%a[i]==0)
           {
			   if(flag)
			   {
				   flag=0;
				   printf(" %ld",a[i]);
			   }
			   else
			   printf(" x %ld",a[i]);
               n=n/a[i];
            }
           else
              i++;
         }
		 if(n!=1)
			 if(flag)
				   printf(" %ld",n);
			 else
				   printf(" x %ld",n);
		 printf("\n");
       }
       return 0;
}
