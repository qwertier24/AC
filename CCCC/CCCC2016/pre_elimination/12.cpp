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

bool in(int a,int b,int c,int d,int e, int f){
    if(MP(a,b) >= MP(c,d) && MP(a,b) <= MP(e,f))
        return true;
    else
        return false;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int h, m;
  scanf("%d:%d",&h,&m);
  if(in(h,m,0,0,12,0)){
      printf("Only %02d:%02d.  Too early to Dang.\n", h,m);
      return 0;
  }
  if(m)
      h++;
  FOR(i,h-12)
      printf("Dang");
  return 0;
}
