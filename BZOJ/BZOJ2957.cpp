#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100010
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)

typedef long long LL;
using namespace std;

int ansv[N<<2];
double maxv[N<<2];
int calc(int o,int l,int r,double v){
  if(l==r)return maxv[o]>v;
  if(maxv[lc]>=v)return ansv[o]-ansv[lc]+calc(lc,l,mid,v);
  return calc(rc,mid+1,r,v);
}
void modify(int o,int l,int r,int x,double v){
  if(l==r){maxv[o]=v,ansv[o]=1;return;}
  if(x<=mid)modify(lc,l,mid,x,v);
  else modify(rc,mid+1,r,x,v);
  maxv[o]=max(maxv[lc],maxv[rc]);
  ansv[o]=ansv[lc]+calc(rc,mid+1,r,maxv[lc]);
  //printf("%d %d %d\n",l,r,maxv[o]);
}

int n,m,x,y;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  while(m--){
    scanf("%d%d",&x,&y);
    modify(1,1,n,x,y/double(x));
    printf("%d\n",ansv[1]);
  } 
  return 0;
}
