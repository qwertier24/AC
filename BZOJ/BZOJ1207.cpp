#include<stdio.h>
#include<algorithm>
#include<math.h>
#define M 10010
#define FOR(i,n) for(int i=1; i<=n; i++)

using namespace std;

int n,m,x[M],y[M],d[M],t[M],ans;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  FOR(i,m){
    scanf("%d%d%d",&t[i],&x[i],&y[i]);
    d[i]=1;
    FOR(j,i-1)
      if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])
	d[i]=max(d[i],d[j]+1);
    ans=max(ans,d[i]);
  }
  printf("%d\n",ans);
  return 0;

}
