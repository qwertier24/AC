#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 100

typedef long long LL;
using namespace std;

LL f[N],n,d[N][2];
vector<int> dig;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  f[1]=1;
  f[2]=2;
  for(int i=3; i<N; i++)f[i]=f[i-1]+f[i-2];
  scanf("%lld",&n);
  dig.clear();
  for(int i=88; n; i--)if(n>=f[i])n-=f[i],dig.push_back(i);
  reverse(dig.begin(),dig.end());
  int m=dig.size();
  d[0][1]=1;
  d[0][0]=(dig[0]-1)>>1;
  for(int i=1; i<m; i++){
    d[i][1]=d[i-1][0]+d[i-1][1];
    d[i][0]=((dig[i]-dig[i-1])>>1)*d[i-1][0] + ((dig[i]-dig[i-1]-1)>>1)*d[i-1][1];
  }
  printf("%lld\n",d[m-1][0]+d[m-1][1]);
  return 0;
}
