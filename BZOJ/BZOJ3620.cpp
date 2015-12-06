#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;
#define N 15010

int k;
int fa[N],low[N];
int calc(char *s,int n){
  fa[1]=0;
  int j=0;
  int ret=0;
  if(k==1)low[1]=1;
  for(int i=2; i<=n; i++){
    while(j && s[j+1]!=s[i])j=fa[j];
    if(s[j+1]==s[i])j++;
    fa[i]=j;
    if(i>=k){
      if(fa[i]>=k)low[i]=low[fa[i]];
      else low[i]=i;
      if(low[i]*2<i)ret++;
    }
  }
  return ret;
}

int n,ans;
char s[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%s%d",s+1,&k);
  n=strlen(s+1);
  REP(i,n)
    ans+=calc(s+i,n-i);
  printf("%d\n",ans);
  return 0;
}
