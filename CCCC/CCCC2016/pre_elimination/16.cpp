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

char ch[4] = {'G', 'P', 'L', 'T'};
int tot;
char s[10010];
int cnt[4];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%s",s);
  int n  = strlen(s);
  REP(i,n){
      REP(j,4)
          if(s[i] == ch[j] || s[i]-'a' +'A' == ch[j]){
              cnt[j]++;
              tot++;
          }
  }
  int cur = 0;
  while(tot){
      while(!cnt[cur]){
          cur = (cur + 1) % 4;
      }
      putchar(ch[cur]);
      cnt[cur]--;
      tot--;
      cur = (cur + 1) % 4;
  }
  return 0;
}
