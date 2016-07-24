#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#include<iostream>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 510
#define M 1000000
#define INF (1<<30)

int n, m, b, c;
int g[N][N],  power[N], init[N];
int mark[N];
int task[N];

void print_cost(){
  int mint = INF, maxt = -INF;
  REP(i,m){
    mint = min(mint, task[i]);
    maxt = max(maxt, task[i]);
  }
  printf(" %d %d %d %d\n", mint, maxt, maxt- mint, m);

}

int id[N];
bool cmp(const int &i, const int &j){
  return power[i] > power[j];
}

LL tot = 0;
int ans[N];
void doit(){
  memset(mark, 0, sizeof(mark));
  fflush(stdout);
  priority_queue<pii, vector<pii>, greater<pii> > pq;
  REP (i,n) {
    pq.push(MP(task[i],i));
  }
  REP (i,b) {
    scanf("%d%d", &init[i], &power[i]);
    //init[i] = rand() % n + 1;power[i] = rand() % 1000 + 1;
    init[i]--;
    tot += power[i];
    ans[i] = init[i];
  }
  int avg = tot / n;
  REP (i,n) {
    id[i] = i;
  }
  sort(id, id+n, cmp);
  
  REP (j,b) {
    int i = id[j];
    int cur = pq.top().second;
    //printf("%d %d\n", i, cur);
    pq.pop();
    if(g[init[i]][cur] <= c){
      c -= g[init[i]][cur];
      task[cur] += power[i];
      ans[i] = cur;
    }
    pq.push(MP(task[cur], cur));
    //printf("%d\n", ans+1);
  }
  REP (i,b)
      printf("%d\n", ans[i] + 1);
  //print_cost();
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d%d%d%d", &n, &m, &b,&c);
  //n = m = b = 500; c = rand() * rand() % (400 * n * m) + 100 * n *m;
  REP(i,n)REP(j,n){
    scanf("%d", &g[i][j]);
    //if(i==j)g[i][j] = 0;    else g[i][j] = rand() % 1000 + 1;
  }
  REP(k,n)REP(i,n)REP(j,n){
    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
  }
  REP(i,m)
    doit();
  return 0;
}
