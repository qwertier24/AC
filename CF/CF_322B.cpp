#include <stdio.h>
#include <algorithm>
using namespace std;
int d[3][3][3]={0};
int main()
{
	int r,b,g,ans=0;
	scanf("%d%d%d",&r,&g,&b);
	if(r==0||g==0||b==0)
	{
		printf("%d",r/3+g/3+b/3);
		return 0;
	}
	ans+=r/3+b/3+g/3;
	r%=3;g%=3;b%=3;
	if(r==0)
		r+=3,ans--;
	if(g==0)
		g+=3,ans--;
	if(b==0)
		b+=3,ans--;
	printf("%d",ans+max(min(r,min(g,b)),r/3+b/3+g/3));
	return 0;
}
