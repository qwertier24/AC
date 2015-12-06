#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#include<vector>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 1010
#define MP make_pair

typedef long long LL;
using namespace std;

int n,m;

int a[N];
map<int,int> cnt;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d",&n,&m);
  For(i,n){
    scanf("%d",&a[i]);
    int j;
    for(j=2; j*j<a[i]; j++)
      if(a[i]%j==0)
        cnt[a[i]/j]++,cnt[j]++;
    if(j*j==a[i])
      cnt[j]++;
    cnt[a[i]]++;
  }
  
  int ans=0;
  for(map<int,int>::iterator it=cnt.begin(); it!=cnt.end(); ++it)
    if(it->second>=m)
      ans=it->first;
  printf("%d\n",ans);
  return 0;
}
