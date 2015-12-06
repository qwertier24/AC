#include <stdio.h>
#include <string.h>
#define maxn 1000001
int prime[maxn+100],next_prime[maxn],P[maxn];
double d[maxn];
bool vis[maxn]={0};
void get_prime()
{
	for(long long i=2; i<=maxn; i++)
		if(prime[i])
			for(long long  j=i*i; j<=maxn; j+=i)
			{
				//printf("%d\n",j);
				prime[j]=0;
			}
	int next=maxn+1;
	for(int i=maxn; i>=2; i--)
		if(prime[i])
		{
			next_prime[i]=next;
			next=i;
		}
	int t=0;
	for(int i=2; i<=maxn; i++)
	{
		if(prime[i])
		{
			t++;
		}
		P[i]=t;
	}
}
double dp(int x)
{
	if(x==1)return 0.0;
	if(vis[x])return d[x];
	vis[x]=true;
	double& ans=d[x];
	ans=0.0;
	int g=0;
	for(int i=2; i<=x; i=next_prime[i])
		if(x%i==0)
		{
			ans+=dp(x/i);
			g++;
		}
	ans=((double)ans+(double)P[x])/(double)g;
	//printf("%d %d %d\n",x,P[x],g);
	return ans;
}
int main()
{
	int T;
	memset(prime,-1,sizeof(prime));
	get_prime();
	scanf("%d",&T);
	for(int kase=1; kase<=T;kase++)
	{
		int n;
		scanf("%d",&n);
		printf("Case %d: %.10lf\n",kase,dp(n));
	}
	return 0;
}
