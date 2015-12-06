#include <stdio.h>
#include <algorithm>
using namespace std;
#define For(i,b,e) for(int i=b; i<=e; ++i)
struct Muddy{
	int l,r;
	bool operator<(const Muddy& rhs)const{
		return l<rhs.l;
	}
}mud[10010];
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	int pos=0,n,L,ans=0;
	scanf("%d%d",&n,&L);
	For(i,1,n)
		scanf("%d%d",&mud[i].l,&mud[i].r);
	sort(mud+1,mud+n+1);
	For(i,1,n){
		if(pos>=mud[i].r)continue;
		else{
			pos=max(pos,mud[i].l);
			ans+=(mud[i].r-pos-1)/L+1;
			pos+=((mud[i].r-pos-1)/L+1)*L;
		}
	}
	printf("%d",ans);
	return 0;
}
