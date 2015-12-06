#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<set>
#define milk first
#define deadline second
#define N 10000
#define PROB "msched"
#define For(i,n) for(int i=1; i<=n; i++)

using namespace std;

typedef pair<int,int> Cow;
Cow cow[N+10];
set<int> st;
set<int>::iterator it;
int n;
int main(){
  freopen(PROB".in","r",stdin);
  freopen(PROB".out","w",stdout);
  scanf("%d",&n);
  For(i,n)
    scanf("%d%d",&cow[i].milk,&cow[i].deadline);
  sort(cow+1,cow+n+1);
  reverse(cow+1,cow+n+1);
  For(i,10000)st.insert(i);
  int ans=0;
  For(i,n){
    it=st.upper_bound(cow[i].deadline);
    if(it--!=st.begin()){
      st.erase(it);
      ans+=cow[i].milk;
    }
  }
  printf("%d",ans);
  return 0;
}
