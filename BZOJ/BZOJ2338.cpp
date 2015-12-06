#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 1510
#define X first
#define Y second

typedef long long LL;
using namespace std;
typedef pair<int,int> P;

struct Line{
  int mx,my;
  LL dist2,dx,dy;
  Line(int a,int b,LL c,LL d):mx(a),my(b),dx(c),dy(d),dist2(c*c+d*d){}
  LL operator*(Line &l){
    return abs(dx*l.dy-dy*l.dx);
  }
  bool operator<(const Line& r)const{
    if(mx==r.mx){
      if(my==r.my)
        return dist2<r.dist2;
      return my<r.my;
    }
    return mx<r.mx;
  }
};
vector<Line> line;
P p[N];
int n;
int main(){
#ifdef LOCAL
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  For(i,n)
    scanf("%d%d",&p[i].X,&p[i].Y);
  For(i,n)For(j,i-1){
    line.push_back(Line(p[i].X+p[j].X,p[i].Y+p[j].Y,p[j].X-p[i].X,p[j].Y-p[i].Y));
  }
  sort(line.begin(),line.end());
  int lpos=0;
  LL ans=0;
  Rep(i,line.size()){
    if(i==0 || (line[i].mx!=line[i-1].mx || line[i].my!=line[i-1].my || line[i].dist2!=line[i-1].dist2))
      lpos=i;
    for(int j=lpos; j<i; j++)
      ans=max(ans,line[i]*line[j]);
  }
  printf("%lld\n",ans/2);
  return 0;
}
