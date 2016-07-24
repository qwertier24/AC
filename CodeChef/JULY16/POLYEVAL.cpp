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
#define MOD 786433
#define N MOD
#define ORT 10
#define m0 (MOD - 1)

LL pt[N];
void init(){
  pt[0] = 1;
  FOR(i,MOD-1)
      pt[i] = pt[i-1] * ORT % MOD;
}

void calc(vector<int> &a, vector<int> &y){
  vector<int> a0, a1;
  int m = a.size();
  REP(i, m){
    if(i % 2){
      a1.push_back(a[i]);
    }else{
      a0.push_back(a[i]);
    }
  }
  LL x0 = pt[m0 / m];
  if(m > 3){
    vector<int> y0(m/2), y1(m/2);
    calc(a0, y0);
    calc(a1, y1);
    LL x = 1;
    REP(i,m/2){
      y[i] = (y0[i] + x * y1[i]) % MOD;
      y[i+m/2] = (y0[i] + pt[m0/2] * x * y1[i]) % MOD;
      x = x * x0 % MOD;
    }
  }else{
    //printf("%d\n", m);
    LL x = 1;
    REP(i,m){
      y[i] = (a[0] + x * a[1] + x * x * a[2]) % MOD;
      x = x * x0 % MOD;
    }
  }
}

int a[N],ans[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  init();
  int n;
  scanf("%d",&n);
  vector<int> a(MOD-1), y(MOD-1);
  REP(i,n+1)scanf("%d", &a[i]);
  calc(a, y);
  REP(i,MOD-1){
    ans[pt[i]] = y[i];
  }
  int Q;
  scanf("%d", &Q);
  ans[0] = a[0];
  while(Q--){
    int v;
    scanf("%d", &v);
    printf("%d\n", ans[v]);
  }
  return 0;
}
