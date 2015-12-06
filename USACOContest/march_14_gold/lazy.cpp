#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100010
#define ADD 0
#define DEL 1
#define MP make_pair

using namespace std;

namespace segTree{
#define mid ((l+r)>>1)
#define lc (o<<1)
#define rc (o<<1|1)
  int maxv[N<<3],addv[N<<3],sz,L,R,addt;
  void init(int k){
    sz=k;
    memset(maxv,0,sizeof(maxv));
    memset(addv,0,sizeof(addv));
  }
  void update(int o,int l,int r){
    if(L<=l&&r<=R){
      addv[o]+=addt;
      maxv[o]+=addt;
      return;
    }
    if(L<=mid)update(lc,l,mid);
    if(R>mid)update(rc,mid+1,r);
    maxv[o]=max(maxv[lc],maxv[rc])+addv[o];
  }
  void add(int l,int r,int d){
    if(l>r)return;
    addt=d;
    L=l,R=r;
    update(1,1,sz);
  }
  int getmax(){
    return maxv[1];
  }
}

int x[N],y[N],a[N];

int n,k;
int yc[N<<1];
pair<int,int> events[N<<1];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#else
  freopen("lazy.in","r",stdin);
  freopen("lazy.out","w",stdout);
#endif
  scanf("%d%d",&n,&k);
  k<<=1;
  For(i,n){
    int xt,yt;
    scanf("%d%d%d",&a[i],&xt,&yt);
    x[i]=xt+yt;
    y[i]=-xt+yt;

    yc[i]=y[i];
    yc[i+n]=y[i]+k;
    
    events[i]=MP(x[i],i<<1);
    events[n+i]=MP(x[i]+k+1,i<<1|1);
  }
  int en=n*2,m=n*2;
  sort(events+1,events+en+1);
  
  sort(yc+1,yc+m+1);
  m=unique(yc+1,yc+m+1)-yc-1;

  segTree::init(m);
  int ans=0;
  For(i,en){
    //printf("%d %d %d\n",events[i].first,events[i].second>>1,events[i].second&1);
    int curi=events[i].second>>1,curo=events[i].second&1;
    int p1=lower_bound(yc+1,yc+m+1,y[curi])-yc,
      p2=lower_bound(yc+1,yc+m+1,y[curi]+k)-yc;
    if(curo==ADD)
      segTree::add(p1,p2,a[curi]);
    else
      segTree::add(p1,p2,-a[curi]);
    if(i!=en && events[i].first==events[i+1].first)continue;
    ans=max(ans,segTree::getmax());
  }
  printf("%d",ans);
  return 0;
}
