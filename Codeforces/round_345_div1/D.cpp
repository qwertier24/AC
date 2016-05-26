#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 400010

int  m;
pii b[N];

struct SegTree{
#define mid ((l+r)>>1)
#define lc (o<<1)
#define rc (o<<1|1)
  int maxv[N<<2];
  int getv(int o, int l, int r, int L, int R){
    if(b[l].first > R || b[r].first < L)
      return 0;
    if(L <= b[l].first && b[r].first <= R)
      return maxv[o];
    
    int ret = 0;
    if(b[mid].first >= L)
      ret = max(ret, getv(lc, l, mid, L, R));
    if(b[mid + 1].first <= R)
      ret = max(ret, getv(rc, mid + 1, r, L, R));
    return ret;
  }
  void modi(int o, int l, int r, int p, int v){
    if(l==r){
      maxv[o] = v;
      return;
    }
    if(p<=mid)
      modi(lc,l,mid,p,v);
    else
      modi(rc,mid+1,r,p,v);
    maxv[o]=max(maxv[lc],maxv[rc]);
  }
}tree[2];

#define INF (1<<30)
int ans[N];
int L[N], R[N], n, a[N], id[N], g[N];

vector<pii> q[N];
int cnt[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  FOR(i,n){
    scanf("%d",&a[i]);
    b[i] = MP(a[i],i);
  }

  sort(b+1,b+n+1);
  FOR(i,n)
    id[b[i].second] = i;

  int maxl = 0;

  FOR(i,n)
    g[i] = 1<<30;
  FOR(i,n){
    L[i] = lower_bound(g+1, g+n+1, a[i]) - g;
    g[L[i]] = a[i];
    maxl = max(maxl, L[i]);
  }
  FOR(i,n)
    g[i] = 1<<30;
  for(int i = n; i >= 1; i--){
    R[i] = lower_bound(g+1, g+n+1, -a[i]) - g;
    g[R[i]] = -a[i];
    if(L[i] + R[i] - 1 == maxl)
      cnt[L[i]]++;
  }
  
  REP(i,m){
    int j,k;
    scanf("%d%d",&j,&k);
    q[j].push_back(MP(i,k));
  }
  FOR(i,n)
    tree[1].modi(1,1,n,id[i],R[i]);
  FOR(i,n){
    tree[1].modi(1,1,n,id[i],0);
    for(auto& qu : q[i]){
      int v = qu.second;
      ans[qu.first] = tree[0].getv(1, 1, n, 0, v-1) + 1 + tree[1].getv(1, 1, n, v+1, INF);
      if(L[i] + R[i] - 1 != maxl || cnt[L[i]] > 1)
        ans[qu.first] = max(ans[qu.first], maxl);
      else
        ans[qu.first] = max(ans[qu.first], maxl - 1);
    }
    tree[0].modi(1,1,n,id[i],L[i]);
  }
  REP(i,m)
    printf("%d\n",ans[i]);
  return 0;
}
