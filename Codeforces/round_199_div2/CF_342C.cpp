#include <stdio.h>
#include <math.h>
int main()
{
	int r,h;
	scanf("%d%d",&r,&h);
	int ans=h/r*2,rem=h%r;
	if((double)rem>=r/2.0*sqrt(3.0))
		ans+=3;
	else if(rem>=r/2.0)
		ans+=2;
	else
		ans++;
	printf("%d",ans);
	return 0;
}
