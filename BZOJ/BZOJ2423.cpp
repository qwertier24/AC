#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<ctype.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define N 5010
#define MOD 100000000
#define CLR(x) memset(x,0,sizeof(x))

typedef long long LL;
using namespace std;

void readstr(char *s,int &len){
  len=0;
  char c=getchar();
  while(!isalpha(c))c=getchar();
  while(c!='.'){
    s[++len]=c;
    c=getchar();
  }
}
void add(int& x,int dx){
  x+=dx;
  if(x<0)x+=MOD;
  if(x>=MOD)x-=MOD;
}
int d1[2][N],d2[2][N];
char s1[N],s2[N];
int n2,n1;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in","r",stdin);
#endif
  readstr(s1,n1);
  readstr(s2,n2);

  int cur=0,last=1;
  Rep(i,n2+1)
    d2[cur][i]=1;
  For(i,n1){
    cur^=1,last^=1;
    CLR(d1[cur]);
    CLR(d2[cur]);
    d2[cur][0]=1;
    For(j,n2){
      if(s1[i]==s2[j])
	d1[cur][j]=d1[last][j-1]+1;
      else
	d1[cur][j]=max(d1[last][j],d1[cur][j-1]);
      if(s1[i]==s2[j])
	d2[cur][j]=d2[last][j-1];
      if(d1[last][j]==d1[cur][j])
	add(d2[cur][j],d2[last][j]);
      if(d1[cur][j-1]==d1[cur][j])
	add(d2[cur][j],d2[cur][j-1]);
      if(d1[cur][j]==d1[last][j-1])
	add(d2[cur][j],-d2[last][j-1]);
    }
  }
  printf("%d\n%d\n",d1[cur][n2],d2[cur][n2]);
  return 0;
}
