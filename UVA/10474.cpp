#include<iostream.h>
#include<stdlib.h>
int comp(const void *x,const void *y)
{
   return(*((int*)x)-*((int*)y));
}
int main()
{
  int a[10000],val[10000],n,t,i,j,h;
  int k=1;
  while(k)
  {
     cin>>n>>t;
	 if(n==0&&t==0)
		 break;
	 for(i=0;i<n;i++)
		 cin>>a[i];
	 for(i=0;i<t;i++)
		 cin>>val[i];
	 qsort(a,n,sizeof(int),comp);
     cout<<"CASE# "<<k<<":"<<"\n";
	 for(j=0;j<t;j++)
	 {
		 h=0;
	    for(i=0;i<n;i++)
		{
              if(a[i]==val[j])
			  {
				h=1;
				break;
			  }
		}
		if(h==1)
	          cout<<val[j]<<" found at "<<i+1<<"\n";
			else
                cout<<val[j]<<" not found"<<"\n";
	 }
	 k++;
  }
 return 0;
}