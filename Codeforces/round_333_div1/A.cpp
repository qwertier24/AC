#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 410
int n,m,road[N][N],rail[N][N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  memset(road,0x1f,sizeof(road));
  memset(rail,0x1f,sizeof(rail));
  FOR(i,m){
    int u,v;
    scanf("%d%d",&u,&v);
    rail[u][v]=rail[v][u]=1;
  }
  FOR(i,n)FOR(j,i-1)if(rail[i][j]>n)
    road[i][j]=road[j][i]=1;
  FOR(k,n)FOR(i,n)FOR(j,n)
    if(i!=j && j!=k && k!=i){
      road[i][j]=min(road[i][j],road[i][k]+road[k][j]);
      rail[i][j]=min(rail[i][j],rail[i][k]+rail[k][j]);
    }
  printf("%d\n",max(road[1][n],rail[1][n])>n?-1:max(road[1][n],rail[1][n]));
  return 0;
}
