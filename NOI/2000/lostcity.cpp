#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
#define N 1
#define V 2
#define A 4

using namespace std;

int ch[1000*30][26],sz,val[1000*30];
void insert(char *s,int type){
  int u=0;
  while(*s){
    int c=*(s++)-'a';
    if(!ch[u][c])
      ch[u][c]=++sz;
    u=ch[u][c];
  }
  val[u]|=type;
}
int get_type(char c){
  if(c=='n')return N;
  else if(c=='v')return V;
  else return A;
}
struct MP{
  int a,b;
  MP(int _a=0,int _b=0):a(_a),b(_b){}
  MP operator+(const MP& r){return MP(a+r.a,b+r.b);}
  const bool operator<(const MP& r)const{return a<r.a||(a==r.a&&b<r.b);}
}dp[1000*30][8];
inline void update(MP& a,MP b){
  if(b<a)a=b;
}
void calc(char *s,int pos){
  int u=0,cur=pos;
  while(*s!='.'){
    u=ch[u][*(s++)-'a'];
    cur++;
    if(!u)return;
    if(val[u]&N)
      update(dp[cur][N],min(min(dp[pos][N]+MP(1,1),dp[pos][V]+MP(0,1)),min(dp[pos][A|V]+MP(0,1),dp[pos][A|N]+MP(1,1))));
    if(val[u]&V)
      update(dp[cur][V],min(dp[pos][N]+MP(0,1),dp[pos][A|N]+MP(0,1)));
    if(val[u]&A){
      update(dp[cur][A|V],min(dp[pos][A|V]+MP(0,1),dp[pos][V]+MP(0,1)));
      update(dp[cur][A|N],min(dp[pos][A|N]+MP(0,1),dp[pos][N]+MP(0,1)));
    }
    //printf("cur:%d %c N:%d %d V:%d %d A&N:%d %d A&V:%d %d\n",cur,*(s-1),dp[cur][N].a,dp[cur][N].b,dp[cur][V].a,dp[cur][V].b,dp[pos][A&N].a,dp[pos][A&N].b,dp[cur][A&V].a,dp[cur][A&V].b);
  }
}

int n;
char str[6010];
int main(){
  freopen("lostcity.in","r",stdin);
  freopen("lostcity.out","w",stdout);
  scanf("%d",&n);
  REP(i,1,n){
    scanf("%s",str);
    insert(str+2,get_type(str[0]));
  }
  scanf("%s",str+1);
  n=strlen(str+1)-1;
  memset(dp,0x3f,sizeof(dp));
  dp[0][A|V]=MP(1,0);
  REP(i,0,n-1){
    calc(str+i+1,i);
  }
  MP ans=min(dp[n][N],dp[n][V]);
  printf("%d\n%d",ans.a,ans.b);
  return 0;
}
