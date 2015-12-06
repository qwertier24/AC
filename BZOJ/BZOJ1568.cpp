#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <set>
#include <math.h>
using namespace std;

typedef long long LL;
const int n=50000;

namespace segTree{
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
	int setv[n<<2],L,R,sett,P;
	void pushdown(int o){
		if(setv[o]!=-1){
			setv[lc]=setv[rc]=setv[o];
			setv[o]=-1;
		}
	}
	void update(int o=1,int l=1,int r=n){
		if(L<=l && r<=R){
			setv[o]=sett;
			return;
		}
		pushdown(o);
		if(L<=mid)update(lc,l,mid);
		if(R>mid)update(rc,mid+1,r);
	}
	void Update(int l,int r,int v){
		l=max(1,l);
		r=min(n,r);
		if(l>r)return;
		L=l,R=r,sett=v;
		update();
	}
	int query(int o=1,int l=1,int r=n){
		if(l==r)return setv[o];
		pushdown(o);
		if(P<=mid)return query(lc,l,mid);
		if(P>mid)return query(rc,mid+1,r);
	}
	int Query(int p){
		P=p;
		return query();
	}
	void init(){
		memset(setv,-1,sizeof(setv));
		setv[1]=0;
	}
}

struct Line{
	double k,b;
	bool operator<(const Line &rhs)const{
		return k<rhs.k;
	}
	Line(double c=0,double d=0):k(c),b(d){}
}line[n<<2];

set<Line>::iterator L,R,it;
set<Line> st;
inline bool check(const Line &a,const Line &b,const Line &c){
	//printf("%d %d %d %d %d %d\n",a.k,a.b,b.k,b.b,c.k,c.b);
	return (a.b-b.b)*(c.k-a.k)<(a.b-c.b)*(b.k-a.k);
}
void addline(int cur){
	R=st.lower_bound(line[cur]);
	L=R;
	L--;
	if(R->k==line[cur].k){
		if(R->b>=line[cur].b)return;
		st.erase(R);
		st.insert(line[cur]);
	}else{
		if(!check(*L,line[cur],*R))return;
		st.insert(line[cur]);
	}
	R=st.lower_bound(line[cur]);
	--R;
	while(R!=st.begin()){
		L=R;
		--L;
		if(check(*L,*R,line[cur]))break;
		st.erase(R);
		R=L;
	}
	L=st.lower_bound(line[cur]);
	++L;
	R=L;
	++R;
	while(R!=st.end()){
		if(check(line[cur],*L,*R))break;
		st.erase(L);
		L=R;
		++R;
	}
	L=R=st.lower_bound(line[cur]);
	--L;
	++R;
	int l=max(1.0,ceil((L->b-line[cur].b)/(line[cur].k-L->k))),r=min((double)n,(line[cur].b-R->b)/(R->k-line[cur].k));
	//printf("%d %d\n",l,r);
	segTree::Update(l+1,r+1,cur);
}
char op[20];
int m;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	st.insert(Line(0,0));
	st.insert(Line(101,-1e20));
	segTree::init();
	scanf("%d",&m);
	for(int i=1; i<=m; i++){
		scanf("%s",op);
		if(op[0]=='Q'){
			int p;
			scanf("%d",&p);
			int r=segTree::Query(p);
			printf("%d\n",(int)((p-1)*line[r].k+line[r].b)/100);
		}else{
			scanf("%lf%lf",&line[i].b,&line[i].k);
			addline(i);
			//printf("%d %d\n",line[i].b,line[i].k);
		}
	}
	return 0;
}

