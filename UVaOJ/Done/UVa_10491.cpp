#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
int main()
{
	double a,b,c;
	while(scanf("%lf%lf%lf",&a,&b,&c)!=EOF)
	{
	printf("%.5lf\n",(a/(a+b))*(b/(a+b-c-1)) + (b/(a+b))*((b-1)/(a+b-c-1)));
	}
	return 0;
}
