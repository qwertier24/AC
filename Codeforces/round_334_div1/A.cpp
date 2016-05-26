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

#define N  100010
int n;
char a[N];
int L[N][2],R[N][2];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  scanf("%s",a);
  int lft=-1,rgt=n-1;
  REP(i,n){
    if(a[i]==a[i+1]){
      if(lft==-1)
        lft=i+1;
      else
        rgt=i;
    }
  }
  if(lft!=-1)for(int i=lft; i<=rgt; i++)
    a[i]=a[i]=='1'?'0':'1';
  REP(i,n){
    if(i==0){
      L[i][a[i]=='1']=1;
      continue;
    }
    int cur=(a[i]=='1');
    L[i][cur]=L[i-1][1^cur]+1;
    L[i][cur^1]=L[i-1][cur^1];
  }
  printf("%d\n",max(L[n-1][0],L[n-1][1]));
  return 0;
}
