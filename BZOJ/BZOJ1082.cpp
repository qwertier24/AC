#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 1010

using namespace std;
typedef long long LL;

int n,m,a[N],b[N];

int flag,mid,suma[N],sumb[N],mark[N];
void dfs(int curm,int lastp,int remm){
  if(curm<=0){
    flag=1;
    return;
  }
  int sumt=0;
  For(i,n)if(a[i]>=b[1])sumt+=a[i];
  if(remm>sumt)return;
  int st=(b[curm+1]==b[curm]?lastp:1);
  For(i,n)if(a[i]>=b[curm]){
    a[i]-=b[curm];
    dfs(curm-1,i,remm-b[curm]);
    a[i]+=b[curm];
    if(flag)return;
  }
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d",&n);
  For(i,n)scanf("%d",&a[i]);
  sort(a+1,a+n+1);
  For(i,n)suma[i]=suma[i-1]+a[i];

  scanf("%d",&m);
  For(i,m)scanf("%d",&b[i]);
  sort(b+1,b+m+1);
  For(i,m)sumb[i]=sumb[i-1]+b[i];

  int l=0,r=m;
  while(l<r){
    memset(mark,0,sizeof(mark));
    mid=1+((l+r-1)>>1);
    flag=0;
    dfs(mid,1,sumb[mid]);
    if(flag==1)l=mid;
    else r=mid-1;
  }
  printf("%d",l);
  return 0;
}
