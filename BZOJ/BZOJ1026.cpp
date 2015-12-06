#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<math.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define MAXD 10

using namespace std;

int d[MAXD+10][10],p10[MAXD+10]={1,1e1,1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9},sum[MAXD+10];
void init(){
  Rep(i,10)d[1][i]=1;
  For(i,MAXD)Rep(j,10)Rep(k,10)
    if(abs(k-j)>=2)
      d[i][j]+=d[i-1][k];
  For(i,10){
    For(j,9){
      sum[i]+=d[i][j];
      //printf("%d %d %d\n",i,j,d[i][j]);
    }
    sum[i]+=sum[i-1];
    //printf("sum %d %d\n",i,sum[i]);
  }
}
int cnt(int num){
  if(!num)return 0;
  int dig=int(log10(num))+1;
  int ret=sum[dig-1];
  int lastd=-1,curd;
  int flag=1;
  for(int i=dig; i&&flag; --i){
    int curd=num/p10[i-1];
    num%=p10[i-1];
    //printf("%d cur:%d\n",i,curd);
    if(flag)
      Rep(j,curd)
	if(abs(j-lastd)>=2){
	  ret+=d[i][j];
	  //printf("%d %d %d\n",i,j,d[i][j]);
	}
    if(abs(curd-lastd)<2)flag=0;
    lastd=curd;
  }  
  return ret+flag;
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  init();
  int l,r;
  scanf("%d%d",&l,&r);
  printf("%d\n",cnt(r)-cnt(l-1));
  return 0;
}
