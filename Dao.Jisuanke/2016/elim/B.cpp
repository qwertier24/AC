#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair


int a[3],b[3];
int cmp(int i, int j){
  return b[i] > b[j] || (b[i] == b[j] && i < j);
}
int check(int x){
  int lst = -1, ans = 0;
  b[0] = a[0];
  b[1] = a[1];
  b[2] = a[2];
  
  b[0] -= x;
  b[1] -= x;
  FOR(i,x){
    int id[3] = {0,1,2};
    sort(id,id+3,cmp);
    int cur = -1;
    REP(i,3){
      if(id[i] != lst && b[id[i]] > 0){
        cur = id[i];
        break;
      }
    }
    if(cur == -1)
      return false;
    b[cur]--;
    //printf("%d %d %d %d %d\n", cur, lst,b[0],b[1],b[2]);
    lst = cur;
    ans++;
    lst = cur;
  }
  return true;
}
int getans1(){
  int lo = 0, hi = min(a[0],a[1]);
  while(lo < hi){
    int mi = (lo + hi + 1)>>1;
    if(check(mi))
      lo = mi;
    else
      hi = mi -1;
  }
  return lo;
}

int getmin(int lst){
  int ret;
  if(lst != 0){
    if(a[0])
      ret = 0;
    else{
      if(lst == -1)
        ret = a[1] >= a[2] ? 1 : 2;
      else
        ret = (lst == 1 ? 2 : 1);
    }
  }else{
    ret = a[1] >= a[2] ? 1 : 2;
  }
  if(a[ret] <= 0)
    return -1;
  else
    return ret;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%d%d%d",&a[0],&a[1],&a[2]);
    //int ans1 = getans1();
    swap(a[0], a[2]);
    int fst = -1, ans = 0, lst = -1;
    while(true){
      int &x = a[0], &y = a[1], &z = a[2];
      y--;
      z--;
      if(x < 0 || y < 0 || z < 0){
        break;
      }
      int cur = getmin(lst);
      if(cur == -1){
        break;
      }
      if(fst == -1)
        fst = cur;
      a[cur]--;
      //printf("%d %d %d %d %d\n", lst, cur,x,y,z);
      lst = cur;
      ans++;
    }
    //printf("%d\n",fst);
    //printf("%d %d %d %d %d\n", fst,getmin(fst),a[0],a[1],a[2]);
    if(fst != -1 && a[1] >= 0 && a[2] >= 0 && getmin(fst) != -1)
      ans++;
    printf("%d\n", ans);
  }
  return 0;
}
