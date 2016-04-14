#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

unordered_map<int,map<int,int> > cnt;
unordered_map<int,int> mx,my;
int n, x[200010],y[200010];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  LL ans = 0;
  FOR(i,n){
    scanf("%d%d",&x[i],&y[i]);
    ans += mx[x[i]] + my[y[i]] - cnt[x[i]][y[i]];
    mx[x[i]] ++;
    my[y[i]]++;
    cnt[x[i]][y[i]]++;
  }
  cout<<ans;
  return 0;
}
