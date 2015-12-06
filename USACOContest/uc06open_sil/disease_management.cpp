#include <stdio.h>
#include <algorithm>
using namespace std;
int n,d,k,dis[1010]={0},mil[1010];
int calc(int p){
	int ret=0;
	for(int i=1; i<=n; ++i)
		if((dis[i]|p)==p)
			ret++;
	return ret;
}
bool check(int p){
	int cnt=0;
	for(int i=0; i<d; ++i)
		if((p>>i)&1)
			cnt++;
	return cnt==k;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	scanf("%d%d%d",&n,&d,&k);
	int ans=0;
	for(int i=1; i<=n; i++){
		int nt,t;
		scanf("%d",&nt);
		for(int j=1; j<=nt; ++j){
			scanf("%d",&t);
			dis[i]|=(1<<(t-1));
		}
		//printf("%d %d\n",i,dis[i]);
	}
	for(int i=0; i<(1<<d); ++i)
		if(check(i))
		ans=max(ans,calc(i));
	printf("%d",ans);
	return 0;
}
