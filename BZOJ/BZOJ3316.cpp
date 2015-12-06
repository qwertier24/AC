#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;
#define N 200010
#define gcd __gcd

int a[N],n,L,R,ansl,ansr;
double sum[N];
int q[N],fr,rr;
bool check(double quot){
  FOR(i,n)
    sum[i]=sum[i-1]+a[i]-quot;
  fr=0,rr=-1;
  int pt=1;
  for(int i=1; i<=n; i+=2){
    while(fr<=rr && i-q[fr]>R)fr++;
    if(pt<=i-L){
      while(fr<=rr && sum[q[rr]]>=sum[pt])rr--;
      q[++rr]=pt;
      pt+=2;
    }
    if(fr<=rr){
      if(sum[i]-sum[q[fr]]>=0){
        ansl=q[fr]+1;
        ansr=i;
        return true;
      }
    }
  }
  fr=0,rr=-1;
  pt=0;
  for(int i=2; i<=n; i+=2){
    while(fr<=rr && i-q[fr]>R)fr++;
    if(pt<=i-L){
      while(fr<=rr && sum[q[rr]]>=sum[pt])rr--;
      q[++rr]=pt;
      pt+=2;
    }
    if(fr<=rr){
      if(sum[i]-sum[q[fr]]>=0){
        ansl=q[fr]+1;
        ansr=i;
        return true;
      }
    }
  }
  return false;
}

int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d%d",&n,&L,&R);
  FOR(i,n)scanf("%d",&a[i]);
  FOR(i,n)a[i+n]=a[i];
  n<<=1;
  double lo=0,hi=1e9;
  while(hi-lo>1e-6){
    double mi=(lo+hi)/2.0;
    if(check(mi))lo=mi;
    else hi=mi;
  }
  check(lo);
  long long tot=0,cnt=0;
  for(int i=ansl; i<=ansr; i++)
    tot+=a[i];
  cnt=ansr-ansl+1;
  printf("%lld/%lld",tot/gcd(tot,cnt),cnt/gcd(tot,cnt));
  return 0;
}
