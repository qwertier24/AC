#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;
int x[50001],y[50001],pA[50001],pB[50001];
inline int dist(int a,int b)
{
	return abs(x[a]-x[b])+abs(y[a]-y[b]);
}
int main()
{
	int T,m,n;
	bool doub=false;
	scanf("%d",&T);
	while(T--)
	{
		int ans=0,rA=1<<30,rB=1<<30;
		memset(pA,0,sizeof(pA));
		memset(pB,0,sizeof(pB));
		scanf("%d%d",&m,&n);
		m--;
		for(int i=1; i<=n; i++)
			scanf("%d %d",&x[i],&y[i]);
		if(x[1]>x[2])x[1]^=x[2]^=x[1]^=x[2];
		for(int i=2; i<=n; i++)
		{
			if(dist(i,1)<rA)
			{
				memset(pA,0,sizeof(pA));
				pA[i]=1;
				rA=dist(i,1);
			}
			else if(dist(i,1)==rA)
				pA[i]=1;
		}
		for(int i=1; i<=n; i==1?i+=2:i++)
		{
			if(dist(i,2)<rB)
			{
				memset(pB,0,sizeof(pB));
				pB[i]=1;
				rB=dist(2,i);
			}
			else if(dist(i,2)==rB)
				pB[i]=1;
		}
		printf("%d %d\n",rA,rB);
		for(int i=3; i<=n; i++)
			if(pA[i]&&pB[i])
				doub=true;
		for(int i=m; i>=0; i--)
		{
			int dA=rA>abs(i-y[1])?(rA-abs(i-y[1])):0,dB=rB>abs(i-y[2])?(rB-abs(i-y[2])):0,d=x[2]-x[1]>abs(i-y[1])?(x[2]-x[1]-abs(i-y[1])):0;
			int l1=x[2]-d,r1=x[1]+dA,l2=x[2]-dB,r2=x[1]+d;
			if(r1<l2)
			{
				ans+=r1-l1>0?r1-l1-1:0;
				ans+=r2-l2>0?r2-l2-1:0;
				printf("1:%d %d %d %d\n",l1,r1,l2,r2);
			}
			else if(r1==l2)
			{
				ans+=(r2-l2>0?(r2-l2-1):0)-((r1-l2)>0?(r2-l2-1):0);
				if(!doub&&l1<r1&&l2<r2)
					ans++;
				printf("2:%d %d %d %d\n",l1,r1,l2,r2);
			}
			else
				ans+=r2-l1-1;
			printf("%d %d\n",i,ans);
		}
		printf("   %d\n",ans);
	}
	return 0;
}
