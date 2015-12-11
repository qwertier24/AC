#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<iostream>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

string name[6000];
int m;
bool read_name(string &s){
  int c=getchar(),ret=0;
  while(c!='\"'){
    if(c==-1)return false;
    c=getchar();
  }
  c=getchar();
  while(c!='\"'){
    s.push_back(c);
    c=getchar();
  }
  return true;
}
int getV(string s){
  int ret=0;
  REP(i,s.size()){
    ret+=s[i]-'A'+1;
  }
  return ret;
}
int t;
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int ans=0;
  while(read_name(name[m]))m++;
  sort(name,name+m);
  REP(i,m)ans+=getV(name[i])*(i+1);
  printf("%d\n",ans);
  return 0;
}
