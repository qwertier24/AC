#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<iostream>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

typedef long long LL;
using namespace std;

namespace nf{
#define N 1410
#define M 3000000
#define INF (1ll<<60)

  int le[N],ev[M],pe[M],ecnt;
  LL data[M];
  void addEdge(int u,int v,LL cap){
    pe[ecnt]=le[u];
    le[u]=ecnt;
    ev[ecnt]=v;
    data[ecnt]=cap;
    ecnt++;
		
    pe[ecnt]=le[v];
    le[v]=ecnt;
    ev[ecnt]=u;
    data[ecnt]=0;
    ecnt++;
  }
  
  int S,T;
  void init(int s,int t){
    S=s,T=t;
    memset(le,-1,sizeof(le));
    ecnt=0;
  }
  
  int st,ed;

  int q[N],fr,rr,dist[N];
  int bfs(){
    fr=0,rr=-1;
    q[++rr]=st;
    memset(dist,-1,sizeof(dist));
    dist[st]=0;
    while(fr<=rr){
      int &u=q[fr++];
      for(int i=le[u]; i!=-1; i=pe[i])
        if(data[i]&&dist[ev[i]]==-1){
          int &v=ev[i];
          dist[v]=dist[u]+1;
          q[++rr]=v;
          if(v==ed)return 1;
        }
    }
    return 0;
  }
  
  int dfscnt;
  int cur[N],mark[N];
  LL dfs(int u,LL a){
    LL ret=0,f;
    if(u==ed || a==0)return a;
    if(mark[u]!=dfscnt){mark[u]=dfscnt; cur[u]=le[u];}
    for(int &i=cur[u]; i!=-1; i=pe[i])if(data[i]&&dist[ev[i]]==dist[u]+1){
        int &v=ev[i];
        f=dfs(v,min(a,data[i]));
        ret+=f;
        a-=f;
        data[i]-=f;
        data[i^1]+=f;
        if(a==0)break;
      }
    return ret;
  }
  
  int vis[N];
  int find(int u,int dest){
    if(u==dest)return 1;
    if(vis[u]==dfscnt)return 0;
    vis[u]=dfscnt;
    for(int i=le[u]; i!=-1; i=pe[i])
      if(data[i] && find(ev[i],dest))
        return 1;
    return 0;
  }
  int on_cut(int u,int v){
    if(data[le[u]])return 0;
    dfscnt++;
    return !find(u,v);
  }
  void erase(int u,int v){
    LL ft=data[le[v]],f=ft;
    le[u]=pe[le[u]],le[v]=pe[le[v]];
    
    st=T,ed=v;
    f=ft;
    while(f&&bfs()){dfscnt++;f-=dfs(st,f);}

    st=u,ed=S;
    f=ft;
    while(f&&bfs()){dfscnt++;f-=dfs(st,f);}
  }
  
  LL maxFlow(){
    st=S,ed=T;
    LL ret=0;
    memset(mark,0,sizeof(mark));
    while(bfs()){
      dfscnt++;
      ret+=dfs(S,INF);
    }
    return ret;
  }
}
using namespace nf;

int n,a[N],b[N],c[N],f[N],idx[N];
vector<int> ans,v;
bool by_c(const int &a,const int& b){
  return c[a]<c[b];
}
int main(){
  freopen("lis.in","r",stdin);
  freopen("lis.out","w",stdout);
  int Q;
  scanf("%d",&Q);
  while(Q--){
    scanf("%d",&n);
    Rep(i,n)scanf("%d",&a[i]);
    Rep(i,n)scanf("%d",&b[i]);
    Rep(i,n)scanf("%d",&c[i]);
    int maxf=0;
    Rep(i,n){
      f[i]=1;
      Rep(j,i)if(a[j]<a[i])
        f[i]=max(f[i],f[j]+1);
      maxf=max(maxf,f[i]);
      idx[i]=i;
    }
    init(n<<1,n<<1|1);
    Rep(i,n){
      if(f[i]==maxf)addEdge(i+n,T,INF);
      if(f[i]==1)addEdge(S,i,INF);
      
      for(int j=i+1; j<n; j++)if(a[j]>a[i]&&f[j]==f[i]+1)
        addEdge(i+n,j,INF);
      addEdge(i,i+n,b[i]);
    }

    cout<<maxFlow();
    sort(idx,idx+n,by_c);
    ans.clear();
    Rep(j,n){
      int &i=idx[j];
      if(on_cut(i,i+n)){
        ans.push_back(i);
        erase(i,i+n);
      }
    }
    
    sort(ans.begin(),ans.end());
    printf(" %d\n",(int)ans.size());
    Rep(i,(int)ans.size())
      printf("%s%d",i?" ":"",ans[i]+1);
    puts("");
  }
  return 0;
}

