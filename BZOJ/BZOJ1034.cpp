#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100000

using namespace std;

multiset<int> st;
multiset<int>::iterator it;
int n,a[N+10],b[N+10];
int mark[N+10];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  int maxScore=0,minScore=2*n;
  For(i,n)scanf("%d",&a[i]);
  For(i,n)scanf("%d",&b[i]);

  sort(b+1,b+n+1);
  For(i,n)st.insert(a[i]);
  for(int i=n; i; i--){
    it=st.upper_bound(b[i]);
    if(it!=st.end()){
      maxScore+=2;
      st.erase(it);
      mark[i]=1;
    }
  }
  For(i,n)if(!mark[i]){
    it=st.lower_bound(b[i]);
    if(it!=st.end()){
      maxScore++;
      st.erase(it);
    }
  }

  st.clear();
  memset(mark,0,sizeof(mark));
  sort(a+1,a+n+1);
  For(i,n)st.insert(b[i]);
  for(int i=n; i; i--){
    it=st.upper_bound(a[i]);
    if(it!=st.end()){
      minScore-=2;
      st.erase(it);
      mark[i]=1;
    }
  }
  For(i,n)if(!mark[i]){
    it=st.lower_bound(a[i]);
    if(it!=st.end()){
      minScore--;
      st.erase(it);
    }
  }
  printf("%d %d\n",maxScore,minScore);
  return 0;
}
