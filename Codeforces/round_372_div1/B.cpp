#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#include<iostream>
#define REP(i, n) for(int i = 0, ed_##i = n; i < ed_##i; i++)
#define FOR(i, n) for(int i = 1, ed_##i = n; i <= ed_##i; i++)
#define bit(x) (1 << (x))
#define bitl(x) (1LL << (x))
#define sqr(x) ((x) * (x))
#define sz(x) ((int)(x.size()))
#define cnti(x) (__builtin_popcount(x))
#define cntl(x) (__builtin_popcountll(x))
#define clzi(x) (__builtin_clz(x))  // Leading zeros
#define clzl(x) (__builtin_clzll(x))
#define ctzi(x) (__builtin_ctz(x))
#define ctzl(x) (__builtin_ctzll(x))

#ifdef QWERTIER
#define err(x) cerr << #x << " : " << x << endl
#else
#define err(x)
#endif

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 1010
#define M 50010

int le[N], ev[M], ew[M], ecnt, pe[M];
void addEdge(int u, int v, int w) {
  ecnt++;
  pe[ecnt] = le[u];
  le[u] = ecnt;
  ev[ecnt] = v;
  ew[ecnt] = w;
}

LL diss[N], dist[N];

int inq[N];
void songchi(int u, int v, LL *dis, int w) {
  queue<int> q;
  memset(inq, 0, sizeof(inq));
  if (dis[u] > dis[v] + w) {
    dis[u] = dis[v] + w;
    q.push(u);
    inq[u] = 1;
  }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    inq[u] = 0;
    for (int i = le[u]; i; i = pe[i]) {
      if (dis[ev[i]] > dis[u] + ew[i]) {
        dis[ev[i]] = dis[u] + ew[i];
        if (!inq[ev[i]]) {
          inq[ev[i]] = 1;
          q.push(ev[i]);
        }
      }
    }
  }
}

#define INF (1000000000000000ll)
void spfa(int s, LL *dis) {
  memset(inq, 0, sizeof(inq));
  memset(dis, 0x3f, sizeof(LL)*N);
  queue<int> q;
  dis[s] = 0;
  q.push(s);
  inq[s] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    inq[u] = 0;
    for (int i = le[u]; i; i = pe[i]) {
      if (dis[ev[i]] > dis[u] + ew[i]) {
        dis[ev[i]] = dis[u] + ew[i];
        if (!inq[ev[i]]) {
          inq[ev[i]] = 1;
          q.push(ev[i]);
        }
      }
    }
  }
}

LL ans[M];
int u[M], v[M], w[M];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int n, m, L, s, t;
  scanf("%d%d%d%d%d", &n, &m, &L, &s, &t);
  FOR (i, m) {
    scanf("%d%d%d", &u[i], &v[i], &w[i]);
    if (w[i]) {

      addEdge(u[i], v[i], w[i]);
      addEdge(v[i], u[i], w[i]);
    }
  }
  spfa(s, diss);
  spfa(t, dist);
  if (diss[t] < L) {
    puts("NO");
  } else if (diss[t] == L) {
    puts("YES");
    FOR (i, m) {
      if (w[i] == 0) {
        printf("%d %d %d\n", u[i], v[i], 1000000001);
      } else {
        printf("%d %d %d\n", u[i], v[i], w[i]);
      }
    }
  } else {
    FOR (i, m) {
      int u = ::u[i], v = ::v[i], w = ::w[i];
      if (!w) {
        if (diss[t] > L) {
          ans[i] = 1;
          if (diss[u] < INF && dist[v] < INF) {
            ans[i] = max(ans[i], L - diss[u] - dist[v]);
          }
          if (diss[v] < INF && dist[u] < INF) {
            ans[i] = max(ans[i], L - diss[v] - dist[u]);
          }

          if (ans[i]==0)while(true);
          addEdge(u, v, ans[i]);
          addEdge(v, u, ans[i]);
          songchi(u, v, diss, ans[i]);
          songchi(u, v, dist, ans[i]);
          songchi(v, u, diss, ans[i]);
          songchi(v, u, dist, ans[i]);
        } else {
          ans[i] = 1000000001;
        }
      }
    }
    if (diss[t] != L) {
      puts("NO");
      return 0;
    }
    puts("YES");
    FOR (i, m) {
      if (!w[i]) {
        printf("%d %d %I64d\n", u[i], v[i], ans[i]);
      } else {
        printf("%d %d %d\n", u[i], v[i], w[i]);
      }
    }
  }
  return 0;
}
