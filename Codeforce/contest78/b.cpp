#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    long n,i,a[1500],kI,bI,kom,beshi,soman,sum,avg;
    long C,B;
    while(~scanf("%ld",&n))
    {
      sum=0;
      for(i=0;i<n;i++)
      {
        scanf("%ld",&a[i]);
        sum+=a[i];
      }    
      avg=sum/n;
      if((avg*n)!=sum)
      {
         printf("Unrecoverable configuration.\n");
         continue;
      }
      B=0;C=0;
      soman=0;
      for(i=0;i<n;i++)
      {
        if(a[i]>avg)
        {
          if(C>1)
           break;
          bI=i;
          beshi=a[i]-avg;
          C++;
        }
        else if(a[i]<avg)
        {
          if(B>1)
           break;
           kI=i;
          kom=avg-a[i];
          B++;
        }
        else
         soman++;
      }
      if(B>1||C>1)
       printf("Unrecoverable configuration.\n");
      else if(soman==n)
       printf("Exemplary pages.\n");
      else if(kom==beshi)
       printf("%ld ml. from cup #%ld to cup #%ld.\n",kom,kI+1,bI+1);
      else
        printf("Unrecoverable configuration.\n");
    } 
    return 0;
}
