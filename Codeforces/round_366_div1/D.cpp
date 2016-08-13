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

#define N 300010
#define M 5000010
#define INF (N)

namespace nf{
int le[N],pe[M],ecnt,data[M],ev[M];
void addEdge(int u,int v,int cap){
  //printf("edge:%d %d %d\n", u, v, cap);
  pe[ecnt]=le[u];
  ev[ecnt]=v;
  data[ecnt]=cap;
  le[u]=ecnt++;
  
  pe[ecnt]=le[v];
  ev[ecnt]=u;
  data[ecnt]=0;
  le[v]=ecnt++;
}
int S,T;
void init(int s,int t){
  memset(le,-1,sizeof(le));
  ecnt=0;
  S=s,T=t;
}
void setST(int s, int t) {
  S = s, T = t;
}
int dist[N],q[N],front,rear;
int bfs(){
  memset(dist,-1,sizeof(dist));
  front=rear=0;
  q[front]=S;
  dist[S]=0;
  while(front<=rear){
    int u=q[front++];
    for(int i=le[u]; i!=-1; i=pe[i]){
      if(data[i] > 0 && dist[ev[i]]==-1){
        dist[ev[i]]=dist[u]+1;
        q[++rear]=ev[i];
        if (ev[i] == T)
          return 1;
      }
    }
  }
  return 0;
}
int cur[N];
int dfs(int u,int a){
  if(u==T || a==0)return a;
  int ret=0,f;
  for (int &i=cur[u]; i!=-1; i=pe[i]) {
    int &v=ev[i];
    if(dist[v]!=dist[u]+1)continue;
    f=dfs(v,min(a,data[i]));
    data[i]-=f;
    data[i^1]+=f;
    a-=f;
    ret+=f;
    if (a == 0)
      break;
  }
  return ret;
}
int maxFlow(){
  int ret=0;
  while(bfs()){
    memcpy(cur, le, sizeof(le));
    ret+=dfs(S,INF);
  }
  return ret;
}
}

map<int,int> idx, idy, dx, dy, qx, qy;
int eid[N];
int n, m, r, b;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int cnt = 0;
  int s = cnt+0, t = cnt+1;
  int ss = cnt+2, tt = cnt+3;
  cnt += 4;
  nf::init(ss, tt);
  scanf("%d%d", &n, &m);
  scanf("%d%d", &r, &b);
  int flag = 0;
  FOR (i, n) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (i == 1 && x == 772872332) {
      flag = 0;
    }
    if (!idx.count(x)) 
      idx[x] = cnt++;
    qx[x]++;
    if (!idy.count(y)) 
      idy[y] = cnt++;
    qy[y]++;
    eid[i] = nf::ecnt;
    nf::addEdge(idx[x], idy[y], 1);
  }
  FOR (i, m) {
    int t, l, d;
    scanf("%d%d%d", &t, &l, &d);
    if (t == 1) {
      if (!qx.count(l))
        continue;
      if (!dx.count(l))
        dx[l] = INF;
      dx[l] = min(dx[l], d);
    } else {
      if (!qy.count(l))
        continue;
      if (!dy.count(l))
        dy[l] = INF;
      dy[l] = min(dy[l], d);
    }
  }

  int tot = 0;
  for (auto p : qx) {
    int x = p.first;
    int q = qx[x], d = min(q, dx.count(x) ? dx[x] : n);
    int L = max((q - d + 1) / 2, 0), R = (q + d) / 2;
    if (L > R) {
      puts("-1");
      exit(0);
    }
    if (L) {
      nf::addEdge(ss, idx[x], L);
      tot += L;
    }
    if (R - L) {
      nf::addEdge(s, idx[x], R - L);
    }
  }

  int tot2 = 0;
  for (auto p : qy) {
    int y = p.first;
    int q = qy[y], d = min(q, dy.count(y) ? dy[y] : n);
    int L = max((q - d + 1) / 2, 0), R = (q + d) / 2;
    if (L > R) {
      puts("-1");
      exit(0);
    }
    if (L) {
      nf::addEdge(idy[y], tt, L);
      tot2 += L;
    }
    if (R - L) {
      nf::addEdge(idy[y], t, R - L);
    }
  }

  nf::addEdge(ss, t, tot2);
  nf::addEdge(s, tt, tot);
  nf::addEdge(t, s, n + 2);

  if (flag) {
    printf("%d %d %d %d\n", nf::ecnt, cnt, nf::S, nf::T);
    return 0;
  }
  int f = nf::maxFlow();
  if (f != tot + tot2) {
    puts("-1");
    return 0;
  }

  nf::le[ss] = -1;
  nf::le[tt] = -1;

  nf::setST(s, t);
  char rc = 'r', bc = 'b';
  if (r > b) {
    swap(rc, bc);
    swap(r, b);
  }

  f = nf::maxFlow();
  printf("%I64d\n", 1ll * f * r + 1ll * (n - f) * b);

  FOR (i, n) {
    if (nf::data[eid[i]] == 0) {
      printf("%c", rc);
    } else {
      printf("%c", bc);
    }
  }

  return 0;
}
