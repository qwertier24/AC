#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

int len[20]={0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8};
int len_x0[10]={0,0,6,6,5,5,5,7,6,6};
int calc(int n){
  if(n<20)
    return len[n];
  else if(n<100)
    return len_x0[n/10]+len[n%10];
  else
    return len[n/100]+7+(calc(n%100)?3+calc(n%100):0);
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int ans=0;
  printf("%d %d %d\n",len[342/100],len_x0[(342/10)%10],len[342%10]);
  FOR(i,999)
    ans+=calc(i);
  printf("%d\n",ans+11);
  return 0;
}
