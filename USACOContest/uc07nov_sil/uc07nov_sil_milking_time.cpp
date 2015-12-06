#include <stdio.h>
#include <algorithm>
#define For(i,b,e) for(int i=b; i<=e; ++i)
using namespace std;
int d[1010]={0};
struct Interval{
	int l,r,eff;
	bool operator<(const Interval& rhs)const{
		return l<rhs.l;
	}
}interval[1010]={0};
int n,m,r;
bool over_lapping(const Interval& a,const Interval& b){
	return a.r>b.l-r;
}
int main(){
	freopen("prob.in","r",stdin);
	int ans=0;
	scanf("%d%d%d",&n,&m,&r);
	For(i,1,m)
		scanf("%d%d%d",&interval[i].l,&interval[i].r,&interval[i].eff);
	//printf("%d\n",over_lapping(interval[1],interval[4]));
	sort(interval+1,interval+m+1);
	For(i,1,m){
		d[i]=interval[i].eff;
		For(j,1,i-1){
			//printf("%d %d %d %d\n",i,j,interval[i].eff,!over_lapping(interval[i],interval[j]));
			if(!over_lapping(interval[j],interval[i])){
				d[i]=max(d[i],d[j]+interval[i].eff);
				//printf("%d %d %d\n",i,j,interval[i].eff);
			}
		}
		ans=max(ans,d[i]);
	}
	printf("%d",ans);
	return 0;
}
