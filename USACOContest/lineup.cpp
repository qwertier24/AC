#include <stdio.h>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>
#define For(i,b,e) for(int i=b; i<=(e); ++i)
using namespace std;
map<int,int> mp;
int id[100010];
struct SegTree{
	int n,maxv[400010],val[400010],P,addt;
	SegTree(int size){
		n=size;
		memset(val,0,sizeof(val));
		memset(maxv,0,sizeof(maxv));
	}
	void add(int p,int t){
		P=p;
		addt=t;
		Add(1,1,n);
	}
	void Add(int o,int l,int r){
		if(l==r){
			val[l]+=addt;
			maxv[o]=val[l];
			return;
		}
		int m=(l+r)>>1;
		if(P<=m)Add(o<<1,l,m);
		else Add(o<<1|1,m+1,r);
		maxv[o]=max(maxv[o<<1],maxv[o<<1|1]);
	}
	int max_val(){
		return maxv[1];
	}
	int get(int p){
		return val[p];
	}
};
int main(){
	int n,k;
	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout);
	scanf("%d%d",&n,&k);
	For(i,1,n){
		scanf("%d",&id[i]);
		if(!mp.count(id[i]))
			mp[id[i]]=mp.size();
		id[i]=mp[id[i]];
	}
	int l=1,ans=0;
	set<int> st;
	SegTree segTree(mp.size());
	For(i,1,n){
		st.insert(id[i]);
		segTree.add(id[i],1);
		while(st.size()>k+1){
			segTree.add(id[l],-1);
			if(segTree.get(id[l])==0)
				st.erase(st.lower_bound(id[l]));
			l++;
		}
		//printf("%d %d %d %d\n",i,id[i],segTree.get(id[i]),l);
		ans=max(ans,segTree.max_val());
	}
	printf("%d",ans);
	return 0;
}
