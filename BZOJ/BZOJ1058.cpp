#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define mp make_pair
#define N 500010
#define INSERT 0
#define MINGAP 1
#define MINSORTGAP 2

using namespace std;

set<pair<int,int> > st;
set<pair<int,int> >::iterator it1,it2;
multiset<int> gap;
void Insert(int p,int v){
  it1=st.lower_bound(mp(p,v));
  it1--;
  it2=st.lower_bound(mp(p,v));
  gap.insert(abs(v-it1->second));
  if(it2!=st.end()){
    gap.insert(abs(v-it2->second));
    gap.erase(gap.lower_bound(abs(it2->second-it1->second)));
  }
  st.insert(mp(p,v));
}
set<int> sortst;
set<int>::iterator it;
int minsortgap=1<<30;
void maintain_sort_gap(int v){
  if(minsortgap==0)return;
  it=sortst.lower_bound(v);
  if(it!=sortst.end()){
    minsortgap=min(minsortgap,*it-v);
  }
  if(it!=sortst.begin()){
    --it;
    minsortgap=min(minsortgap,v-*it);
  }
  sortst.insert(v);
}
int n,m,a[N],behind[N],pos[N];
char o[10];
struct OPT{
  int type,x,y;
}opt[N];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  For(i,n)
    scanf("%d",&a[i]);
  For(i,m){
    scanf("%s",o);
    if(o[4]=='R'){
      scanf("%d%d",&opt[i].x,&opt[i].y);
      behind[opt[i].x]++;
      opt[i].type=INSERT;
    }else if(o[4]=='G')
      opt[i].type=MINGAP;
    else 
      opt[i].type=MINSORTGAP;
  }
  int sum=0;
  For(i,n){
    sum++;
    pos[i]=sum;
    st.insert(mp(pos[i],a[i]));
    if(i>1)gap.insert(abs(a[i]-a[i-1]));
    maintain_sort_gap(a[i]);
    sum+=behind[i];
  }
  For(i,m){
    if(opt[i].type==INSERT){
      pos[opt[i].x]++;
      Insert(pos[opt[i].x],opt[i].y);
      maintain_sort_gap(opt[i].y);
    }else if(opt[i].type==MINGAP){
      printf("%d\n",*gap.begin());
    }else{
      printf("%d\n",minsortgap);
    }
  }
  return 0;
}
