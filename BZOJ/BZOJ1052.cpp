#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 20010
#define INF 1ll<<32

using namespace std;
typedef long long LL;

int x[N],y[N],n,mark[N];
int dfs(LL L,int depth){
  LL yc[2]={INF,-INF},xc[2]={INF,-INF};
  For(i,n)if(!mark[i]){
    yc[0]=min(yc[0],(LL)y[i]);
    yc[1]=max(yc[1],y[i]-L);
    xc[0]=min(xc[0],(LL)x[i]);
    xc[1]=max(xc[1],x[i]-L);
  }
  if(depth>2){
    if(xc[1]<=xc[0] && yc[1]<=yc[0])return 1;
    else return 0;
  }
  Rep(i,2)Rep(j,2){
    int flag=0;
    For(k,n)if(!mark[k] && (x[k]>=xc[i]&&x[k]<=xc[i]+L&&y[k]>=yc[j]&&y[k]<=yc[j]+L))mark[k]=depth;
    if(dfs(L,depth+1))return 1;
    For(k,n)if(mark[k]==depth)mark[k]=0;
  }
  return 0;
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("cover9.in","r",stdin);
#endif
  char s[20];
  FILE* fans=fopen("cover9.out","r");
  fscanf(fans,"%s",s);
  printf("%s\n",s);
  scanf("%d",&n);
  For(i,n){
    scanf("%d%d",&x[i],&y[i]);
  }
  LL l=0,r=1ll<<31;
  while(l<r){
    LL mid=(l+r)>>1;
    memset(mark,0,sizeof(mark));
    if(dfs(mid,1))r=mid;
    else l=mid+1;
  }
  printf("%lld",l);
  return 0;
}
