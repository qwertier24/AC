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
#define N 9999

int d[N+10],ans;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  FOR(i,N){
    int s=0;
    for(int j=2; j*j<=i; j++){
      if(i%j==0){
        s+=j;    
        if(j*j!=i)
          s+=i/j;
      }
    }
    d[i]=s+1;
    //printf("%d %d\n",i,s);
    if(d[i]<i && d[d[i]]==i){
      ans+=i;
      if(d[i]!=i)
        ans+=d[i];
    }
  }
  printf("%d\n",ans);
  return 0;
}
