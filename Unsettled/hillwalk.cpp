#include<stdio.h>
#include<algorithm>
#include<set>
#define PROB "hillwalk"
#define For(i,n) for(int i=1; i<=n; i++)
#define N 100000

using namespace std;
bool flag=false;

struct Interval{
  int x1,y1,x2,y2,ord;
  bool operator<(const Interval& o)const{
    if(flag)printf("%d %d %d %d %d %d %d %d\n",x1,y1,x2,y2,o.x1,o.y1,o.x2,o.y2);
    return (y2-o.y1)*(o.x2-o.x1)>(o.y2-o.y1)*(x2-o.x1);
    if(make_pair(x1,y1)==make_pair(o.x1,o.y1)&&make_pair(x2,y2)==make_pair(o.x2,o.y2))return false;
    //return a>0;
  }
}interval[N+10];
set<Interval> st;

pair<int,int> x1[N+10],x2[N+10];

int n,l=1,r=1;
int mark[N+10]={0};

void print(){
    for(set<Interval>::iterator it=st.begin(); it!=st.end(); ++it)
        printf("%d %d %d %d\n",it->x1,it->y1,it->x2,it->y2);
}

int main(){
  freopen(PROB".in","r",stdin);
  //freopen(PROB".out","w",stdout);
  scanf("%d",&n);
  For(i,n){
    scanf("%d%d%d%d",&interval[i].x1,&interval[i].y1,&interval[i].x2,&interval[i].y2);
    x1[i]=make_pair(interval[i].x1,i);
    x2[i]=make_pair(interval[i].x2,i);
    interval[i].ord=i;
  }
  int curx=interval[1].x2,cury=interval[1].y2,ans=1;
  sort(x1+1,x1+n+1);
  sort(x2+1,x2+n+1);
  int cur=1;
  while(true){
    printf("!!");
    while(r<=n&&x2[r].first<=curx){
      printf("erase:%d\n",r);
      if(r==297){
        print();
        flag=true;
      }
      if(mark[x2[r].second]){
      printf("erase:%d\n",st.count(interval[x2[r].second]));
	   st.erase(interval[x2[r].second]);
      printf("erase:%d\n",r);
      }
      printf("erase:%d\n",r);
      mark[x2[r++].second]=1;
    }
    while(l<=n&&x1[l].first<=curx){
      if(!mark[x1[l].second]){
	st.insert(interval[x1[l].second]);
	mark[x1[l].second]=1;
      }
      l++;
      printf("insert:%d\n",l);
    }
    printf("%d %d %d\n",st.size(),l,r);
    set<Interval>::iterator it=st.upper_bound(interval[cur]);
    if(it==st.end())break;
    else{
      cur=it->ord;
      curx=it->x2;
      cury=it->y2;
      ans++;
    }
    printf("%d %d %d %d %d\n",l,r,curx,cury,st.size());
  }
  printf("%d",ans);
  return 0;
}

