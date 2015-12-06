#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cstring>
#define MOD 1000000007
#define maxn 100000
using namespace std;
vector<int> divisors[maxn+10];
int a[maxn+10],n,cnt[maxn+10]={0},sum[maxn+10]={0};
long long fast_pow(int b,int p){
	long long ret=1,t=b;
	while(p){
		if(p&1)
			ret=(ret*t)%MOD;
		p>>=1;
		t=(t*t)%MOD;
	}
	return ret;
}
long long solve(int m){
	long long ret=1,j=1;
	for(int i=0; i<divisors[m].size()-1; ++i){
		ret=(ret*fast_pow(i+1,sum[divisors[m][i]]-sum[divisors[m][i+1]]))%MOD;
	}
	return (ret*(fast_pow(divisors[m].size(),sum[divisors[m].back()])-fast_pow(divisors[m].size()-1,sum[divisors[m].back()])))%MOD+MOD;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
	//freopen("prob.out","w",stdout);
#endif
	int maxa=0;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
		maxa=max(maxa,a[i]);
	}
	for(int i=maxn; i>=1; --i)
		sum[i]=sum[i+1]+cnt[i];
	for(int i=1; i<=maxa; i++)
		for(int j=i; j<=maxa; j+=i)
			divisors[j].push_back(i);
	for(int i=1; i<=maxa; i++){
		ans=(ans+solve(i))%MOD;
	}
	printf("%I64d",ans);
	return 0;
}
