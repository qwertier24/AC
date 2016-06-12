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

int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int p,a,b;
  scanf("%d%d%d",&p,&a,&b);
  if(p < b){
      puts("-1");
  }else{
      printf("%d\n",max(p,a+b));
  }
  return 0;
}
