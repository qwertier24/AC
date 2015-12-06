#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;

int n,m;
int main(){
  freopen("frog.in","r",stdin);
  freopen("frog.out","w",stdout);
  scanf("%d%d",&n,&m);
  printf("%d\n",(1<<n)*(m+1));
  return 0;
}
