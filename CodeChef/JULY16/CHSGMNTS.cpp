#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
#include<iostream>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 1010

int pa[N], sz[N];
int findset(int u){
  if(pa[u] != u)
    pa[u] = findset(pa[u]);
  return pa[u];
}

void union_set(int u, int v){
  if(findset(u) == findset(v))
    return;
  sz[pa[v]] += sz[pa[u]];
  pa[pa[u]] = pa[v];
}

int a[N];
unordered_map<int,int> cnt;
unordered_map<int,vector<int> > pos;
int erase(int x){
  if(cnt[x] == 1){
    int ret = 0;
    for(auto &p : pos[x]){
      int L = sz[findset(p - 1)] + 1, R = sz[findset(p + 1)] + 1;
      //printf("p:%d %d %d\n",p,L,R);
      ret += L * R;
      pa[p] = p;
      sz[p] = 1;
      if(findset(p-1))
        union_set(p-1, p);
      if(findset(p+1))
        union_set(p+1, p);
    }
    cnt[x]--;
    return ret;
  }else{
    cnt[x]--;
    return 0;
  }
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d",&T);
  while(T--){
    int n;
    scanf("%d", &n);
    pos.clear();
    FOR(i,n){
      scanf("%d", &a[i]);
      pos[a[i]].push_back(i);
    }
    LL ans = 0;
    FOR(st, n){
      int cur = 0;
      cnt.clear();
      memset(pa, 0, sizeof(pa));
      memset(sz, 0, sizeof(sz));
      FOR(i,n)
          cnt[a[i]]++;
      FOR(i,st-1)
          cur += erase(a[i]);
      for(int ed = n; ed >= st; ed--){
        ans += cur;
        //printf("%d %d %d\n", st, ed, cur);
        cur += erase(a[ed]);
      }
    }
    cout<<ans/2<<endl;
  }
  return 0;
}
