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
#define N 100010

int n,m,k;
int inmst[N],ew[N],eu[N],ev[N];
pii b[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  FOR(i,m){
    scanf("%d%d",&ew[i],&inmst[i]);
    if(inmst[i])
      b[++k]=MP(-ew[i],i);
  }
  sort(b+1,b+n);
  set<pair<int,pii> > st;
  FOR(i,n-1){
    eu[b[i].second] = i;
    ev[b[i].second] = i+1;
    if(i<=n-2)
      st.insert(MP(b[i].first,MP(i,i+2)));
  }
  FOR(i,m)if(!inmst[i]){
    set<pair<int,pii> >::iterator it = st.lower_bound( MP( -ew[i], MP(0,0) ) );
    if(it == st.end()){
      puts("-1");
      return 0;
    }else{
      eu[i] = (it->second).first;
      ev[i] = (it->second).second;
      //printf("%d %d\n",eu[i],ev[i]);
      pair<int,pii> tmp = *it;
      st.erase(it);
      tmp.second=MP(tmp.second.first,tmp.second.second+1);
      if(tmp.second.second<=n)
        st.insert(tmp);
    }
  }
  FOR(i,m)
    printf("%d %d\n",eu[i],ev[i]);
  return 0;
}
