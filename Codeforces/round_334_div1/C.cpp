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

int mex(int a,int b){
  if(a!=0 && b!=0)
    return 0;
  else{
    for(int i=0; i<3; i++)
      if(a!=i && b!=i)
        return i;
  }
}
void doit(){
  int n=100;
  int sg[n];
  sg[0]=0;
  for(int i=1; i<=n; i++){
    if(i%2==0)
      sg[i]=mex(sg[i-1],sg[i/2]);
    else
      sg[i]=sg[i-1]==0?1:0;
    printf("%d %d\n",i,sg[i]);
  }
 }

int SG(int x){
  if(x<4){
    if(x==0)return 0;
    else if(x==1)return 1;
    else if(x==2)return 0;
    else if(x==3)return 1;
  }
  if(x%2==0)
    return mex(SG(x-1),SG(x/2));
  else
    return 0;
}
#define N 100010
int n,k,a[N];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  //doit();
  scanf("%d%d",&n,&k);
  int ans=0;
  FOR(i,n){
    scanf("%d",&a[i]);
    if(k%2==0){
      if(a[i]==1)
        ans^=1;
      else if(a[i]==2)
        ans^=2;
      else
        ans^=(a[i]%2==0);
    }else{
      ans^=SG(a[i]);
    }
  }
  puts(ans?"Kevin":"Nicky");
  return 0;
}
