#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100010
#define mid ((l+r)>>1)
#define lc (o<<1)
#define rc (o<<1|1)

typedef long long LL;
using namespace std;

int n,m;
struct SegTree{
  int P,setv;
  LL lsum[N*4],rsum[N*4],sumv[N*4];
  void maintain(int o,int l,int r){
    rsum[o]=rsum[rc]==r-mid?rsum[rc]+rsum[lc]:rsum[rc];
    lsum[o]=lsum[lc]==mid-l+1?lsum[lc]+lsum[rc]:lsum[lc];
    sumv[o]=sumv[lc]+sumv[rc]+rsum[lc]*lsum[rc];
  }
  void update(int o,int l,int r){
    if(l==r){
      lsum[o]=rsum[o]=sumv[o]=setv;
      return;
    }
    if(P<=mid)update(lc,l,mid);
    else update(rc,mid+1,r);
    maintain(o,l,r);
  }
  void set(int p,int v){
    P=p,setv=v;
    update(1,1,n);
  }
  LL getsum(){
    return sumv[1];
  }
}tree[17];
int a[N],dig[N][20];
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  For(i,n){
    scanf("%d",&a[i]);
    int j=0;
    while(a[i]){
      dig[i][j]=a[i]&1;
      if(dig[i][j])tree[j].set(i,1);
      j++;
      a[i]>>=1;
    }
  }
  while(m--){
    int p,v;
    scanf("%d%d",&p,&v);
    for(int i=0; i<17; i++){
      if(dig[p][i])tree[i].set(p,0);
      dig[p][i]=0;
    }
    int i=0;
    while(v){
      dig[p][i]=v&1;
      if(dig[p][i])tree[i].set(p,1);
      i++;
      v>>=1;
    }
    LL ans=0;
    Rep(i,17){
      ans+=(1ll<<i)*tree[i].getsum();
    }
    printf("%I64d\n",ans);
  }
  return 0;
}
