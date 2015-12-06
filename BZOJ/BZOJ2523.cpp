#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;
typedef long long LL;

int calc(int a,int b,int i,int j,int k){
  if(a==b)return k;
  else if(a>b)return calc(b,a-b,j,k,i)+(k-i+3)%3;
  else return calc(a,b-a,i,k,j)+(k-j+3)%3;
}
vector<int> ans;
int n,m;
int t[3];
void init(int a,int b,int c){
  t[0]=a;t[1]=b;t[2]=c;
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  while(scanf("%d%d",&n,&m) && n>=0){
    n--;
    if(n%3==0)init(1,2,0);
    else if(n%3==1)init(0,2,1);
    else init(0,1,2);
    ans.clear();
    For(i,m-1)if(calc(i,m-i,t[0],t[1],t[2])==n)
      ans.push_back(i);
    printf("%d\n",(int)ans.size());
    Rep(i,ans.size()){
      if(n%3==0)printf("%d %d %d\n",m,ans[i],m-ans[i]);
      else if(n%3==1)printf("%d %d %d\n",ans[i],m,m-ans[i]);
      else printf("%d %d %d\n",ans[i],m-ans[i],m);
    }
  }
  return 0;
}
