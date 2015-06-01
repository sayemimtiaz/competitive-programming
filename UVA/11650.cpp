#include<stdio.h>
int main()
{
	int kase,h,m,nh,t,nm,S[14];
	int A[14]={0,11,10,9,8,7,6,5,4,3,2,1,12};
	S[11]=12;S[10]=1;S[9]=2;S[8]=3;
	S[7]=4;S[6]=5;S[5]=6;S[4]=7;
	S[3]=8;S[2]=9;S[1]=10;S[12]=11;
	scanf("%d",&kase);
	while(kase--)
    {
		scanf("%d%*c%d",&h,&m);
		if(m!=0)
		nh=S[h];
		else
		nh=A[h];
	    nm=m/5;
	    if(nm*5!=m)
	     nm++;
        t=nm;
        nm=5*A[nm];
        nm+=(5*t-m);
        nm%=60;
		printf("%02d:%02d\n",nh,nm);
	}
	return 0;
}
