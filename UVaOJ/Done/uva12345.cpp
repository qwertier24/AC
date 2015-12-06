#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<math.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 50010
#define INF (1<<29)
#define MP make_pair

using namespace std;

int n,a[N];

set<pair<int,int> > st;
set<pair<int,int> >::iterator it;
int sz,bkn,blk[300][300],lpos[N];
void init(){
  memset(blk,0x3f,sizeof(blk));
  memset(lpos,0xaf,sizeof(lpos));
  sz=sqrt(n);
  bkn=(n-1)/sz+1;

  Rep(i,n)st.insert(MP(a[i],i));
  Rep(i,n){
    it=st.lower_bound(MP(a[i],i));
    if(it!=st.begin()){
      --it;
      if(it->first==a[i])
	lpos[i]=it->second;
    }
    blk[i/sz][i%sz]=lpos[i];
  }

  Rep(i,bkn)
    sort(blk[i],blk[i]+sz);
}
void erase(int bki,int lp){
  int k=lower_bound(blk[bki],blk[bki]+sz,lp)-blk[bki];
  for(int i=k; i<sz-1; i++)
    blk[bki][i]=blk[bki][i+1];
}
void insert(int bki,int lp){
  for(int i=sz-1; i>=0; i--){
    if(i==0 || blk[bki][i-1]<=lp){
      blk[bki][i]=lp;
      break;
    }
    blk[bki][i]=blk[bki][i-1];
  }
}
void change(int p,int lp){
  erase(p/sz,lpos[p]);
  lpos[p]=lp;
  insert(p/sz,lpos[p]);
}
void modify(int p,int v){
  int rp;

  st.erase(MP(a[p],p));
  it=st.upper_bound(MP(a[p],p));
  if(it!=st.end() && it->first==a[p]){
    rp=it->second;
    change(rp,lpos[p]);
  }

  a[p]=v;
  st.insert(MP(a[p],p));
  it=st.lower_bound(MP(a[p],p));
  if(it!=st.begin() && --it!=st.end() && it->first==a[p])
    change(p,it->second);
  else
    change(p,-INF);
  
  it=st.upper_bound(MP(a[p],p));
  if(it!=st.end() && it->first==a[p])
    change(it->second,p);
}
int query(int l,int r){
  if(l>=r)return 0;
  int ret=0;
  int lb=l/sz,rb=r/sz;
  for(int i=lb+1; i<rb; i++){
    ret+=lower_bound(blk[i],blk[i]+sz,l)-blk[i];
  }
  for(int i=l; i/sz==lb&&i<=r; i++)
    ret+=lpos[i]<l;
  if(rb!=lb){
    for(int i=r; i>=0 && i/sz==rb; i--)
      ret+=lpos[i]<l;
  }
  return ret;
}

char op[10];
int m,x,y;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  Rep(i,n)scanf("%d",&a[i]);
  init();
  int cnt=0;
  while(m--){
    scanf("%s%d%d",op,&x,&y);
    if(op[0]=='Q'){
      printf("%d\n",query(x,y-1));
    }else{
      modify(x,y);
    }
  }
  return 0;
}
