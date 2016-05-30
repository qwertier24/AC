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

#define N 10
string temp[N];

int n, m;

char s[200];
bool check(int dep){
    REP(i,dep)
        if(temp[i] == temp[dep])
            return false;
    return true;
}
bool dfs(int p, int dep){
    if(dep == n && p == m){
        puts("YES");
        REP(i,n)
            cout<<temp[i]<<endl;
        return true;
    }
    temp[dep] = string();
    for(int i = p; i < m; i++){
        temp[dep] += s[i];
        if(!check(dep))
            continue;
        if(dfs(i+1, dep+1))
            return true;
    }
    return false;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int T;
  scanf("%d",&T);
  while(T--){
      scanf("%s%d",s,&n);
      m = strlen(s);
      if(m < n*(n+1)/2){
          if(!dfs(0, 0))
              puts("NO");
      }else{
          puts("YES");
          int p = 0;
          REP(i,n-1){
              for(; p<=(i+1)*(i+2)/2; p++){
                  printf("%c",s[p]);
              }
              puts("");
          }
          for(; p<m; p++)
              printf("%c",s[p]);
          puts("");
      }
  }
  return 0;
}
