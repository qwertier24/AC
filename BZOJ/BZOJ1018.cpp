#include<stdio.h>
#include<algorithm>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define T 0
#define B 1
#define N 100000
#define mid ((l+r)>>1)
#define lc (o<<1)
#define rc (o<<1|1)

using namespace std;

int open[3][N+10];

int L,R;

struct Node{
  int route[2][2];
  void update(const Node& a,const Node& b){
    route[T][T]=(a.route[T][B]&b.route[B][T])|(a.route[T][T]&b.route[T][T]);
    route[T][B]=(a.route[T][T]&b.route[T][B])|(a.route[T][B]&b.route[B][B]);
    route[B][T]=(a.route[B][T]&b.route[T][T])|(a.route[B][B]&b.route[B][T]);
    route[B][B]=(a.route[B][B]&b.route[B][B])|(a.route[B][T]&b.route[T][B]);
  }
}node[N<<2];
void update(int o,int l,int r){
  if(l==r&&L<=l&&r<=R){
    node[o].route[T][T]=(open[0][l])|(open[2][l]&open[1][l]&open[2][l+1]);
    node[o].route[T][B]=(open[0][l]&open[2][l+1])|(open[2][l]&open[1][l]);
    node[o].route[B][T]=(open[2][l]&open[0][l])|(open[1][l]&open[2][l+1]);
    node[o].route[B][B]=(open[1][l])|(open[2][l]&open[0][l]&open[2][l+1]);
    return;
  }
  if(L<=mid)update(lc,l,mid);
  if(R>mid) update(rc,mid+1,r);
  node[o].update(node[lc],node[rc]);
}
Node query(int o,int l,int r){
  if(L<=l&&r<=R)return node[o];
  if(R<=mid)return query(lc,l,mid);
  if(L>mid)return query(rc,mid+1,r);
  Node ret;
  ret.update(query(lc,l,mid),query(rc,mid+1,r));
  return ret;
}

set<int> rows[2];
set<int>::iterator it;
char o[10];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif 
  int n;
  scanf("%d",&n);
  Rep(i,n+1)rows[0].insert(i),rows[1].insert(i);
  int kase=1;
    while(scanf("%s",o)&&o[0]!='E'){
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    x1--,x2--;
    if(y1>y2)swap(x1,x2),swap(y1,y2);
    if(o[0]=='C'||o[0]=='O'){
      int f=o[0]=='O';
      if(x1==x2){
	open[x1][y1]=f;
	L=R=y1;
	if(!f)rows[x1].insert(y1);
	else rows[x1].erase(y1);
      }else{
      	open[2][y1]=f;
      	L=max(1,y1-1),R=min(n-1,y1);
      }
      update(1,1,n-1);
    }else{
      if(y1==y2){
	if(open[2][y1]){
	  puts("Y");
	  continue;
	}
	if(open[x1][y1-1]){
	  y1--;
	}else if(open[x1][y1]){
	  y1++;
	}else if(open[x2][y2-1]){
	  y2--;
	}else if(open[x2][y2]){
	  y2++;
	}else{
	  puts("N");
	  continue;
	}
      }
      if(y1>y2)swap(x1,x2),swap(y1,y2);
      it=rows[x1].lower_bound(y1);
      --it;
      L=*it+1;
      R=*rows[x2].lower_bound(y2)-1;
      Node ans=query(1,1,n-1);
      if(ans.route[x1][x2])puts("Y");
      else puts("N");
    }
  }
  return 0;
}
