#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define INF (1ll<<60)

typedef long long LL;
using namespace std;

struct Node{
  int u,d;
  Node(int a,int b):u(a),d(b){}
  bool operator<(const Node& r)const{
    return d>r.d;
  }
};

int n,a[20],mark[400010];
LL lo,hi,dis[400010];
void DIJ(){
  priority_queue<Node> pq;
  int u,v;
  Rep(i,a[1])dis[i]=INF;
  dis[0]=0;
  pq.push(Node(0,0));
  while(!pq.empty()){
    Node e=pq.top();
    pq.pop();
    int u=e.u;
    if(mark[u])continue;
    mark[u]=1;
    For(i,n){
      int v=(u+a[i])%a[1];
      if(dis[u]+a[i]<dis[v]){
        dis[v]=dis[u]+a[i];
        pq.push(Node(v,dis[v]));
      }
    }
  }
}

LL ans;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%lld%lld",&n,&lo,&hi);
  For(i,n)scanf("%d",&a[i]);
  sort(a+1,a+n+1);
  int p=1;
  while(p<=n && a[p]==0)p++;
  swap(a[1],a[p]);
  if(a[1]==0){
    puts("0");
    return 0;
  }
  DIJ();
  Rep(i,a[1]){
    if(hi<dis[i])continue;
    ans+=(hi-max(dis[i],lo+(i-lo%a[1]+a[1])%a[1]))/a[1]+1;
    //printf("%d %lld %lld\n",i,dis[i],(hi-max(dis[i],lo/a[1]*a[1]+i))/a[1]+1);
  }
  printf("%lld\n",ans);
  return 0;
}
