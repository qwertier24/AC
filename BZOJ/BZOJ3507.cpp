#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
#define INF (1<<30)

using namespace std;
#define N 100030

int cnt[N],ch[N][26],sz,fa[N];
vector<int> pos[N];
int fr,rr,q[N];
struct OPT{
  char str[N];
  int n,len,root;
  void insert(char *s,int &i){
    int u=root;
    while(*s && *s!='?'){
      int c=*(s++)-'a';
      if(!ch[u][c])
        ch[u][c]=++sz;
      u=ch[u][c];
      ++i;
    }
    pos[u].push_back(i-1);
  }
  void calc_fa(){
    fr=0,rr=-1;
    REP(i,0,25){
      if(ch[root][i]){
        q[++rr]=ch[root][i];
        fa[ch[root][i]]=root;
      }else
        ch[root][i]=root;
    }
    while(fr<=rr){
      int r=q[fr++];
      REP(i,0,25){
        if(!ch[r][i]){
          ch[r][i]=ch[fa[r]][i];
          continue;
        }
        int u=ch[r][i];
        fa[u]=ch[fa[r]][i];
        REP(i,0,int(pos[fa[u]].size()-1))
          pos[u].push_back(pos[fa[u]][i]);
        q[++rr]=u;
      }
    }
  }
  void init(){
    int lpos=0;
    root=++sz;
    REP(i,0,len-1){
      if(str[i]>='a' && str[i]<='z'){
        insert(str+i,i);
        n++;
      }
    }
    calc_fa();
  }
  int find(char *s,int m){
    if(len==0)return 0;
    int u=root;
    memset(cnt,0,sizeof(cnt));
    REP(i,0,m-1){
      u=ch[u][s[i]-'a'];
      REP(j,0,int(pos[u].size())-1)
        if(i>=pos[u][j])
          cnt[i-pos[u][j]]++;
    }
    REP(i,0,m-1)
      if(cnt[i]==n)
        return i;
    return 1<<29;
  }
}opt[20];
int optn;

char wild[N];
int n;
void split(){
  int lpos=0;
  if(wild[0]=='*')
    optn++;
  REP(i,0,n){
    if(!wild[i] || wild[i]=='*'){
      if(lpos<=i-1){
        strncpy(opt[optn].str,wild+lpos,i-lpos);
        opt[optn].len=i-lpos;
        opt[optn].init();
        optn++;
      }
      lpos=i+1;
    }
  }
  if(wild[n-1]=='*')
    optn++;
}

bool check(char *str,int m){
  for(int i=0; i<opt[0].len; i++)
    if(!str[i] || (str[i]!=opt[0].str[i] && opt[0].str[i]!='?'))
      return false;
  str+=opt[0].len;
  m-=opt[0].len;
  
  if(optn==1)return true;
  
  if(m<opt[optn-1].len)return false;
  m-=opt[optn-1].len;
  for(int i=0; i<opt[optn-1].len; i++)
    if(str[m+i]!=opt[optn-1].str[i] && opt[optn-1].str[i]!='?')
      return false;
  
  str[m]=0;
  for(int i=1; i<optn-1; i++){
    int step=opt[i].find(str,m);
    if(step+opt[i].len>m){
      return false;
    }
    str+=step+opt[i].len;
    m-=step+opt[i].len;
  }
  return true;
}

int Q;
char str[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  scanf("%s",wild);
  n=strlen(wild);
  split();
  scanf("%d",&Q);
  while(Q--){
    scanf("%s",str);
    puts(check(str,strlen(str))?"YES":"NO");
  }
  return 0;
}
