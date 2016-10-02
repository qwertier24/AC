#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#define REP(i, n) for(int i = 0, ed_##i = n; i < ed_##i; i++)
#define FOR(i, n) for(int i = 1, ed_##i = n; i <= ed_##i; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

namespace SAM {
#define SIGMA_SIZE 26
#define SZ 500010
int to[SZ][SIGMA_SIZE], sz = 0, maxl[SZ], fa[SZ];
int insert(int c, int st, int lst) {
  int cur = ++sz;
  maxl[cur] = maxl[lst] + 1;

  int p = lst;
  while (p && !to[p][c]) {
    to[p][c] = cur;
    p = fa[p];
  }

  if (!p) {
    fa[cur] = st;
    return cur;
  }

  int q = to[p][c];
  if (maxl[p] + 1 == maxl[q]) {
    fa[cur] = q;
  } else {
    int sq = ++sz;
    maxl[sq] = maxl[p] + 1;
    memcpy(to[sq], to[q], sizeof(to[q]));
    while (p && to[p][c] == q) {
      to[p][c] = sq;
      p = fa[p];
    }
    fa[sq] = fa[q];
    fa[q] = sq;
    fa[cur] = sq;
  }
  return cur;
}
void get_sam(char *s) {
  int lst = 1;
  int st = ++sz;
  while (*s) {
    lst = insert(*s -'a', st, lst);
    s++;
  }
}
int get_lcp_len(char *t) {
  int cur = 1, curl = 0, ret = 0;
  while (*t) {
    int c = (*t++) - 'a';
    while (!to[cur][c] && cur != 1) {
      //printf("cur:%d %d\n", cur, fa[cur]);
      cur = fa[cur];
      curl = maxl[cur];
    }
    if (to[cur][c]) {
      cur = to[cur][c];
      curl++;
    }
    //printf("%d %d\n", cur, curl);
    ret = max(ret, curl);
  }
  return ret;
}
}

char s[SZ], t[SZ];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%s%s", s, t);
  SAM::get_sam(s);
  printf("%d", SAM::get_lcp_len(t));
  return 0;
}
