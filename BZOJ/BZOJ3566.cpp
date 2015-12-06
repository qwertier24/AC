#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 500010

#define MP make_pair
vector<pair<int,double> > adj[N];
vector<double> pre[N];
vector<double> suf[N];

double f[N],p[N];
void dfs(int u,int fa){
  for(int i=0; i<adj[u].size(); i++){
    if(adj[u][i].first==fa)adj[u].erase(adj[u].begin()+i);
    if(i>=adj[u].size())break;
    int &v=adj[u][i].first;
    dfs(v,u);
    pre[u].push_back(f[v]+(1-f[v])*(1-adj[u][i].second));
  }
  suf[u]=vector<double>(pre[u].size());
  for(int i=int(suf[u].size())-1; i>=0; i--){
    if(i==int(adj[u].size())-1)
      suf[u][i]=pre[u][i];
    else
      suf[u][i]=pre[u][i]*suf[u][i+1];
  }
  for(int i=0; i<adj[u].size(); i++)
    if(i)
      pre[u][i]*=pre[u][i-1];
  if(suf[u].size())
    f[u]*=suf[u][0];
}
double f2[N];
void dfs2(int u){
  for(int i=0; i<adj[u].size(); i++){
    int &v=adj[u][i].first;
    double l=i?pre[u][i-1]:1,r=i+1==adj[u].size()?1:suf[u][i+1];
    double ft=l*r*f2[u]*(1-p[u]);
    f2[v]=ft+(1-ft)*(1-adj[u][i].second);
    dfs2(v);
  }
}

int n;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,1,n-1){
    int u,v;
    double p;
    scanf("%d%d%lf",&u,&v,&p);
    p/=100.0;
    adj[u].push_back(MP(v,p));
    adj[v].push_back(MP(u,p));
  }
  REP(i,1,n){
    scanf("%lf",&p[i]);
    p[i]/=100.0;
    f[i]=1.0-p[i];
  }
  if(n<=1){
    printf("%f\n",p[1]);
    return 0;
  }
  dfs(1,0);
  f2[1]=1.0;
  dfs2(1);
  double ans=0;
  REP(i,1,n)ans+=1-f[i]*f2[i];
  printf("%f\n",ans);
  return 0;
}
