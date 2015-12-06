#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
int L,R,maxv[40010],decv[40010]={0},dect,_max;
int n,I,H,m;
map<pair<int,int>,int> done;
void Build(int o,int l,int r){
	maxv[o]=H;
	if(l==r)return;
	int m=(l+r)>>1;
	Build(o<<1,l,m);
	Build(o<<1|1,m+1,r);
}
inline void maintain(int o){
	maxv[o]=max(maxv[o<<1],maxv[o<<1|1]);
}
void dec(int o,int l,int r){
	if(L<=l&&R>=r){
		decv[o]+=dect;
		maxv[o]-=dect;
		return;
	}
	int m=(l+r)>>1;
	if(m>=L)dec(o<<1,l,m);
	if(m<R)dec(o<<1|1,m+1,r);
	maintain(o);
}
void Dec(int l,int r){
	if(l>r)return;
	dect=1;
	L=l,R=r;
	dec(1,1,n);
}
void query(int o,int l,int r,int dec_sum){
	if(L<=l&&R>=r){
		_max=max(_max,maxv[o]-dec_sum);
		return;
	}
	int m=(l+r)>>1;
	if(L<=m)query(o<<1,l,m,dec_sum+decv[o]);
	if(R>m)query(o<<1|1,m+1,r,dec_sum+decv[o]);
}
int Query(int l,int r){
	L=l,R=r;
	_max=0;
	query(1,1,n,0);
	return _max;
}
void print(int o,int l,int r){
	printf("%d %d %d %d\n",l,r,maxv[o],decv[o]);
	if(l<r)
		print(o<<1,l,(l+r)>>1),print(o<<1|1,((l+r)>>1)+1,r);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	scanf("%d%d%d%d",&n,&I,&H,&m);
	Build(1,1,n);
	for(int i=1; i<=m; i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>b)swap(a,b);
		if(!done[make_pair(a,b)]){
			Dec(a+1,b-1);
			//printf("query(2):%d\n",Query(2,2));
			//print(1,1,n);
			done[make_pair(a,b)]=1;
		}
	}
	for(int i=1; i<=n; i++)
		printf("%d\n",Query(i,i));
	return 0;
}
