#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#include <time.h>
#include <queue>
#define left first
#define right second
#define For(i,b,e) for(int i=b; i<=e; i++)
using namespace std;
struct Block{
	int l,r,h;
	bool operator<(const Block& rhs)const{
		return h<rhs.h;
	}
}b[50010];
bool cmp2(const Block& a,const Block& b){
	return a.l<b.l;
}
int main(){
	freopen("horizon.in","r",stdin);
	freopen("horizon.out","w",stdout);
	int n;
	long t1=clock();
	scanf("%d",&n);
	set<int> st;
	For(i,1,n){
		scanf("%d%d%d",&b[i].l,&b[i].r,&b[i].h);
		st.insert(b[i].l);
		st.insert(b[i].r);
	}
	sort(b+1,b+n+1,cmp2);
	priority_queue<Block> pq;
	int left=*st.begin(),right;
	set<int>::iterator it=st.begin();
	++it;
	int p=1;
	long long ans=0;
	for(; it!=st.end(); ++it){
		right=*it;
		while(p<=n&&b[p].l<=left)
			pq.push(b[p++]);
		while(!pq.empty()&&pq.top().r<=left)
			pq.pop();
		
		if(!pq.empty()){
			ans+=(right-left)*(long long)pq.top().h;
		}
		left=right;
	}
	cout<<ans;
	return 0;
}

