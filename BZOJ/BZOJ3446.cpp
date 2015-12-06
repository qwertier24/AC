#include<stdio.h>
#include<algorithm>
#include<vector>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 20
#define X first
#define Y second
#define MP make_pair

using namespace std;
typedef long long LL;

int d[1<<N];
int cnt_ones(int x){
  int ret=0;
  while(x){
    ret+=x&1;
    x>>=1;
  }
  return ret;
}
int n,m,g[N][N];
vector<pair<int,int> > bonus[N];
int main(){
#ifndef ONLINE_JUDGE
  freopen("dec.in","r",stdin);
  freopen("dec.out","w",stdout);
#endif 
  scanf("%d%d",&n,&m);
  Rep(i,m){
    int k,a,b;
    scanf("%d%d%d",&k,&a,&b);
    bonus[k-1].push_back(MP(a,b));
  }
  Rep(i,n)Rep(j,n)
    scanf("%d",&g[i][j]);
  Rep(i,n)
    sort(bonus[i].begin(),bonus[i].end());
  Rep(i,(1<<n)){
    int cur=cnt_ones(i)-1;
    if(cur==-1)continue;
    Rep(j,n)
      if(i&(1<<j))
	d[i]=max(d[i],d[i^(1<<j)]+g[j][cur]);
    //return 0;
    Rep(j,bonus[cur].size()){
      if(bonus[cur][j].X>d[i])
	break;
      d[i]+=bonus[cur][j].Y;
    }
  }
  printf("%d\n",d[(1<<n)-1]);
  return 0;
}
