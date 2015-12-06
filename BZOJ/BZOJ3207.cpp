#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

typedef long long LL;
using namespace std;
#define SZ 5000000
#define mid ((l+r)>>1)

int sumv[SZ],lc[SZ],rc[SZ],sz;
void insert(int &o,int &p,int l,int r,int &x){
  o=++sz;
  sumv[o]=sumv[p]+1;
  if(l==r)return;
  if(x<=mid){
    rc[o]=rc[p];
    insert(lc[o],lc[p],l,mid,x);
  }else{
    lc[o]=lc[p];
    insert(rc[o],rc[p],mid+1,r,x);
  }
}
int query(int &p,int &q,int l,int r,int x){
  if(l==r)return sumv[p]-sumv[q];
  if(x<=mid)return query(lc[p],lc[q],l,mid,x);
  else return query(rc[p],rc[q],mid+1,r,x);
}

#define N 100010

int k;
vector<int> v[N],vt[N];
inline bool cmp(const vector<int> &a,const vector<int> &b){
  for(int i=0; i<min(a.size(),b.size()); i++){
    if(a[i]!=b[i])
      return a[i]<b[i];
  }
  return a.size()<b.size();
}
inline bool check(const vector<int> &a,const vector<int> &b){
  if(a.size()!=b.size())return false;
  REP(i,0,k-1)
    if(a[i]!=b[i])
      return false;
  return true;
}

int n,a[N],m,id[N],q,rt[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d%d",&n,&q,&k);
  REP(i,1,n)
    scanf("%d",&a[i]);
  REP(i,1,n){
    REP(j,i,min(n,i+k-1))
      v[i].push_back(a[j]);
    vt[i]=v[i];
  }
  sort(v+1,v+n+1,cmp);
  m=unique(v+1,v+n+1,check)-v-1;
  REP(i,1,n){
    int rank=lower_bound(v+1,v+m+1,vt[i],cmp)-v;
    insert(rt[i],rt[i-1],1,m,rank);
  }
  vector<int> t(k);
  while(q--){
    int l,r;
    scanf("%d%d",&l,&r);
    REP(j,0,k-1)
      scanf("%d",&t[j]);
    int rank=lower_bound(v+1,v+m+1,t,cmp)-v;
    if(!check(v[rank],t)){
      puts("Yes");
      continue;
    }
    puts(query(rt[r-k+1],rt[l-1],1,m,rank)?"No":"Yes");
  }
  return 0;
}
