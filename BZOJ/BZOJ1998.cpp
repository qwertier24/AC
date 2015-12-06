#include<stdio.h>
#include<algorithm>
#include<cstring>
#define gcd __gcd
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

typedef long long LL;
using namespace std;
#define N 100010

struct LST{
  LST *nxt;
  int cnt;
}lst1[N],lst2[N];

void zip(LST &a){
  if(a.nxt!=&a)zip(*a.nxt);
  a.nxt=a.nxt->nxt;
}
int n,c[N],pos[N],y[N],s,q,p,m,d,g,a[N];
void fill(int p){
  lst2[p].nxt=&lst2[(p+d)%n];
  if(--lst1[p%g].cnt)return;
  lst1[p%g].nxt=lst1[(p+1)%g].nxt;
}
int vis[N];
void solve(){
  scanf("%d%d%d%d%d%d",&n,&s,&q,&p,&m,&d);
  d%=n;
  g=gcd(n,d);
  REP(i,0,g-1){
    lst1[i].nxt=&lst1[i];
    lst1[i].cnt=n/g;
  }
  REP(i,0,n-1)lst2[i].nxt=&lst2[i];
  fill(pos[0]=s);
  REP(i,1,n-1){
    c[i]=(c[i-1]*(LL)q+p)%m;
    zip(lst1[c[i]%g]);
    y[i]=((lst1[c[i]%g].nxt-lst1-c[i]+g)%g+g)%g;
    zip(lst2[(y[i]+c[i])%n]);
    pos[i]=lst2[(y[i]+c[i])%n].nxt-lst2;
    fill(pos[i]);
  }
  memset(vis,0,sizeof(vis));
  int ans=0;
  REP(i,0,n-1)a[pos[i]]=i;
  REP(i,0,n-1){
    if(vis[i])continue;
    int j=i,cnt=0,flag=0;
    while(!vis[j]){
      if(j==s)flag=1;
      vis[j]=1;
      cnt++;
      j=pos[j];
    }
    if(cnt==1)continue;
    ans+=cnt+1-flag*2;
  }
  printf("%d\n",ans);
}
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  int T;
  scanf("%d",&T);
  while(T--){
    solve();
  }
  return 0;
}
