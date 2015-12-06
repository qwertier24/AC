/*
ID: mayukun3
PROG: ratios
LANG: C++
*/
#include <stdio.h>
#include <algorithm>
using namespace std;
int sum=1<<30,ans_x,ans_y,ans_z;
int main()
{
	freopen("ratios.in","r",stdin);freopen("ratios.out","w",stdout);
	int a,b,c,a1,b1,c1,a2,b2,c2,a3,b3,c3;
	scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&a,&b,&c,&a1,&b1,&c1,&a2,&b2,&c2,&a3,&b3,&c3);
	for(int x=0; x<=100; x++)
		for(int y=0; y<=100; y++)
			for(int z=0; z<=100; z++)
				if(x!=0||y!=0||z!=0)
				{
					if(((a1*x+a2*y+a3*z)*b==(b1*x+b2*y+b3*z)*a) &&((b1*x+b2*y+b3*z)*c==(c1*x+c2*y+c3*z)*b)&&((a1*x+a2*y+a3*z)%a==0))
					if(sum>x+y+z)
					{
						sum=x+y+z;
						ans_x=x;
						ans_y=y;
						ans_z=z;
					}
				}
	if(sum==1<<30)
		printf("NONE\n");
	else
	printf("%d %d %d %d\n",ans_x,ans_y,ans_z,(a1*ans_x+a2*ans_y+a3*ans_z)/a);
	return 0;
}