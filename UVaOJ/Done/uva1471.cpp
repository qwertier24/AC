#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<set>
#define N 200000
#define INF (1<<30)
#define For(i,n) for(int i=1; i<=n; i++)

using namespace std;

void readint(int& x){
  x=0;
  char c=getchar();
  while(c<'0'||c>'9')c=getchar();
  while(c>='0'&&c<='9'){
    x=x*10+c-'0';
    c=getchar();
  }
}
int len,dig[10];
void writeint(int x){
  len=0;
  while(x){
    dig[++len]=x%10;
    x/=10;
  }
  for(int i=len; i; i--)
    putchar(dig[i]+'0');
}
struct Val{
  int h,len;
  const bool operator<(const Val& rhs)const{
    return h<rhs.h;
  }
  Val(int a,int b):h(a),len(b){}
};
int a[N+10],d[N+10],d2[N+10],n,g[N+10];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif
  int T;
  readint(T);
  while(T--){
    readint(n);
    a[0]=INF;
    a[n+1]=-INF;
    For(i,n){
      readint(a[i]);
      if(a[i-1]<a[i])d[i]=d[i-1]+1;
      else d[i]=1;
    }
    for(int i=n; i; i--){
      if(a[i+1]>a[i])d2[i]=d2[i+1]+1;
      else d2[i]=1;
    }
    int ans=0;
    For(i,n)g[i]=INF;
    For(i,n){
      int k=lower_bound(g+1,g+n+1,a[i])-g;
      ans=max(ans,k+d2[i]-1);
      g[d[i]]=min(g[d[i]],a[i]);
    }
    writeint(ans);
    putchar('\n');
  }
  return 0;
}
