#include<stdio.h>
int main()
{
	double h,m,h_ang,m_ang;
	while(1)
	{
		scanf("%lf%*c%lf",&h,&m);
		if(h==0)
			break;
		h_ang=(h*30)+((m*30)/60);
		m_ang=m*6;
		h_ang=h_ang-m_ang;
		if(h_ang<0)
			h_ang=-h_ang;
		if(h_ang>180)
			h_ang=360-h_ang;
		printf("%0.3lf\n",h_ang);
	}
	return 0;
}
