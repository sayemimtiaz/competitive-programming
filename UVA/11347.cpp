#include<stdio.h>
#include<math.h>
#include<string.h>
#define SIZE 1500
long d[SIZE],c,a[SIZE],fr[SIZE];
bool prime[SIZE];
void fac(long n)
{
     long i;
      for(i=0;i<c&&a[i]<=n;)
          {
            if(n%a[i]==0)
            {
               fr[a[i]]++;  
               n/=a[i];
            }
            else
              i++;
        }

}
void sieve(long N)
{
     long i,j,prev,dv;
     long M=sqrt(N);
	for(i=4;i<=N;i+=2)
		prime[i]=1;
	a[0]=2;c=1;
	for(i=3;i<=N;i+=2)
	{
		if(!prime[i])
		{         
            a[c++]=i;
            if(i<=M)
			for(j=i*i;j<=N;j+=2*i)
				prime[j]=1;
		}
	}
}
int main()
{
    long kase,i,n,s,kas=1;
    double res,con;
    bool flag;
    char str[1000],*pch;
    sieve(1005);
    scanf("%ld",&kase);
    gets(str);
    while(kase--)
    {
        gets(str);
        pch=strtok(str,"!");
        sscanf(pch,"%ld",&n);
        pch=strtok(NULL," ");
        if(pch!=NULL)
        s=strlen(pch);
        else
         s=0;
         s++;
          res=n%s;
          if(!res)
           res=1;
        for(i=n;i>=res;i-=s)
        {
           if(!prime[i])
            fr[i]++;
           else
            fac(i);
            
        }
        res=1;flag=1;
        con=pow(10,18);
        for(i=0;i<c;i++)
         if(fr[a[i]])
         {
            res*=(fr[a[i]]+1);
          if(res>con)
           {flag=0;break;}
         }
         printf("Case %ld: ",kas++);
         if(flag)
          printf("%0.lf\n",res);
         else
          printf("Infinity\n");
          memset(fr,0,sizeof(fr));
    }
    return 0;
}
