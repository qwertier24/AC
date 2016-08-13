#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<list>
#include<queue>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;
#define N 100010
#define sz 320

typedef pair<int,int> pii;
#define MP make_pair

int pre[N], nxt[N], cnt_times[N], a[N], n, Q;

int times[N];
inline void erase(int x) {
  int &t = times[a[x]];
  
  cnt_times[t]--;
  if (cnt_times[t] == 0) {
    nxt[pre[t]] = nxt[t];
    pre[nxt[t]] = pre[t];
  }
  
  t--;
  
  cnt_times[t]++;
  // printf("erase:%d %d %d\n", x, a[x], t);
  if (cnt_times[t] == 1) {
    pre[t] = pre[t + 1];
    nxt[t] = nxt[pre[t + 1]];
    pre[nxt[t]] = nxt[pre[t]] = t;
  }

  if (cnt_times[t+1] == 0) {
    nxt[t + 1] = pre[t + 1] = 0;
  }
}
void insert(int x) {
  int &t = times[a[x]];
  cnt_times[t]--;
  if (cnt_times[t] == 0) {
    nxt[pre[t]] = nxt[t];
    pre[nxt[t]] = pre[t];
  }
  t++;
  cnt_times[t]++;
  // printf("insert:%d %d\n", a[x], t);
  if (cnt_times[t] == 1) {
    nxt[t] = nxt[t - 1];
    pre[t] = pre[nxt[t - 1]];
    pre[nxt[t]] = nxt[pre[t]] = t;
  }
  if (cnt_times[t-1] == 0) {
    nxt[t - 1] = pre[t - 1] = 0;
  }

}

pii que[N];
int query() {
  int ret = 0;
  int fr0 = nxt[0], fr1 = 0, rr1 = -1;
  bool minus = false;
  while (fr0 || (fr1 <= rr1)) {
    pii p;
    if (fr0 && (fr1 > rr1 || fr0 <= que[fr1].first)) {
      p = MP(fr0, cnt_times[fr0]);
      fr0 = nxt[fr0];
    } else {
      p = que[fr1++];
    }
    if (minus)
      p.second--;
    //printf("%d %d %d\n", p.first, p.second, ret);
    minus = false;
    if (!p.second)
      continue;
    if (p.second >= 2) {
      ret += (p.first * 2) * (p.second / 2);
      que[++rr1] = MP(p.first * 2, p.second / 2);
    }
    if (p.second % 2 == 1 && (fr0 || (fr1 <= rr1))) {
      pii p2;
      if (fr0 && (fr1 > rr1 || fr0 <= que[fr1].first)) {
        p2 = MP(fr0, cnt_times[fr0]);
      } else {
        p2 = que[fr1];
      }
      //printf("p2:%d %d %d %d %d\n", p2.first, p2.second, ret, fr1, rr1);
      minus = true;
      p2.second--;
      ret += p.first + p2.first;
      que[++rr1] = MP(p.first + p2.first, 1);
    }
  }
  return ret;
}

void print_debug(int l, int r) {
  printf("%d %d\n", l, r);
  for (int x = nxt[0]; x; x = nxt[x]) {
    printf(" %d %d\n", x, cnt_times[x]);
  }
  puts("");
}

struct Qu {
  int l, r, id;
}q[N];
bool cmp(const Qu & i, const Qu & j) {
  if (i.l / sz == j.l / sz)
    return i.r < j.r;
  else
    return i.l / sz < j.l / sz;
}

int ans[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d", &n);
  FOR (i,n) {
    scanf("%d", &a[i]);
  }

  scanf("%d", &Q);
  FOR (i,Q) {
    scanf("%d%d", &q[i].l, &q[i].r);
    q[i].id = i;
  }
  sort(q + 1, q + Q, cmp);

  int l = 1, r = 0;
  for (int i = 1; i <= Q; i++) {
    while (l > q[i].l) {
      insert(--l);
    }
    while (r < q[i].r) {
      insert(++r);
    }
    while (r > q[i].r) {
      erase(r--);
    }
    while (l < q[i].l) {
      erase(l++);
    }
    //print_debug(l,r);
    ans[q[i].id] = query();
  }

  FOR (i, Q) {
    printf("%d\n", ans[i]);
  }
  
  return 0;
}
