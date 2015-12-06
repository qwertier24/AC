#include<stdio.h>
#include<algorithm>
#include<string.h>
#define read(a) scanf("%d",&a);
#define REP(i,n) for(int i=0; i<n; i++)
#define N 100
#define M 1000
#define MOD 31011

using namespace std;

int n,m;
struct Edge{
  int u,v,d;
  bool operator<(const Edge& rhs)const{
    return d<rhs.d;
  }
}e[M];

int pa[N],pa2[N];
inline void Init(){
  REP(i,n)pa[i]=i;
}
int findset(int u){
  if(pa[u]!=u)pa[u]=findset(pa[u]);
  return pa[u];
}
int findset2(int u){
  if(pa2[u]!=u)return findset2(pa2[u]);
  else return u;
}
inline void Union(int u,int v){
  pa[findset(u)]=findset(v);
}

int sum,start,end,temp,ans=1;
void dfs(int pos,int rem){
  if(rem==0){temp++;return;}
  if(pos>end)return;
  int pu=findset2(e[pos].u),pv=findset2(e[pos].v);
  if(pu!=pv){
    pa2[pu]=pv;
    dfs(pos+1,rem-1);
    pa2[pu]=pu;
  }
  dfs(pos+1,rem);
}
void count(){
  temp=0;
  dfs(start,sum);
  ans=(ans*temp)%MOD;
}

int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  read(n);
  read(m);
  Init();
  REP(i,m)
    scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].d);
  sort(e,e+m);
  int cnt=0;
  REP(i,m){
    if(i==0||e[i].d!=e[i-1].d){
      if(i!=0){
	end=i-1;
	//printf("%d %d %d %d\n",i,e[i].d,start,end);
	count();
      }
      memcpy(pa2,pa,sizeof(pa));
      sum=0;
      start=i;
    }
    if(findset(e[i].u)!=findset(e[i].v)){
      sum++;
      cnt++;
      Union(e[i].u,e[i].v);
    }
  }
  end=m-1;
  count();
  if(cnt==n-1)printf("%d",ans);
  else printf("0");
  return 0;
}
