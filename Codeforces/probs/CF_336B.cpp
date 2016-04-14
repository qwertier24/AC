#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
long long sum[100001]={0};
int main()
{
	long long m,R;
	double s=0;
	scanf("%I64d%I64d",&m,&R);
	R*=2;
	for(int i=1; i<=m; i++)
		sum[i]=sum[i-1]+(long long)i;
	for(int i=1; i<=m; i++)
	{
		s+=R;
		if(i>=2)
			s+=(sqrt(2)*R)/2+R;
		if(m-i>=1)
			s+=(sqrt(2)*R)/2+R;
		if(i>=3)
			s+=R*sum[i-2]+(i-2)*sqrt(2)*R;
		if(m-i>=2)
			s+=R*sum[m-i-1]+(m-i-1)*sqrt(2)*R;
	}
	printf("%.10lf\n",s/(m*m));
	return 0;
}
