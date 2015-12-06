#include<stdio.h>
#include<string.h>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

using namespace std;
#define N 51

int n;
int d[N][N];
char s[N+1];
int main(){
  scanf("%s",s+1);
  n=strlen(s+1);
  REP(i,1,n)d[i][i]=1;
  RREP(i,n,1)REP(j,i+1,n){
    d[i][j]=d[i+1][j]+1;
    REP(k,i+1,j)
      if(s[i]==s[k])
        if(d[i][j]>d[i+1][k]+d[k+1][j])
          d[i][j]=d[i+1][k]+d[k+1][j];
  }
  printf("%d\n",d[1][n]);
  return 0;
}
