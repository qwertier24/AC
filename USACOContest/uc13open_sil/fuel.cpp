#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <stack>
#define For(i,b,e) for(int i=b; i<=e; i++)
using namespace std;
struct Sta{
	int x,cost;
	bool operator<(const Sta& rhs)const{
		return x<rhs.x;
	}
}station[50010];
int n,cap,f0,dist,d[50010];
int main(){
	freopen("fuel.in","r",stdin);
	freopen("fuel.out","w",stdout);
	scanf("%d%d%d%d",&n,&cap,&f0,&dist);
	For(i,1,n)scanf("%d%d",&station[i].x,&station[i].cost);
	station[++n].cost=0;
	station[n].x=dist;
	sort(station+1,station+n+1);
	stack<int> st;
	st.push(n);
	for(int i=n-1; i>=1; i--){
		while(!st.empty()&&station[st.top()].cost>station[i].cost)
			st.pop();
		d[i]=station[st.top()].x;
		st.push(i);
		//printf("%d %d %d\n",i,station[i].x,d[i]);
	}
	int cur_x=0,cur_f=f0;
	long long ans=0;
	for(int i=1; i<=n; i++){
		if(station[i].x-cur_x>cur_f){
			printf("-1\n");
			return 0;
		}
		cur_f-=station[i].x-cur_x;
		cur_x=station[i].x;
		if(cur_f<d[i]-cur_x){
			int add=min(cap,d[i]-cur_x)-cur_f;
			ans+=add*(long long)station[i].cost;
			cur_f+=add;
		}
		//printf("%d %d %d %lld\n",i,cur_x,cur_f,ans);
	}
	cout<<ans;
	return 0;
}
