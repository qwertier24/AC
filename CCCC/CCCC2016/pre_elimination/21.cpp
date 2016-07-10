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

#define N 10010
int cnt[N], n, id[N], bag[N];
bool cmp(int i,int j){
    if(cnt[i] == cnt[j]){
        if(bag[i] == bag[j])
            return i < j;
        else
            return bag[i] > bag[j];
    }else
        return cnt[i] > cnt[j];
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  FOR(i,n){
      int k;
      scanf("%d", &k);
      FOR(j,k){
          int u, w;
          scanf("%d%d",&u,&w);
          cnt[u] += w;
          cnt[i] -= w;
          bag[u] ++;
      }
      id[i] = i;
  }
  sort(id+1, id+n+1, cmp);
  FOR(i,n)
      printf("%d %.2f\n", id[i], cnt[id[i]]/100.0);
  return 0;
}
