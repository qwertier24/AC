#include<stdio.h>
#include<algorithm>
#include<string.h>
#define EMPTY 1
#define FULL 0
#define MIXED 2
#define N 500000
#define For(i,n) for(int i=1; i<=n; i++)
#define CLR(t) memset(t,0,sizeof(t))
#define PROB "seating"

using namespace std;

struct SegementTree{
  int suf[N<<2],pre[N<<2],sub[N<<2],flag[N<<2],L,R,cur,n;
  void pushdown(int o,int l,int r){
    int lc=o<<1,rc=o<<1|1,m=(l+r)>>1;
    if(flag[o]==EMPTY){
      flag[lc]=flag[rc]=EMPTY;
      pre[lc]=suf[lc]=sub[lc]=m-l+1;
      pre[rc]=suf[rc]=sub[rc]=r-m;
    }else if(flag[o]==FULL){
      flag[lc]=flag[rc]=FULL;
      pre[lc]=suf[lc]=sub[lc]=0;
      pre[rc]=suf[rc]=sub[rc]=0;
    }
  }
  void maintain(int o,int l,int r){
    int lc=o<<1,rc=o<<1|1,m=(l+r)>>1;
    if(flag[lc]==EMPTY&&flag[rc]==EMPTY){
      sub[o]=pre[o]=suf[o]=r-l+1;
      flag[o]=EMPTY;
    }else if(flag[lc]==FULL&&flag[rc]==FULL){
      sub[o]=pre[o]=suf[o]=0;
      flag[o]==FULL;
    }else{
      flag[o]=MIXED;
      sub[o]=max(max(sub[lc],sub[rc]),suf[lc]+pre[rc]);
      pre[o]=pre[lc]+(pre[lc]==m-l+1?pre[rc]:0);
      suf[o]=suf[rc]+(suf[rc]==r-m?suf[lc]:0);
    }
  }
  void query(int o,int l,int r,int len){
    //printf("%d %d %d %d\n",o,l,r,len);
    if(r-l+1==len){
      L=l,R=r;
      return;
    }
    pushdown(o,l,r);
    int lc=o<<1,rc=o<<1|1,m=(l+r)>>1;
    if(sub[lc]>=len)query(lc,l,m,len);
    else if(suf[lc]+pre[rc]>=len){
      L=m-suf[lc]+1;
      R=m+len-suf[lc];
    }else query(rc,m+1,r,len);
  }
  void update(int o,int l,int r){
    if(L<=l&&r<=R){
      flag[o]=cur;
      if(cur==EMPTY){
	sub[o]=pre[o]=suf[o]=r-l+1;
      }else{
	sub[o]=pre[o]=suf[o]=0;
      }
      return;
    }
    pushdown(o,l,r);
    int m=(l+r)>>1,lc=o<<1,rc=o<<1|1;
    if(L<=m)update(lc,l,m);
    if(R>m)update(rc,m+1,r);
    maintain(o,l,r);
  }
  void Erase(int l,int r){
    L=l,R=r,cur=EMPTY;
    update(1,1,n);
  }
  bool Occupy(int size){
    if(sub[1]<size)return false;
    query(1,1,n,size);
    cur=FULL;
    update(1,1,n);
    return true;
  }
  void Init(int t){
    CLR(pre);
    CLR(sub);
    CLR(suf);
    n=t;
    flag[1]=EMPTY;
    sub[1]=pre[1]=suf[1]=n;
  }
}tree;
  
int main(){
  freopen(PROB".in","r",stdin);
  freopen(PROB".out","w",stdout);
  int n,m;
  scanf("%d%d",&n,&m);
  tree.Init(n);
  int ans=0;
  For(i,m){
    char opt[10];
    scanf("%s",opt);
    if(opt[0]=='A'){
      int size;
      scanf("%d",&size);
      if(!tree.Occupy(size))ans++;
    }else{
      int l,r;
      scanf("%d%d",&l,&r);
      tree.Erase(l,r);
    }
  }
  printf("%d",ans);
  return 0;
}
