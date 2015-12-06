#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 10010
#define lowbit(x) ((x)&(-(x)))
#define INF (1<<30)

typedef long long LL;
using namespace std;

int n,m;

int val1[110],val2[110];
int sum(int *cur,int p){
  int ret=0;
  while(p>0){
    ret+=cur[p];
    p-=lowbit(p);
  }
  return ret;
}
void add(int *cur,int p,int v){
  while(p<=m){
    cur[p]+=v;
    p+=lowbit(p);
  }
}

int a[N],k,d[110];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  For(i,n){
    scanf("%d",&a[i]);
    if(a[i]!=-1)
      add(val2,a[i],1);
  }
  int ans=0;
  For(i,n){
    if(a[i]==-1){
      k++;
      int mind=INF;
      For(j,m){
        mind=min(mind,d[j]);
        d[j]=mind+i-k-sum(val1,j)+sum(val2,j-1);
      }
    }else{
      add(val1,a[i],1);
      ans+=i-k-sum(val1,a[i]);
      add(val2,a[i],-1);
    }
  }
  int mind=INF;
  For(i,m)mind=min(mind,d[i]);
  printf("%d\n",ans+mind);
  return 0;
}
