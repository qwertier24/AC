#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 5010

using namespace std;

void getfail(char *s,int n,int *fail){
  int k=0;
  fail[1]=0;
  for(int i=2; i<=n; i++){
    while(k&&s[k+1]!=s[i])k=fail[k];
    if(s[k+1]==s[i])k++;
    fail[i]=k;
  }
}
int d[N],fail[N][N];
char s[N];
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  scanf("%s",s+1);
  int n=strlen(s+1);
  For(i,n){
    getfail(s+i-1,n,fail[i]);
    d[i]=d[i-1]+1;
    for(int j=0; j<i; j++)
      if((i-j)%(i-j-fail[j+1][i-j])==0)
	d[i]=min(d[i],d[j]+i-j-fail[j+1][i-j]);
    //printf("%d %d\n",i,d[i]);
  }
  printf("%d",d[n]);
  return 0;
}
