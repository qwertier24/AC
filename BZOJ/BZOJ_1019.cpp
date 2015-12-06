#include<stdio.h>
#include<algorithm>
#include<stack>
#include<iostream>
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;

pair<int,int> opt[6];
int n;
long long calc(){
  long long ret;
  int a[3]={0};
  for(int cur=3; cur<=5; cur++){
    stack<int> pos[3];
    for(int i=cur; i; i--)pos[0].push(i);
    int last_step=-1;
    while(pos[1].size()!=cur&&pos[2].size()!=cur){
      a[cur-3]++;
      Rep(i,6)
	if(pos[opt[i].first].size()
	   &&(!pos[opt[i].second].size()||pos[opt[i].second].top()>pos[opt[i].first].top())
	   &&pos[opt[i].first].top()!=last_step){
	  pos[opt[i].second].push(pos[opt[i].first].top());
	  last_step=pos[opt[i].first].top();
	  pos[opt[i].first].pop();
	  break;
	}
    }
  }
  int A=(a[2]-a[1])/(a[1]-a[0]),B=a[2]-A*a[1];
  if(n<6)return a[n-3];
  ret=a[2];
  Rep(i,n-5)
    ret=ret*A+B;
  return ret;
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  char s[10];
  Rep(i,6){
    scanf("%s",s);
    opt[i].first=s[0]-'A';
    opt[i].second=s[1]-'A';
  }
  cout<<calc();
  return 0;
}
