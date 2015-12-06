#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;

int v,v0;
int main(){
  freopen("ring.in","r",stdin);
  freopen("ring.out","w",stdout);
  scanf("%d%d",&v,&v0);
  if(v<v0)
    puts("0");
  else if(v==v0)
    puts("0");
  else{
    int n=v/(2*v0),t=v-n*2*v0,t2=(n+1)*2*v0-v;
    if(t==t2)puts("0");
    else if(t<t2)printf("%d\n",n);
    else printf("%d\n",n+1);
  }
  return 0;
}
