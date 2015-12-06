#include<stdio.h>
#include<algorithm>
#include<string.h>
#define INF (1<<29)
#define PROB "partition"
#define For(i,n) for(int i=1; i<=n; i++)
#define N 15

using namespace std;

int sum[N+10][N+10],sumt[N+10][N+10],max_sum[N+10][N+10],block,n,K,g[N+10][N+10];

bool check(int min_sum,int rem){
  int last_col=1;
  for(int i=1; i<=n; i++){
    //printf("%d %d %d\n",last_col,i,max_sum[last_col][i]);
    if(max_sum[i][i]>min_sum)return false;
    if(max_sum[last_col][i]>min_sum){
      last_col=i;
      rem--;
    }
  }
  return rem>=0;
}

int calc(int s){
  memset(sumt,0,sizeof(sumt));
  memset(max_sum,0,sizeof(max_sum));
  block=0;
  int last_row=1;
  For(i,n)if((s>>i-1)&1){
    block++;
    for(int j=last_row; j<=i; j++)
      For(k,n)
	sumt[block][k]+=sum[j][k];
    last_row=i+1;
  }
  //printf("last_row:%d\n",last_row);
  block++;
  for(int i=last_row; i<=n; i++)
    For(j,n)
      sumt[block][j]+=sum[i][j];
  //printf("%o %d\n",s,block);
  For(l,n)for(int r=l; r<=n; r++){
    For(i,block)
      max_sum[l][r]=max(max_sum[l][r],sumt[i][r]-sumt[i][l-1]);
    //printf("%d %d %d\n",l,r,max_sum[l][r]);
  }
  if(block>K+1)return INF;
  int l=0,r=1000000;
  while(l<r){
    int m=(l+r)>>1;
    if(check(m,K-block+1))r=m;
    else l=m+1;
  }
  //printf("l:%d\n",l);
  return l;
}

int main(){
#ifndef ONLINE_JUDGE
  //freopen("in.txt","r",stdin);
#endif 
  freopen(PROB".in","r",stdin);
  freopen(PROB".out","w",stdout);
  scanf("%d%d",&n,&K);
  For(i,n)For(j,n)scanf("%d",&g[i][j]);
  For(i,n){
    For(j,n)
      sum[i][j]=sum[i][j-1]+g[i][j];
  }
  int ans=INF;
  for(int s=0; s<(1<<n-1); s++)
    ans=min(ans,calc(s));
  printf("%d",ans);
  return 0;

}
