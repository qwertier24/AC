#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<set>
#define FOR(i,n) for(int i= 1; i<=n;i++)
#define REP(i,n) for(int i = 0; i< n;i++)


typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define N 10010
#define MAXN 5000000

struct node{
	int l,r,maxn;
}a[MAXN];

#define lc (a[o].l)
#define rc (a[o].r)
#define mid ((l+r)>>1)

int cnt;
int Newnode(){
	++cnt;a[cnt].l = a[cnt].r = a[cnt].maxn = 0;
	return cnt;
}

void Update(int o){
	int ans = 0;
	if(lc)
		ans = a[lc].maxn;
	if(rc)
		ans = max(ans,a[rc].maxn);
	a[o].maxn = ans;
}


void Query(int o,int l,int r,int L,int R,int &tmp){
	if (!o) return;
	if (L <= l && r <= R){
		tmp = max(tmp,a[o].maxn);
		return;
	}
	if (L <= mid)
		Query(lc,l,mid,L,R,tmp);
	if (mid + 1 <= R)
		Query(rc,mid + 1,r,L,R,tmp);
}

void Insert(int o,int l,int r,int p,int d){
	if (l == r){
		a[o].maxn = max(a[o].maxn,d);
		return;
	}
	if(p <= mid){
		if (!lc) lc = Newnode();
		Insert(lc,l,mid,p,d);
	}else {
		if (!rc) rc = Newnode();
		Insert(rc,mid + 1,r,p,d);
	}
	Update(o);
}


struct Inte{
	int x,y,z,d;
    int l,r;
    bool operator<(const Inte & rhs)const{
        if(d == rhs.d){
            if(l == rhs.l)
                return r < rhs.r;
            else
                return l < rhs.l;
        }else
            return d > rhs.d;
    }
}inte[N];

int n,m;
bool cmp(const Inte & a,const Inte & b){
	if (a.d != b.d) return a.d > b.d;
	return a.l < b.l || (a.l == b.l && a.r < b.r);
}

int main(){
#ifdef QWERTIER
    freopen("C.in","r",stdin);
#endif
    int T;
	scanf("%d",&T);
	for (int tt = 1;tt <= T;tt++){
		scanf("%d",&n);
        m = 0;
		FOR(i,n){
			scanf("%d%d%d%d",&inte[i].x,&inte[i].y,&inte[i].z,&inte[i].d);
			if (inte[i].d == 1) m++;
			inte[i].l = inte[i].y - inte[i].z;
			inte[i].r = inte[i].x + inte[i].z;
		}
        multiset<int> mst;
        multiset<int> ::iterator it;
		sort(inte + 1,inte + n + 1);
		cnt = 1;a[1].l = a[1].r = a[1].maxn = 0;
		int res = 0 , cur = 0;
		FOR(i,m){
			if (inte[i].l > inte[i].r) continue;
			while (!mst.empty()){
				it = mst.begin();
				if (*it < inte[i].l){
					mst.erase(it);cur--;
				}else break;
			}
			mst.insert(inte[i].r);
			cur++;
			res = max(res,cur);
			Insert(1,-2e6,2e6,inte[i].l,cur);
		}
        
		mst.clear();
        cur = 0;

		for (int i = m + 1; i <= n; i++){
			if (inte[i].l > inte[i].r)
                continue;

			while (!mst.empty()){
				it = mst.begin();
				if (*it < inte[i].l){
					int tmp = 0;
					Query(1,-2000000,2000000,-2000000,*it,tmp);
					res = max(res, cur + tmp);
					mst.erase(it);
                    cur--;
				}else break;
			}
            
			mst.insert(inte[i].r);
			cur++;
		}

		while (!mst.empty()){
			it = mst.begin();
			int tmp = 0;
            Query(1,-2000000,2000000,-2000000,*it,tmp);
			res = max(res,cur + tmp);
			mst.erase(it);cur--;
		}
		printf("Case #%d:\n%d\n",tt,res);
	}
	return 0;
}
