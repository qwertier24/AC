#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define p 10000019
#define q 1000000007

int pp[1010];
void init(){
  pp[0]=1;
  for(int i=1; i<=1000; i++)
    pp[i]=(pp[i-1]*(LL)p)%q;
}

int k;
void redp(int *dp,int v,int w){
  for(int i=k; i>=w; i--)
    dp[i]=max(dp[i],dp[i-w]+v);
}

#define N 35010
int w[N],v[N];
int qn;
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
vector<int> S[N<<2];
void dfs(int L,int R,int i,int o=1,int l=1,int r=qn){
  if(L>R)return;
  if(L<=l && r<=R){
    S[o].push_back(i);
    return;
  }
  if(L<=mid)
    dfs(L,R,i,lc,l,mid);
  if(R>mid)
    dfs(L,R,i,rc,mid+1,r);
}

int dp[30][1010];
void calc(int o=1,int l=1,int r=qn,int dep=1){
  memcpy(dp[dep],dp[dep-1],sizeof(dp[dep-1]));
  REP(i,S[o].size())
    redp(dp[dep],v[S[o][i]],w[S[o][i]]);
  if(l==r){
    int res=0;
    FOR(j,k)
      res=(res+dp[dep][j]*(LL)pp[j-1])%q;
    printf("%d\n",res);
    return;
  }
  calc(lc,l,mid,dep+1);
  calc(rc,mid+1,r,dep+1);
}

pii ti[N];

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  init();
  int n;
  scanf("%d%d",&n,&k);
  FOR(i,n){
    scanf("%d%d",&v[i],&w[i]);
    ti[i].first=1;
    ti[i].second=q;
  }
  int Q;
  scanf("%d",&Q);
  FOR(i,Q){
    int op;
    scanf("%d",&op);
    if(op==1){
      n++;
      scanf("%d%d",&v[n],&w[n]);
      ti[n].first=qn+1;
      ti[n].second=p;
    }else if(op==2){
      int x;
      scanf("%d",&x);
      ti[x].second=qn;
    }else{
      qn++;
    }
  }
  FOR(i,n)
    dfs(ti[i].first,ti[i].second,i);
  calc();
  return 0;
}
