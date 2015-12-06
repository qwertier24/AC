#include <stdio.h>

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=n*n/2; i>=n/2; i-=n/2)
	{
		int l1=i-n/2+1,r1=i,l2=n*n-i+1,r2=n*n-i+n/2;
		for(int j=l1; j<=r1; j++)
			printf("%d ",j);
		for(int j=l2; j<r2; j++)
			printf("%d ",j);
		printf("%d\n",r2);
	}
	return 0;
}
