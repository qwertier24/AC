#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<iostream>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

char s[3] = {'P','R','S'};
int n, cnt[3], c[3];
bool check(){
    REP(i,3)
        if(cnt[i] != c[i])
            return 0;
    return 1;
}
string dfs(int dep, int cur){
    if(dep == n){
        cnt[cur]++;
        string ret;
        ret += s[cur];
        return ret;
    }
    string tmp1 = dfs(dep + 1, cur);
    string tmp2 = dfs(dep + 1, (cur + 1) % 3);
    if(tmp1 > tmp2)
        swap(tmp1, tmp2);
    return tmp1 + tmp2;
}

int main(){
#ifdef QWERTIER
  freopen("A_l.in","r",stdin);
  freopen("A_l.out","w",stdout);
#endif 
  int T;
  scanf("%d",&T);
  FOR(kase,T){
      scanf("%d%d%d%d",&n,&c[1],&c[0],&c[2]);
      bool flag = false;
      string ans("Z");
      REP(i,3){
          memset(cnt, 0,sizeof(cnt));
          string tmp = dfs(0, i);
          if(check()){
              flag = true;
              if(ans > tmp)
                  ans = tmp;
          }
      }
      printf("Case #%d: ",kase);
      if(flag)
          cout<< ans<<endl;
      else
          cout<<"IMPOSSIBLE"<<endl;
  }
  return 0;
}
