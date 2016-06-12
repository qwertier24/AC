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

int n=30,m=30;

int score[1010] = {10000,100, 75, 60, 50, 45, 40, 36, 32, 29, 26, 24, 22, 20, 18, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

int a[30];
bool check(int r){
    set<int> st;
    FOR(i,m)
        if(i != r)
            st.insert(score[i]);
    int tmp = score[r],cnt=0;
    REP(i,n){
        auto it = st.lower_bound(tmp - a[i]);
        if(it == st.end())
            break;
        cnt++;
        st.erase(it);
    }
    //printf("%d %d %d\n", r,tmp, cnt);
    //printf("%d %d\n",tmp,cnt);
    return cnt<10;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  REP(i,10)scanf("%d",&a[i]);
  REP(i,20)
      a[i+10] = a[9];
  int lo = 0, hi = 1000;
  while(lo<hi){
      int mi = (lo + hi + 1) >> 1;
      if(check(mi))
          lo = mi;
      else
          hi = mi - 1;
  }
  printf("%d\n", lo);
  return 0;
}
