#include<stdio.h>
#include<algorithm>
#include<iostream>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

typedef long long LL;
using namespace std;

int n=10;
LL ans=1,maxp=1,m;
int pr[11]={0,2,3,5,7,11,13,17,19,23,29};
void dfs(LL num,int pos,int pw,int psum){
  if(pos>n)return;
  if(num>m)return;
  if(psum>maxp){
    ans=num;
    maxp=psum;
  }else if(psum==maxp&&num<ans){
    ans=num;
  }
  //printf("%I64d %d\n",num,pos);
  LL t=num;
  For(i,pw){
    t*=pr[pos];
    if(t>m)break;
    dfs(t,pos+1,i,(psum*(i+1)));
  }
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  cin>>m;
  dfs(1,1,35,1);
  cout<<ans;
  return 0;
}
