#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB
typedef long long LL;
using namespace std;

LL calc(LL n){
	LL ret=n;
	for(LL i=2; i*i<=n; i++)if(n%i==0){
		while(n%i==0)n/=i;
		ret=ret/i*(i-1);
	}
	if(n>1)ret=ret/n*(n-1);
	return ret;
}
LL n;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%lld",&n);
	LL ans=0;
	for(LL i=1; i*i<=n; i++)
		if(n%i==0){
			ans+=calc(n/i)*i;
			if(i!=n/i)ans+=calc(i)*n/i;
		}
	printf("%lld\n",ans);
	return 0;
}

