#include <stdio.h>
int main()
{
	int a,b,m;
	scanf("%d%d%d",&a,&b,&m);
	printf("%I64d",(((long long)a-1)/m+1)*(((long long)b-1)/m+1));
	return 0;
}
