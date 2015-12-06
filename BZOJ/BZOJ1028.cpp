#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

using namespace std;

int ori[410],cur[410],n,m;
bool check(){
  For(j,n)if(ori[j]>=2){
    int flag=1;
    memcpy(cur,ori,sizeof(cur));
    cur[j]-=2;
    For(k,n){
      cur[k]%=3;
      if(k+2<=n){
	if(cur[k+1]<cur[k]||cur[k+2]<cur[k]){
	  flag=0;
	  break;
	}else
	  cur[k+1]-=cur[k],cur[k+2]-=cur[k],cur[k]=0;
      }else if(cur[k]){
	flag=0;
	break;
      }
    }
    if(flag)return true;
  }
  return false;
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%d%d",&n,&m);
  For(i,m*3+1){
    int t;
    scanf("%d",&t);
    ori[t]++;
  }
  int first=1;
  For(i,n){
    ori[i]++;
    if(check()){
      printf("%s%d",first?"":" ",i);
      first=0;
    }
    ori[i]--;
  }
  if(first)printf("NO");
  return 0;
}
