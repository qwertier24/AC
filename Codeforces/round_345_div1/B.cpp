#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 1000010

char p[N];
int n, a, b, T;

int calc(){
  int s = a * (n - 1) * 2 + n - 1;
  FOR(i,n-1){
    if(p[i] == 'w')
      s += b;
  }
  int l = 1;
  int s2 = 0;
  int ret = 0;
  REP(i,n){
    if(i){
      s2 += a + 1;
      if(p[i] == 'w')
        s2 += b;
    }else
      s2 += (p[i] == 'w') * b + 1;
    if(s2 > T)
      return ret;
    while(s + s2 > T && l < n){
      s -= a * 2 + 1;
      if(p[l] == 'w')
        s -= b;
      l++;
    }
    if(s + s2 > T && l >= n)
      break;
    //printf("%d %d %d %d\n",i,l,s,s2);
    ret = max(ret, i + 1 + n -l);
  }
  return min(n,ret);
}
int vis[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d%d%d",&n,&a,&b,&T);
  scanf("%s", p);
  int ans = calc();
  reverse(p+1,p+n);
  ans = max(ans, calc());
  printf("%d\n", ans);
  return 0;
}
