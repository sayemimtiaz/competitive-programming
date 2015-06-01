#include<iostream.h>
int main()
{
	long b[3],g[3],c[3],t[6],min,i,index;
	char com[10][10]={"BCG","BGC","CBG","CGB","GBC","GCB"};
	long im[6]={0,1,2,3,4,5};
	while(cin>>b[0]>>g[0]>>c[0]>>b[1]>>g[1]>>c[1]>>b[2]>>g[2]>>c[2])
	{
		t[0]=b[1]+b[2]+c[0]+c[2]+g[0]+g[1];
		
		t[1]=b[1]+b[2]+c[0]+c[1]+g[0]+g[2];
		
		t[2]=b[0]+b[2]+c[1]+c[2]+g[0]+g[1];
		
		t[3]=b[1]+b[0]+c[1]+c[2]+g[0]+g[2];
		
		t[4]=b[0]+b[2]+c[0]+c[1]+g[2]+g[1];
		
		t[5]=b[1]+b[0]+c[0]+c[2]+g[2]+g[1];
		min=t[0];
		index=0;
		for(i=1;i<6;i++)
		{
			if(t[i]<min)
			{
				min=t[i];
				index=i;
			}
		}
		for(i=0;i<6;i++)
		{
			if(index==im[i])
			{
				cout<<com[i];
				break;
			}
		}
		cout<<" "<<min<<endl;
	}
	return 0;
	}


		



