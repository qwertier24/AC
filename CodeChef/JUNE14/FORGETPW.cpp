#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;

int n,m;

char s1[5],s2[5],str[1000010],change[256];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  int T;
  scanf("%d",&T);
  while(T--){
    memset(change,0,sizeof(change));
    scanf("%d",&m);
    while(m--){
      scanf("%s%s",s1,s2);
      change[s1[0]]=s2[0];
    }
    scanf("%s",str);
    n=strlen(str);
    REP(i,n)if(change[str[i]]){
      str[i]=change[str[i]];
    }
    int comma=0;
    REP(i,n)if(str[i]=='.')comma=1;
    int st=0,ed=n-1;
    if(comma){
      while(str[st]=='0')st++;
      while(str[ed]=='0')ed--;
      if(st==ed){
        puts("0");
      }else{
        if(str[ed]=='.'){
          for(int i=st; i<ed; i++)
            putchar(str[i]);
          putchar('\n');
        }else{
          for(int i=st; i<=ed; i++)
            putchar(str[i]);
          putchar('\n');
        }
      }
    }else{
      while(str[st]=='0' && st<ed)st++;
      for(int i=st; i<=ed; i++)
        putchar(str[i]);
      putchar('\n');
    }
  }
  return 0;
}
