#include <stdio.h>
#include <algorithm>
using namespace std;
struct Cow{
	int t,d;
	bool operator<(const Cow& rhs)const{
		return t*rhs.d<rhs.t*d;
	}
}cow[100010];
int n;
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d%d",&cow[i].t,&cow[i].d);
	sort(cow+1,cow+n+1);
	long long loss=0,t=0;
	for(int i=1; i<=n; i++){
		loss+=t*cow[i].d;
		t+=cow[i].t*2;
	}
	printf("%lld",loss);
	return 0;
}
