#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<queue>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 500010

int m;
set<int> pos;
multiset<int,greater<int> > gap;
bool check(int p){
  if(*gap.begin()>m)return false;
  multiset<int,greater<int> >::iterator it1,it2;
  it1=it2=pos.lower_bound(p);
  it1--;
  it2++;
  if(*it2-*it1>m)return false;
  gap.insert(*it2-*it1);
  gap.erase(gap.find(p-*it1));
  gap.erase(gap.find(*it2-p));
  pos.erase(p);
  return true;
}

int id[N],a[N],b[N],n,ans=(~0u)>>1;
inline bool by_a(const int& i,const int &j){
  return a[i]<a[j];
}
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  REP(i,1,n){scanf("%d%d",&a[i],&b[i]);id[i]=i;}
  sort(id+1,id+n+1,by_a);
  pos.insert(0);
  pos.insert(n+1);
  gap.insert(n+1);
  priority_queue<pair<int,int> > pq;
  set<int>::iterator it1,it2;
  REP(k,1,n){
    int &i=id[k];
    it2=it1=pos.insert(i).first;
    //printf("%d %d %d %d %d\n",i,a[i],b[i],*gap.begin(),pq.empty()?-1:pq.top().first);
    it1--;
    it2++;
    gap.erase(gap.find(*it2-*it1));
    gap.insert(i-*it1);
    gap.insert(*it2-i);
    pq.push(make_pair(b[i],i));
    while(!pq.empty() && check(pq.top().second))
      pq.pop();
    if(!pq.empty() && *gap.begin()<=m)
      ans=min(ans,pq.top().first*a[i]);
    //printf("%d %d %d %lu\n",i,a[i],b[i],pq.size());
  }
  printf("%d\n",ans);
  return 0;
}
