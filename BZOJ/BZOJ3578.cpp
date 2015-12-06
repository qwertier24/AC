#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

typedef unsigned long long ULL;
using namespace std;
#define N 100010

ULL ran(){
  static ULL ranx=123456789012345678ull;
  ranx+=(ranx<<2)+1;
  return ranx;
}
ULL h[N];

int n,m,q,x,y,pos[N];

ULL hval[N<<2];
int cnt1[N<<2],cnt2[N<<2],used[N<<2];
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
void pushdown(int o){
  if(used[o]){
    used[lc]=used[rc]=1;
    cnt2[lc]=cnt2[rc]=0;
    used[o]=0;
  }
}
void maintain(int o){
  cnt1[o]=cnt1[lc]+cnt1[rc];
  if(!used[o])cnt2[o]=cnt2[lc]+cnt2[rc];
  else cnt2[o]=0;
}
void mark(int &L,int &R,int v,int o=1,int l=1,int r=m){
  if(L<=l&&r<=R){
    used[o]=v;
    if(v)cnt2[o]=0;
    else cnt2[o]=cnt1[o];
    return;
  }
  pushdown(o);
  if(L<=mid)mark(L,R,v,lc,l,mid);
  if(R>mid)mark(L,R,v,rc,mid+1,r);
  maintain(o);
}
int query(int &L,int &R,int o=1,int l=1,int r=m){
  if(L<=l && r<=R)return cnt2[o];
  pushdown(o);
  if(R<=mid)return query(L,R,lc,l,mid);
  if(L>mid)return query(L,R,rc,mid+1,r);
  return query(L,R,lc,l,mid)+query(L,R,rc,mid+1,r);
}
void add(int &p,int v,int o=1,int l=1,int r=m){
  if(l==r){
    cnt1[o]+=v;
    cnt2[o]=cnt1[o]*(!used[o]);
    return;
  }
  pushdown(o);
  if(p<=mid)add(p,v,lc,l,mid);
  else add(p,v,rc,mid+1,r);
  maintain(o);
}

ULL cur[N];
char op[10];
set<ULL> st;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d%d",&n,&m,&q);
  REP(i,1,n){
    h[i]=ran();
    cur[1]^=h[i];
    pos[i]=1;
  }
  add(pos[1],n);

  while(q--){
    scanf("%s%d%d",op,&x,&y);
    if(op[0]=='C'){
      if(!query(pos[x],pos[x]))st.insert(cur[pos[x]]);
      cur[pos[x]]^=h[x];
      if(!st.count(cur[pos[x]]))mark(pos[x],pos[x],0);
      else mark(pos[x],pos[x],1);
      add(pos[x],-1);

      pos[x]=y;
      if(!query(pos[x],pos[x]))st.insert(cur[pos[x]]);
      cur[y]^=h[x];
      if(!st.count(cur[y]))mark(y,y,0);
      else mark(y,y,1);
      add(y,1);
    }else{
      printf("%d\n",query(x,y));
      mark(x,y,1);
    }
  }
  return 0;
}
