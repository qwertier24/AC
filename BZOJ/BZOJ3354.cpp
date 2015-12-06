#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

typedef long long LL;
#define N 500010
struct P{
	int fee,rank;
	bool operator<(const P& rhs)const{
		return fee*rhs.rank < rhs.fee*rank;
	}
}a[N];
int n;
LL m;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%lld",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%d%d",&a[i].fee,&a[i].rank);
	}
	sort(a+1,a+n+1);
	LL sum=0;
	int ans=0;
	priority_queue<int> pq;
	for(int i=1; i<=n; i++){
		pq.push(a[i].rank);
		sum+=a[i].rank;
		while(a[i].fee*sum>a[i].rank*m){
			sum-=pq.top();
			pq.pop();
		}
		ans=max(ans,(int)pq.size());
	}
	printf("%d\n",ans);
	return 0;
}

