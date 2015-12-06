#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<math.h>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

typedef long long LL;
using namespace std;

#define N 100010
int n;
struct Str{
  char s[N];
  int cnt[N],*x,*y,sa[N];
  LL sum[N];
  inline bool check(int i,int j){
    if((i<n)^(j<n))return false;
    return (i>=n && j>=n)||(y[i]==y[j]);
  }
  void calc_sa(){
    int m=26;
    for(int i=0; i<n; i++)cnt[x[i]=s[i]-'a']++;
    for(int i=1; i<m; i++)cnt[i]+=cnt[i-1];
    for(int i=n-1; i>=0; i--)sa[--cnt[x[i]]]=i;
    for(int k=1; k<n; k<<=1){
      int p=0;
      for(int i=n-k; i<n; i++)y[p++]=i;
      for(int i=0; i<n; i++)if(sa[i]>=k)y[p++]=sa[i]-k;
      
      for(int i=0; i<m; i++)cnt[i]=0;
      for(int i=0; i<n; i++)cnt[x[i]]++;
      for(int i=0; i<m; i++)cnt[i]+=cnt[i-1];
      for(int i=n-1; i>=0; i--)sa[--cnt[x[y[i]]]]=y[i];

      swap(x,y);
      p=1;
      x[sa[0]]=0;
      for(int i=1; i<n; i++)
        x[sa[i]]=check(sa[i-1],sa[i])&&check(sa[i-1]+k,sa[i]+k)?p-1:p++;
      m=p;
      if(m>=n)break;
    }
  }
  int hi[N];
  void calc_hi(){
    int j,k=0;
    REP(i,0,n-1){
      if(x[i]==0){
        hi[x[i]]=k=0;
        continue;
      }
      if(k)k--;
      j=sa[x[i]-1];
      while(s[i+k]==s[j+k])k++;
      hi[x[i]]=k;
    }
  }
  int minv[N][17];
  void init(){
    calc_sa();
    calc_hi();
    sum[0]=n-sa[0];
    REP(i,1,n-1)sum[i]=sum[i-1]+n-sa[i]-hi[i];
    //REP(i,0,n-1)printf("%lld %s %d\n",sum[i],s+sa[i],n-sa[i]);
    REP(i,0,n-1)minv[i][0]=hi[i];
    REP(i,1,16)
      for(int j=0; j+(1<<i)<=n; j++)
        minv[j][i]=min(minv[j][i-1],minv[j+(1<<i-1)][i-1]);
  }
  Str(){
    x=new int[N];
    y=new int[N];
  }
  void find(LL i,int &p,int &l){
    int lo=0,hi=n-1;
    while(lo<hi){
      int mi=(lo+hi)>>1;
      if(sum[mi]>=i)hi=mi;
      else lo=mi+1;
    }
    p=lo;
    l=n-sa[p]-(sum[p]-i);
  }
  int lcp(int i,int j){
    if(i==j)return 1<<20;
    if(i>j)swap(i,j);
    i++;
    int L=log2(j-i+1);
    return min(minv[i][L],minv[j-(1<<L)+1][L]);
  }
}a,b;

int Q;
#define sqr(x) ((x)*(LL)(x))
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&Q);
  scanf("%s",a.s);
  REP(i,0,n-1)b.s[i]=a.s[n-i-1];
  a.init();b.init();
  while(Q--){
    LL i,j;
    scanf("%lld%lld",&i,&j);
    if(i>a.sum[n-1] || j>a.sum[n-1]){
      puts("-1");
      continue;
    }
    int l1,p1,l2,p2;
    a.find(i,p1,l1);
    a.find(j,p2,l2);
    LL ans=sqr(min(a.lcp(p1,p2),min(l1,l2)));

    p1=n-(a.sa[p1]+l1);
    p2=n-(a.sa[p2]+l2);
    p1=b.x[p1];
    p2=b.x[p2];
    ans+=sqr(min(b.lcp(p1,p2),min(l1,l2)));
    printf("%lld\n",ans);
  }
  return 0;
}
