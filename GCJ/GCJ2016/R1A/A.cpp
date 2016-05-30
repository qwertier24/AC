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

char s[1010];
int main(){
#ifdef QWERTIER
  freopen("A-large.in","r",stdin);
  freopen("A-large.out","w",stdout);
#endif 
  int T;
  scanf("%d",&T);
  FOR(kase,T){
    printf("Case #%d: ",kase);
    scanf("%s",s);
    int n = strlen(s);
    string s1,s2,ans;
    REP(i,n){
      s1 = ans + s[i];
      s2 = s[i] + ans;
      if(s1 > s2)
        ans = s1;
      else
        ans = s2;
    }
    cout<<ans<<endl;
  }
  return 0;
}
