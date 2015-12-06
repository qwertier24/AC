#include<stdio.h>
#include<algorithm>
#include<string.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)

typedef long long LL;
using namespace std;

int num[20],mod,fact[20],p10[20],n,d[1<<10][1<<10],cnt[20];
char s[20];
void init(){
  fact[0]=1;
  For(i,10)fact[i]=fact[i-1]*i;
}
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
#endif 
  init();
  int T;
  scanf("%d",&T);
  while(T--){
    scanf("%s%d",s,&mod);
    memset(cnt,0,sizeof(cnt));
    memset(d,0,sizeof(d));
    p10[0]=1;
    For(i,9)p10[i]=(p10[i-1]*10)%mod;
    n=strlen(s);
    Rep(i,n){
      num[i]=s[i]-'0';
      cnt[num[i]]++;
    }
    Rep(S,1<<n){
      int i=-1;
      Rep(j,n)
	if((S>>j)&1)
	  i++;
      if(i==-1){
	d[S][0]=1;
	continue;
      }
      Rep(j,n)
	if((S>>j)&1)
	  Rep(k,mod)
	    d[S][(k+num[i]*p10[j])%mod]+=d[S^(1<<j)][k];
    }
    int S=(1<<n)-1;
    Rep(i,10)d[S][0]/=fact[cnt[i]];
    printf("%d\n",d[S][0]);
  }
  return 0;
}
