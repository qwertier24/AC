#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 1000010

using namespace std;

int l[N],r[N];
int val[N],n;
inline int lowbit(int x){
  return x&(-x);
}
void add(int p,int v){
  if(p<=0)return;
  while(p<=n){
    val[p]+=v;
    p+=lowbit(p);
  }
}
int sum(int p){
  int ret=0;
  while(p>0){
    ret+=val[p];
    p-=lowbit(p);
  }
  return ret;
}
bool cmp(const int& a,const int& b){
  return l[a]<l[b];
}

int nt[N],mark[N],idx[N],ans[N],m,q,c[N];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d%d%d",&n,&m,&q);
  For(i,n){
    scanf("%d",&c[i]);
  }
  for(int i=n; i; i--){
    nt[i]=mark[c[i]];
    mark[c[i]]=i;
  }

  For(i,q){
    scanf("%d%d",&l[i],&r[i]);
    idx[i]=i;
  }
  For(i,m)add(nt[mark[i]],1);
  int cur=1;
  sort(idx+1,idx+q+1,cmp);
  For(i,q){
    while(cur<l[idx[i]]){
      add(nt[cur],-1);
      //printf("%d %d\n",cur,nt[cur]);
      add(nt[nt[cur]],1);
      cur++;
    }
    ans[idx[i]]=sum(r[idx[i]]);
  }
  For(i,q)printf("%d\n",ans[i]);
  return 0;
}
