#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

int dig(LL u) {
  int ret = 0;
  while (u) {
    u /= 2;
    ret++;
  }
  return ret;
}
map<LL, LL> cost;
void modify(LL u, LL v, int w) {
  if (u < v)
    swap(u, v);
  while (dig(u) > dig(v)) {
    //printf(" %d\n", u);
    cost[u]+=w;
    u /= 2;
  }
  while (u != v) {
    //printf(" %d\n %d\n", u, v);
    cost[u] += w;
    cost[v] += w;
    u /= 2;
    v /= 2;
  }
}
LL query(LL u, LL v) {
  LL ret = 0;
  if (u < v)
    swap(u, v);
  while (dig(u) > dig(v)) {
    ret += cost[u];
    u /= 2;
  }
  while (u != v) {
    ret += cost[u] + cost[v];
    u /= 2;
    v /= 2;
  }
  return ret;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int Q;
  scanf("%d", &Q);
  while(Q--){
    int op, w;
    LL u, v;
    scanf("%d", &op);
    if (op == 1) {
      scanf("%I64d%I64d%d", &u, &v, &w);
      modify(u, v, w);
    } else {
      scanf("%I64d%I64d", &u, &v);
      printf("%I64d\n", query(u,v));
    }
  }
  return 0;
}