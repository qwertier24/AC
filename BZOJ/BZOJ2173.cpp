#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define MOD 1000000007
#define N 1000010

typedef long long LL;
using namespace std;

int f[N],n;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  f[1]=1;
  f[2]=2;
  for(int i=3; i<=n; i++)
    f[i]=(f[i-1]+(LL)f[i-1]+f[i-2])%MOD;
  printf("%d\n",f[n]);
  return 0;
}
