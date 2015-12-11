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

int mark[28123+10];
vector<int> v;
int ans;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  for(int i=12; i<=28123; i++){
    int s=0;
    for(int j=2; j*j<=i; j++)
      if(i%j==0){
        s+=j;
        if(j*j!=i)
          s+=i/j;
      }
    if(s+1>i)
      v.push_back(i);
  }
  REP(i,v.size()){
    REP(j,i+1)
      if(v[i]+v[j]<=28123)
        mark[v[i]+v[j]]=1;
  }
  //printf("%d\n",mark[28123]);
  FOR(i,28123) 
    if(!mark[i]){
      //printf("%d\n",i);
      ans+=i;
    }
  printf("%d\n",ans);
  return 0;
}
