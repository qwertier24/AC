#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;

int n,a[11],b[11],sg[1010],mark[1010],maxa,m,tot;
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,1,n){
    scanf("%d",&a[i]);
    maxa=max(maxa,a[i]);
  }
  scanf("%d",&m);
  REP(i,1,m)scanf("%d",&b[i]);
  REP(i,1,maxa){
    memset(mark,0,sizeof(mark));
    for(int j=1; j<=m&&b[j]<=i; j++)
      mark[sg[i-b[j]]]=1;
    while(mark[sg[i]])sg[i]++;
  }
  REP(i,1,n)tot^=sg[a[i]];
  REP(i,1,n){
    for(int j=1; j<=m&&b[j]<=a[i]; j++)
      if((tot^sg[a[i]]^sg[a[i]-b[j]])==0){
        printf("YES\n%d %d",i,b[j]);
        return 0;
      }
  }
  puts("NO");
  return 0;
}
