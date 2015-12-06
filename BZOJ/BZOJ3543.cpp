#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 100010

int n,x[N],y[N],xm,ym,xc[N],yc[N];
vector<int> row[N],col[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%d",&n);
  REP(i,1,n){
    scanf("%d%d",&x[i],&y[i]);
    xc[i]=x[i];yc[i]=y[i];
  }
  sort(xc+1,xc+n+1);
  xm=unique(xc+1,xc+n+1)-xc-1;
  sort(yc+1,yc+n+1);
  ym=unique(yc+1,yc+n+1)-yc-1;
  REP(i,1,n){
    x[i]=lower_bound(xc+1,xc+xm+1,x[i])-xc;
    y[i]=lower_bound(yc+1,yc+ym+1,y[i])-yc;
    row[x[i]].push_back(y[i]);
    col[y[i]].push_back(x[i]);
  }
  REP(i,1,xm)sort(row[i].begin(),row[i].end());
  REP(i,1,ym)sort(col[i].begin(),col[i].end());
  int x,y,xt,yt,ans=0;
  REP(i,1,xm){
    REP(j,0,int(row[i].size())-1){
      x=i,y=row[i][j];
      int p=j+1,q=lower_bound(col[y].begin(),col[y].end(),x)-col[y].begin()+1;
      while(p<row[x].size() && q<col[y].size()){
        yt=row[x][p],xt=col[y][q];
        if(xc[xt]-xc[x]<yc[yt]-yc[y])q++;
        else if(xc[xt]-xc[x]>yc[yt]-yc[y])p++;
        else{
          ans+=binary_search(row[xt].begin(),row[xt].end(),yt);
          p++;
          q++;
        }
      }
    }
  }
  printf("%d\n",ans);
  return 0;
}
