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

int main(){
#ifdef QWERTIER
  freopen("B-large.in","r",stdin);
  freopen("B-large.out","w",stdout);
#endif 
  int T;
  scanf("%d",&T);
  FOR(kase,T){
    map<int,int> cnt;
    vector<int> ans;
    int n;
    printf("Case #%d: ",kase);
    scanf("%d",&n);
    FOR(i,2*n-1){
      FOR(j,n){
        int tmp;
        scanf("%d",&tmp);
        cnt[tmp]++;
      }
    }
    for(auto& man : cnt){
      if(man.second % 2)
        ans.push_back(man.first);
    }
    sort(ans.begin(),ans.end());
    for(auto &i : ans)
      printf("%d ",i);
    puts("");
  }
  return 0;
}
