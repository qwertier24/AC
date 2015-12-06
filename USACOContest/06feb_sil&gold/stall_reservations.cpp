#include <stdio.h>
#include <algorithm>
#include <queue>
#include <assert.h>
using namespace std;
struct Stall{
	int ord,r;
	bool operator<(const Stall& rhs)const{
		return r>rhs.r;
	}
};
struct Cow{
	int L,R,ord;
	bool operator<(const Cow& rhs)const{
		return L<rhs.L;
	}
}cow[50010];
int ans[50010];
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d%d",&cow[i].L,&cow[i].R);
		cow[i].ord=i;
	}
	priority_queue<Stall> pq;
	sort(cow+1,cow+n+1);
	for(int i=1; i<=n; i++){
		int l=cow[i].L,r=cow[i].R;
		if(pq.empty()||pq.top().r>=l){
			Stall t;
			t.ord=pq.size()+1;
			t.r=r;
			pq.push(t);
			//assert(pq.size()<=ans);
			ans[cow[i].ord]=t.ord;
		}else{
			Stall t=pq.top();
			pq.pop();
			t.r=r;
			pq.push(t);
			//assert(pq.size()<=ans);
			ans[cow[i].ord]=t.ord;
		}
	}
	printf("%d\n",(int)pq.size());
	for(int i=1; i<=n; ++i)
		printf("%d\n",ans[i]);
	return 0;
}
