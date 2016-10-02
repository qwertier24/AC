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

#define N 1010

int n, m;

struct Query{
  int i, j, op;
}q[100010];

vector<int> adj[100010];
int cur;
int state[N][N], inv[N], cnt[N], ans[100010];
void dfs(int u) {
  //printf("u:%d\n", u);
  int done = 0;
  if (q[u].op == 4) {
    ans[u] = cur;
  } else if(q[u].op == 1) {
    if (state[q[u].i][q[u].j] ^ inv[q[u].i] == 0) {
      done = 1;
      state[q[u].i][q[u].j] ^= 1;
      cnt[q[u].i] ++;
      cur++;
    }
  } else if(q[u].op == 2) {
    if (state[q[u].i][q[u].j] ^ inv[q[u].i] == 1) {
      done = 1;
      state[q[u].i][q[u].j] ^= 1;
      cnt[q[u].i]--;
      cur--;
    }
  } else if(q[u].op == 3) {
    inv[q[u].i] ^= 1;
    cur -= cnt[q[u].i];
    cnt[q[u].i] = m - cnt[q[u].i];
    cur += cnt[q[u].i];
    done = 1;
  }
  ans[u] = cur;
  //printf("u:%d %d\n", u, cur);
  for (int v : adj[u]) {
    dfs(v);
  }
  if (done) {
    if (q[u].op==1 || q[u].op == 2) {
      state[q[u].i][q[u].j] ^= 1;
      if (q[u].op==1) {
        cur--;
        cnt[q[u].i]--;
      } else {
        cur++;
        cnt[q[u].i]++;
      }
    } else if(q[u].op == 3) {
      inv[q[u].i] ^= 1;
      cur -= cnt[q[u].i];
      cnt[q[u].i] = m- cnt[q[u].i];
      cur+=cnt[q[u].i];
    }
  }
}

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int Q;
  scanf("%d%d%d", &n, &m, &Q);
  FOR (i, Q) {
    scanf("%d", &q[i].op);
    if (q[i].op == 1 || q[i].op == 2) {
      scanf("%d%d", &q[i].i, &q[i].j);
      adj[i-1].push_back(i);
    } else if (q[i].op == 3) {
      scanf("%d", &q[i].i);
      adj[i-1].push_back(i);
    } else if (q[i].op == 4) {
      int k;
      scanf("%d", &k);
      adj[k].push_back(i);
    }
  }
  dfs(0);
  FOR (i, Q)
      printf("%d\n", ans[i]);
  return 0;
}
