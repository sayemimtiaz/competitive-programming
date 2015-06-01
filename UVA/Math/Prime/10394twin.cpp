#include <iostream>
#include <cmath>
using namespace std;
long p1[20000000],p2[20000000];
long prime[20000000];
int main()
{  
 long i,k,m;  
  m = (int)sqrt(20000000);  
 for (i=2; i<=m; i++)      
	 if (prime[i]==0)
       for ( k=i*i; k<=20000000; k+=i)	  
           prime[k]=1 ; 
	   k=0;
for (i=3; i<20000000; i++)
{    
	if (prime[i]==0&&prime[i+2]==0&&((i+2)-i)==2)
	{
		p1[k]=i;
		p2[k]=i+2;
		k++;
	}
} 
long h; 
while(cin>>h)
{
 cout <<"("<<p1[h-1]<<", "<<p2[h-1]<<")"<< endl;   
}
 return 0;
}