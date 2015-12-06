#include <stdio.h>
#include <string.h>
int d[1<<16],P[17],cover[1<<16];
inline int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int n;
	int kase=0;
	while(scanf("%d",&n) && n)
	{
		int ALL=(1<<n)-1;
		memset(P,0,sizeof(P));
		memset(d,0,sizeof(d));
		memset(cover,0,sizeof(cover));
		for(int i=0; i<n; i++)
		{
			int m,t;
			scanf("%d",&m);
			P[i]|=1<<i;
			for(int j=0; j<m; j++)
			{
				scanf("%d",&t);
				P[i]|=1<<t;
			}
		//printf("%d\n",P[2]);
		}
		for(int S=ALL; S; S--)
			for(int i=0; i<n; i++)
				if((S>>i) &1)
				{
					cover[S]|=P[i];
					//printf("cover[%d]=%d\n",S,cover[S]);
				}
		for(int S=1; S<=ALL; S++) 
			for(int S0=S; S0; S0=(S0-1)&S)
				if(cover[S0]==ALL)
				{
					d[S]=max(d[S^S0]+1,d[S]);
					//printf("S0=%d d[%d]=%d\n",S0,S,d[S]);
				}
		printf("Case %d: %d\n",++kase,d[ALL]);
	}
	return 0;
}
