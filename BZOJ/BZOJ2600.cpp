#include <algorithm>
#include <stdio.h>
#include <string.h>
typedef long long LL;
using namespace std;
#define N 100010

int n,l,a[N];
LL m,sum[N];
bool check(int l,int r){
	int mid=(l+r)/2;
	return a[mid]*LL(mid-l+1)-(sum[mid]-sum[l-1]) + sum[r]-sum[mid]-a[mid]*LL(r-mid)<=m;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d%lld",&n,&l,&m);
	l=1;
	int ans=0;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]+a[i];
		while(!check(l,i))l++;
		ans=max(ans,i-l+1);
	}
	printf("%d",ans);
	return 0;
}

