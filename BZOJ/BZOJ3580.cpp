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
#define N 1002010

void readint(int &x){
  x=0;
  char c=getchar();
  while(c<'0' || c>'9')c=getchar();
  while('0'<=c && c<='9'){
    x=x*10+c-'0';
    c=getchar();
  }
}

int n;

int val[N];
void add(int p,int v){
  while(p<=n){
    val[p]+=v;
    p+=p&(-p);
  }
}
int sum(int p){
  int ret=0;
  while(p){
    ret+=val[p];
    p-=p&(-p);
  }
  return ret;
}
int find(int p){
  int ret=0;
  for(int po=1<<20; po; po>>=1){
    ret+=po;
    if(ret>=n || val[ret]>=p)ret-=po;
    else p-=val[ret];
  }
  return ret+1;
}

int a[N],pre[N],id[N],ans[N];
inline bool cmp(const int &i,const int& j){
  return a[i]<a[j];
}
LL m,tot;
int del[N],presum[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%lld",&n,&m);
  REP(i,1,n){
    readint(a[i]);
    pre[i]=i-1-sum(a[i]);
    add(a[i],1);
    tot+=pre[i];
  }
  if(tot<m){
    puts("Impossible!");
    return 0;
  }
  tot=0;
  REP(i,1,n){
    if(pre[i]){
      del[pre[i]]++;
      tot++;
    }
  }
  int cnt;
  for(cnt=0; m; ){
    if(tot>=m){
      REP(i,1,n)presum[i]=presum[i-1]+(pre[i]-cnt>0);
      int lo=1,hi=n;
      while(lo<hi){
        int mi=(lo+hi)>>1;
        if(presum[mi]>=m)hi=mi;
        else lo=mi+1;
      }
      REP(i,1,lo)pre[i]--;
      m=0;
    }else{
      cnt++;
      m-=tot;
      tot-=del[cnt];
    }
  }
  REP(i,1,n){
    id[i]=i;
    pre[i]=max(0,pre[i]-cnt);
  }
  sort(id+1,id+n+1,cmp);
  memset(val+1,0,sizeof(int)*n);
  REP(i,1,n)add(i,1);
  REP(i,1,n){
    int p=find(pre[id[i]]+1);
    ans[p]=a[id[i]];
    add(p,-1);
  }
  REP(i,1,n)printf("%d%s",ans[i],i==n?"":" ");
  return 0;
}
