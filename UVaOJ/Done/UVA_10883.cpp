#include <stdio.h>
#include <string.h>
#include <math.h>
int C[50001];
int Init(int n)
{
	C[0]=1;
	for(int i=1; i<=n; i++)
		C[i]=C[i-1]*(n-i+1)/i;
}
int main()
{
	int T;
	memset(C,0,sizeof(C));
	scanf("%d",&T);
	for(int kase=1; kase<=T; kase++)
	{
		int n;
		double num,ans=0;
		scanf("%d",&n);
		//Init(n-1);
		double log2C=0;
		for(int i=1; i<=n; i++)
		{
			scanf("%lf",&num);
			//printf("%lf\n",pow(2,log2(num)+log2C-n+1));
			if(num>0)
				ans+=pow(2.0,log2(num)+log2C-n+1);
			else
				ans-=pow(2.0,log2(-num)+log2C-n+1);
			log2C=log2C+log2(n-i)-log2(i);
		}
		printf("Case #%d: %.3lf\n",kase,ans);
	}
	return 0;
}
