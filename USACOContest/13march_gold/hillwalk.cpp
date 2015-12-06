#include<stdio.h>
#include<algorithm>
#include<set>
#include<vector>
#define PROB "hillwalk"
#define N 100000
#define For(i,n) for(int i=1; i<=n; i++)

using namespace std;

struct Edge{
  int ord,x1,y1,x2,y2;
  bool operator<(const Edge& o)const{
    if (x2 < o.x2) {
      return (long long) (y2 - o.y1) * (long long) (o.x2 - o.x1) <
	(long long) (o.y2 - o.y1) * (long long) (x2 - o.x1);
    } else {
      return (long long) (o.y2 - y1) * (long long) (x2 - x1) >
	(long long) (y2 - y1) * (long long) (o.x2 - x1);
    }
  }
}edges[N+10];
struct Event{
  int ord,x,y;
  Event(){}
  Event(int a,int b,int c):x(a),y(b),ord(c){}
  bool operator<(const Event& rhs)const{
    return x<rhs.x||(x==rhs.x&&y<rhs.y);
  }
};
vector<Event> events;
set<Edge> st;
set<Edge>::iterator it,it2;
int n;
int main(){
  freopen(PROB".in","r",stdin);
  freopen(PROB".out","w",stdout);
  scanf("%d",&n);
  For(i,n){
    scanf("%d%d%d%d",&edges[i].x1,&edges[i].y1,&edges[i].x2,&edges[i].y2);
    edges[i].ord=i;
    events.push_back(Event(edges[i].x1,edges[i].y1,i));
    events.push_back(Event(edges[i].x2,edges[i].y2,i));
  }
  int cur=1,ans=1;
  st.insert(edges[1]);
  sort(events.begin(),events.end());
  for(int i=1; i<events.size(); i++){
    Event event=events[i];
    Edge edge=edges[events[i].ord];
    if(event.x==edge.x1)
      st.insert(edge);
    else{
      if(event.ord==cur){
        it=st.find(edge);
	if(it==st.begin())break;
	it2=it;
	it2--;
	cur=it2->ord;
	st.erase(it);
	ans++;
      }else
	st.erase(edge);
    }
    //printf("%d\n",cur);
  }
  printf("%d",ans);
  return 0;

}
