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

#define N 300010

int le[N],ev[N<<1],pe[N<<1],ecnt;
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  ev[ecnt]=v;
  le[u]=ecnt;
}

int a[N];
char s[N];

const int m=26;

int sz[N],ch[N][m];

int ans,cnt;
int mergeto(int a,int b){
  sz[b]=1;
  REP(i,m){
    if(ch[a][i] && ch[b][i])
      mergeto(ch[a][i],ch[b][i]);
    else if(ch[a][i])
      ch[b][i]=ch[a][i];
    sz[b]+=sz[ch[b][i]];
  }
  return b;
}

void dfs(int u,int fa){
  sz[u]=1;
  for(int i=le[u]; i; i=pe[i]){
    int &v=ev[i];
    if(v==fa)continue;
    dfs(v,u);
    int c=s[v]-'a';
    if(!ch[u][c])
      ch[u][c]=v;
    else{
      if(sz[ch[u][c]]>=sz[v])
        mergeto(v,ch[u][c]);
      else{
        mergeto(ch[u][c],v);
        ch[u][s[v]-'a']=v;
      }
    }
  }
  REP(i,m)
    if(ch[u][i]){
      sz[u]+=sz[ch[u][i]];
      //printf("%d %c %d\n",u,i+'a',ch[u][i]);
    }
  //printf("%d %d\n",u,sz[u]);
  if(ans<sz[u]+a[u]){
    ans=sz[u]+a[u];
    cnt=1;
  }else if(ans==sz[u]+a[u])
    cnt++;
}

int n;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  FOR(i,n)
    scanf("%d",&a[i]);
  scanf("%s",s+1);
  FOR(i,n-1){
    int u,v;
    scanf("%d%d",&u,&v);
    addEdge(u,v);
    addEdge(v,u);
  }
  dfs(1,0);
  printf("%d\n%d\n",ans,cnt);
  return 0;
}
