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

#define N 1000010
int n,f[N];

char s[N],t[N];

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  n--;
  scanf("%s",s);
  scanf("%s",t);
  reverse(s,s+n);
  REP(i,n){
    if(s[i]=='N' or s[i]=='S')
      s[i]=s[i]=='N'?'S':'N';
    else
      s[i]=s[i]=='W'?'E':'W';
  }
  int k=-1;
  f[0]=-1;
  FOR(i,n-1){
    while(k>=0 && s[i]!=s[k+1])
      k=f[k];
    if(s[i]==s[k+1])
      k++;
    f[i]=k;
  }
  k=-1;
  REP(i,n){
    while(k>=0 && t[i]!=s[k+1])
      k=f[k];
    if(t[i]==s[k+1])
      k++;
  }
  if(k!=-1)
    puts("NO");
  else
    puts("YES");
  return 0;
}
