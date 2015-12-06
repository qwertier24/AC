#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
	int y;
	while(scanf("%d",&y)&&y)
	{
		int p=1<<((y-1960)/10+2),ans=1;
		double Log2fac=p,t=0;
		while(log2(ans)+t<Log2fac)
		{
			t+=log2(ans),ans++;
			//2160printf("%lf %lf\n",t,Log2fac);
		}
		printf("%d\n",ans-1);
	}
	return 0;
}
