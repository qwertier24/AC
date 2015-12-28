#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<iostream>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 100010

LL ans;
void union_line(vector<pii> &v2){
  vector<pii> v=v2;
  v2.clear();
  sort(v.begin(), v.end());
  FOR(i,v.size()-1){
    if(v[i-1].second+1<v[i].first)
      v2.push_back(v[i-1]);
    else{
      v[i].second=max(v[i].second,v[i-1].second);
      v[i].first=v[i-1].first;
    }
  }
  v2.push_back(v[v.size()-1]);
  
  REP(i,v2.size())
    ans+=v2[i].second-v2[i].first+1;
}
struct Event{
  int x,y,f;
  bool operator<(const Event& rhs)const{
    return x<rhs.x;
  }
  Event(int a,int b,int c):x(a),y(b),f(c){}
};

int yc[N],yn;
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
int sumv[N<<2];
void modify(int p,int v,int o=1,int l=1,int r=yn){
  if(l==r){
    sumv[o]=v;
    return;
  }
  if(p<=mid)modify(p,v,lc,l,mid);
  else modify(p,v,rc,mid+1,r);
  sumv[o]=sumv[lc]+sumv[rc];
}
int query(int L,int R,int o=1,int l=1,int r=yn){
  if(R<L)return 0;
  if(L<=l && r<=R)
    return sumv[o];
  int ret=0;
  if(L<=mid)
    ret+=query(L,R,lc,l,mid);
  if(R>mid)
    ret+=query(L,R,rc,mid+1,r);
  return ret;
}

vector<Event> event;
map<int,vector<pii> > x,y;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int n;
  scanf("%d",&n);
  FOR(i, n){
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    if(x1==x2){
      x[x1].push_back(MP(min(y1,y2),max(y1,y2)));
    }else{
      yc[++yn]=y1;
      y[y1].push_back(MP(min(x1,x2),max(x1,x2)));
    }
  }
  for(map<int,vector<pii> > ::iterator it=y.begin(); it!=y.end(); ++it){
    union_line(it->second);
    vector<pii> &v=it->second;
    REP(i,v.size()){
      event.push_back(Event(v[i].first,it->first,1));
      event.push_back(Event(v[i].second+1,it->first,0));
    }
  }
  sort(event.begin(),event.end());
  sort(yc+1,yc+yn+1);
  yn=unique(yc+1,yc+yn+1)-yc-1;
  int cur=0;
  for(map<int,vector<pii> >::iterator it=x.begin(); it!=x.end(); ++it){
    while(cur<event.size() && event[cur].x<=it->first){
      modify(lower_bound(yc+1,yc+yn+1,event[cur].y)-yc,event[cur].f);
      cur++;
    }
    union_line(it->second);
    for(vector<pii>::iterator it2=(it->second).begin(); it2!=(it->second).end(); ++it2){
      ans-=query(lower_bound(yc+1,yc+yn+1,it2->first)-yc, upper_bound(yc+1,yc+yn+1,it2->second)-yc-1);
    }
  }
  cout<<ans;
  return 0;
}
