#include<stdio.h>
#include<algorithm>
#define M 1000
#define N 10000
#define INF (1<<29)
#define PROB "necklace"

using namespace std;

int fail[M+10];
char s1[N+10],s2[M+10];
int a[N+10];
void get_fail(char* s,int len){
  fail[1]=0;
  a[1]=s[1]-'a';
  for(int i=2; i<=len; i++){
    a[i]=s[i]-'a';
    int j=fail[i-1];
    while(j&&a[j+1]!=a[i])
      j=fail[j];
    if(a[j+1]==a[i])
      j++;
    fail[i]=j;
    //printf("%d %d\n",i,fail[i]);
  }
}
int d[N+10][M+10],prefix[M+10][26],n,m;
int main(){
  freopen(PROB".in","r",stdin);
  freopen(PROB".out","w",stdout);
  scanf("%s%s",s1+1,s2+1);
  n=strlen(s1+1);
  m=strlen(s2+1);
  get_fail(s2,m);
  for(int i=0; i<=m; i++)
    for(int j=0; j<26; j++){
      int k=i;
      while(k&&a[k+1]!=j)
	k=fail[k];
      if(a[k+1]!=j)prefix[i][j]=0;
      else prefix[i][j]=k+1;
      //printf("%d %d %d %d %d\n",i,j,prefix[i][j],k,a[i]);
    }
  for(int i=1; i<=n; i++)
    a[i]=s1[i]-'a';
  for(int i=1; i<=n; i++)
    for(int j=0; j<=m; j++)
      d[i][j]=INF;
  d[1][0]=prefix[0][a[1]];
  d[1][1]=d[1][0]?0:INF;
  for(int i=1; i<n; i++)
    for(int j=0; j<m; j++)
      if(d[i][j]<INF){
	d[i+1][j]=min(d[i+1][j],d[i][j]+1);
	d[i+1][prefix[j][a[i+1]]]=min(d[i+1][prefix[j][a[i+1]]],d[i][j]);
	//printf("%d %d %d\n",i,j,d[i][j]);
      }
  int ans=INF;
  for(int i=0; i<m; i++)
    ans=min(ans,d[n][i]);
  printf("%d",ans);
  return 0;

}
