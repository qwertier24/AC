#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
#define N 20010

using namespace std;

#define MP make_pair
typedef pair<int,int> pii;
int n;
set<pii> st;
set<pii>::iterator it,it2;
int a[N*5],b[N*5];
int pos[N][6];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,1,n*5)
    scanf("%d",&a[i]);
  REP(i,1,n*5){
    scanf("%d",&b[i]);
    pos[b[i]][++pos[b[i]][0]]=i;
  }
  st.insert(MP(0,0));
  st.insert(MP(n*5+1,n*5+1));
  int ans=0;
  REP(i,1,n*5){
    RREP(j,5,1){
      int k=pos[a[i]][j];
      pii tmp(k,0);
      it=st.lower_bound(tmp);
      --it;
      int dt=it->second+1;
      ans=max(ans,dt);
      ++it;
      if(it->first>k || (it->first==k&&it->second<dt)){
        while(it!=st.end() && it->second<=dt){
          it2=it;
          ++it2;
          st.erase(it);
          it=it2;
        }
        st.insert(MP(k,dt));
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}
