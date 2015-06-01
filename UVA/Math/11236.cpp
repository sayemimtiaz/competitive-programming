#include<stdio.h>
int main()
{
	long long a,b,c,d;
	for(a=1;4*a<=2000;a++)
		for(b=a;a+3*b<=2000;b++)
			for(c=b;a+b+2*c<=2000;c++)
			{
					                 long long p = (1.0 * a * b * c);
                 long long s = (0.0 + a + b + c);

                if (p == 1000000) continue;
            
               long long d = (1000000 * s) / (p - 1000000);

               if ( d >= c && ( s +d ) <= 2000) {
                    double a1 = a/100.0;
                    double b1 = b/100.0;
                    double c1 = c/100.0;
                    double d1 = d/100.0;

                   double s1 = a1 + b1 + c1 + d1;    
                   double p1 = a1 * b1 * c1 * d1;
         
                   if ((a+b+c+d)*1000000==a*b*c*d)
                        printf("%0.2lf %0.2lf %0.2lf %0.2lf\n", a/100.0, b/100.0, c/100.0, d/100.0);
             }
             }
	return 0;
}
