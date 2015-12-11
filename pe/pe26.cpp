#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

int count(int n){
  while(n%2==0)n/=2;
  while(n%5==0)n/=5;
  int ret=0,cur=1;
  if(n==1)return 0;
  do{
    cur=cur*10%n;
    ret++;
  }while(cur%n!=1);
  return ret;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int n=1000;
  int ans=1,maxloop=0;
  FOR(i,n){
    if(count(i)>maxloop){
      maxloop=count(i);
      ans=i;
    }
  }
  printf("%d\n",ans);
  return 0;
}
