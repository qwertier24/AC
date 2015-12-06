#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#define MSQ 100
#define MAXN 10000
using namespace std;
int prime[10001],next[10001],pm[10001];
void Init()
{
	memset(prime,-1,sizeof(prime));
	for(int i=2; i<=MAXN; i++)
		for(int j=i*i; j<=MAXN; j+=i)
			prime[j]=0;
	int t=10000000;
	for(int i=MAXN; i>=2; i--)
		if(prime[i])
		{
			//if(i>4000)printf("%d\n",i);
			next[i]=t;
			t=i;
		}
	/*
	for(int i=2; i<=MAXN; i++)
	{
		int S=i;
		//if(i==2)printf("%d\n",loop);
		for(int j=2; j<=i&&S!=1; j=next[j])
		{
			while(S%j==0)
			{
				S/=j;
				p[i][j]++;
				//if(i==2)printf("%d",p[i][j]);
			}
		}
	}
	//printf("p22=%d\n",p[2][2]);
	for(int i=1; i<=MAXN; i++)
		for(int j=1; j<=MSQ; j++)
			p[i][j]+=p[i-1][j];
	*/
}
int main()
{
	int T;
	Init();
	scanf("%d",&T);
	for(int kase=1; kase<=T; kase++)
	{
		int m,n;
		int ans=MAXN;
		scanf("%d%d",&m,&n);
		printf("Case %d:\n",kase);
		{
			for(int i=2; i<=MAXN&&m!=1; i=next[i])
			{
				int cnt=0;
				while(m%i==0)
				{
					m/=i;
					cnt++;
				}
				int t=n,divide=0;
				while(t>1)
				{
					t/=i;
					divide+=t;
				}
				if(cnt)ans=min(ans,divide/cnt);//printf("%d:%d %d\n",i,p[n][i],pm[i]);}
			}
			if(ans==0)
				printf("Impossible to divide\n");
			else
				printf("%d\n",ans);
		}
	}
	return 0;
}
