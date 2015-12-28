#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<bitset>
#include<iostream>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 512
bitset<N> bt[N],ALL;
int p;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&p);
  bt[0]=0;
  ALL[0]=1;
  FOR(i,p){
    REP(j,(1<<i-1)){
      bt[j+(1<<i-1)]=bt[j]|(bt[j]<<(1<<(i-1)));
      bt[j]=(ALL^bt[j])|(bt[j]<<(1<<(i-1)));
      //printf("%d %d:\n",i,j);
      //cout<<bt[j]<<endl;
      //cout<<bt[j+(1<<i-1)]<<endl;
    }
    ALL|=ALL<<(1<<i-1);
    //cout<<ALL<<endl;
  }
  REP(i,1<<p)REP(j,1<<p)
    printf("%c%s",bt[i][j]?'*':'+',j==(1<<p)-1?"\n":"");
  return 0;
}
