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

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)

#define N 200010
#define K 10

int n,m,k;
char s[N];

int cnt[N<<2][K][K],setv[N<<2],cl[N<<2],cr[N<<2];
void Set(int o,int l,int r,int c){
  memset(cnt[o],0,sizeof(cnt[o]));
  cnt[o][c][c]=r-l;
  cl[o]=cr[o]=c;
  setv[o]=c;
}
void maintain(int o,int l,int r){
  if(setv[o]==-1){
    REP(i,k)REP(j,k)
      cnt[o][i][j]=cnt[lc][i][j]+cnt[rc][i][j];
    cnt[o][cr[lc]][cl[rc]]++;
    cl[o]=cl[lc];
    cr[o]=cr[rc];
  }
}
void pushdown(int o,int l,int r){
  if(setv[o]!=-1){
    Set(lc,l,mid,setv[o]);
    Set(rc,mid+1,r,setv[o]);
    setv[o]=-1;
  }
}
void build(int o,int l,int r){
  if(l==r){
    cl[o]=cr[o]=s[l]-'a';
    return;
  }
  build(lc,l,mid);
  build(rc,mid+1,r);
  maintain(o,l,r);
}
void modify(int L,int R,int c,int o=1,int l=1,int r=n){
  if(L<=l && r<=R){
    Set(o,l,r,c);
    return;
  }
  pushdown(o,l,r);
  if(L<=mid)
    modify(L,R,c,lc,l,mid);
  if(R>mid)
    modify(L,R,c,rc,mid+1,r);
  maintain(o,l,r);
}

int p[K];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  memset(setv,-1,sizeof(setv));
  scanf("%d%d%d",&n,&m,&k);
  scanf("%s",s+1);
  build(1,1,n);
  while(m--){
    int op,l,r;
    scanf("%d",&op);
    if(op==1){
      scanf("%d%d%s",&l,&r,s);
      modify(l,r,s[0]-'a');
    }else{
      scanf("%s",s);
      REP(i,k)
        p[s[i]-'a']=i;
      int ans=0;
      REP(i,k)REP(j,k)
        if(p[i]>=p[j])
          ans+=cnt[1][i][j];
      printf("%d\n",ans+1);
    }
  }
  return 0;
}
