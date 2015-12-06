#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;

int q[2][1010][1010],front[2][1010],rear[2][1010];
int qrow[2][1010],frow[2],rrow[2];
int v[2][1010];
bool cmp(int c,int a,int b){
  if(c)return a>=b;
  else return a<=b;
}
int n,m,s,a[1010][1010];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  memset(rear,-1,sizeof(rear));
  scanf("%d%d%d",&n,&m,&s);
  For(i,n)For(j,m)scanf("%d",&a[i][j]);
  int ans=1<<30;
  For(b,n){
    frow[0]=frow[1]=0;
    rrow[0]=rrow[1]=-1;
    For(r,m){
      Rep(i,2){
	while(front[i][r]<=rear[i][r]&&b-q[i][r][front[i][r]]>=s)front[i][r]++;
	while(front[i][r]<=rear[i][r]&&cmp(i,a[b][r],a[q[i][r][rear[i][r]]][r]))rear[i][r]--;
	q[i][r][++rear[i][r]]=b;
	v[i][r]=a[q[i][r][front[i][r]]][r];
	while(frow[i]<=rrow[i]&&r-qrow[i][frow[i]]>=s)frow[i]++;
	while(frow[i]<=rrow[i]&&cmp(i,v[i][r],v[i][qrow[i][rrow[i]]]))rrow[i]--;
	qrow[i][++rrow[i]]=r;
	//printf("v:%d %d %d %d\n",b,r,i,qrow[i][frow[i]]);
      }
      if(b>=s&&r>=s){
	ans=min(ans,v[1][qrow[1][frow[1]]]-v[0][qrow[0][frow[0]]]);
	//printf("%d %d %d %d\n",b,r,v[1][qrow[1][frow[1]]],v[0][qrow[0][frow[0]]]);
      }
    }
  }
  printf("%d",ans);
  return 0;
}
