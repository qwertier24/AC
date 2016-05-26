#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<stack>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 100010
LL calc(int *a,int n){
  LL ret=0,suml=0;
  stack<pii> st;
  for(int i=2; i<=n; i++){
    int l=1;
    while(!st.empty() && abs(a[i]-a[i-1]) > st.top().first){
      suml-=st.top().first*(LL)st.top().second;
      l+=st.top().second;
      st.pop();
    }
    st.push(MP(abs(a[i]-a[i-1]),l));
    suml+=abs(a[i]-a[i-1])*(LL)l;
    ret+=suml;
  }
  return ret;
}
int n,m,a[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  FOR(i,n)scanf("%d",&a[i]);
  FOR(i,m){
    int l,r;
    scanf("%d%d",&l,&r);
    printf("%I64d\n",calc(a+l-1,r-l+1));
  }
  return 0;
}
