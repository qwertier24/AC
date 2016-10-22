#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
struct EDGE {
  int u , v , w;
}E[MAXN] ;
int D[MAXN] ;
int val[MAXN] , valbef[MAXN] ;
vector<int> e1[MAXN] , e2[MAXN] , e3[MAXN] ;

void add_edge (int u , int v , int w , int num) {
  E[num].u = u; E[num].v = v ; E[num].w = w;
  if (w == 1) {
    e1[u].push_back(num);
    e3[v].push_back(num);
    ++D[u];
  }
  else {
    e2[u].push_back(num);
    e2[v].push_back(num);
    ++D[u]; ++D[v];
  }
}
queue<int> Que , Del;

int tot_cnt = 0;

void checkdel (int p) {
  if (D[p] == 1) {
    for (int i = 0 ; i < e2[p].size() ; ++i) {
      int x = e2[p][i];
      Que.push(E[x].u == p ? x : -x);
    }
  }
  if (D[p] == 0) {
    ++tot_cnt;
    for (int i = 0 ; i < e3[p].size() ; ++i)
      Que.push(E[e3[p][i]].v);
  }
}

void Del1 (int x) {
  --D[E[x].v];
  checkdel(E[x].v);
}

void Del2 (int x) {
  int p ;
  if (x > 0) 
    --D[p = E[x].v];
  else --D[p = E[-x].u];
  checkdel(p);
}

int main (void) {
  int n , m;
  cin >> n >> m;
  for (int i = 1 , u , v , w ; i <= m ; ++i) {
    scanf("%d%d%d",&u,&v,&w);
    add_edge(u,v,w,i);
  }
  for (int i = 1 ; i <= m ; ++i) {
    if (E[i].w == 1 && D[E[i].v] == 0)
      Que.push(i);
    if (E[i].w == 2 && D[E[i].v] == 1)
      Que.push(i);
    if (E[i].w == 2 && D[E[i].u] == 1)
      Que.push(-i);
  }
  bool flag = true;
  while (flag) {
    while (flag && Que.empty()) {
      if (Del.empty()) flag = false;
      Del2(Del.front()); Del.pop();
    }
    if (flag == false) break;
    int x = Que.front(); Que.pop();
    cerr << x << endl;
    for (int i = 1 ; i <= n ; ++i)
      cerr << val[i] << ' ';
    cerr <<endl;
    if (x > 0) {
      val[E[x].u] = max(val[E[x].u],val[E[x].v]+1);
      if (E[x].w == 1) Del1(x);
      else Del.push(x);
    } else {
      val[E[-x].v] = max(val[E[-x].v],val[E[-x].u]+1);
      Del.push(x);
    }
  }
  if (tot_cnt < n) cout << "Infinite" << endl;
  else {
    int ans = 0;
    for (int i = 1 ; i <= n ; ++i)
      ans = max(ans,val[i]);
    cout << ans << endl;
    for (int i = 1 ; i <= n ; ++i)
      cout << val[i] << ' ';
  }
  
  return 0;
}
