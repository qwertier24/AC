#include<stdio.h>
#include<algorithm>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 1000

typedef long long LL;
using namespace std;

int n,m,deg[N+10],k;
struct Bign{
  int len,num[5010];
  void operator*=(int t){
    int c=0;
    for(int i=1; i<=len||c; i++){
      len=max(len,i);
      num[i]=num[i]*t+c;
      c=num[i]/10;
      num[i]%=10;
    }
  }
  void operator/=(int t){
    for(int i=len; i; i--){
      num[i-1]+=(num[i]%t)*10;
      num[i]/=t;
    }
    while(!num[len]&&len)len--;
  }
  void print(){
    if(len==0)printf("0");
    else for(int i=len; i; i--)
	   printf("%d",num[i]);
    puts("");
  }
}ans;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  For(i,n){
    scanf("%d",&deg[i]);
    if(deg[i]==0){
      printf("0\n");
      return 0;
    }else if(deg[i]>0){
      m+=deg[i]-1;
    }else k++;
  }
  ans.len=1;
  ans.num[1]=1;
  if(m>n-2){
    printf("0\n");
    return 0;
  }
  For(i,m)
    ans*=i;
  For(i,n-2)ans*=i;
  For(i,m)ans/=i;
  For(i,n-2-m)ans/=i;
  For(i,n)if(deg[i]>0)
    For(j,deg[i]-1)
      ans/=j;
  For(i,n-2-m)ans*=k;
  ans.print();
  return 0;
}
