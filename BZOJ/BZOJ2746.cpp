#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<stack>
#define REP(i,n) for(int i=0; i<n; i++)

using namespace std;

char buff[11000010],*cur=buff;
void readstr(char* &s){
  char c=getchar();
  while(c>'z' || c<'a')c=getchar();
  while('a'<=c && c<='z'){
    *(s++)=c;
    c=getchar();
  }
  *(s++)=0;
}
void readint(int &x){
  x=0;
  char c=getchar();
  while(c>'9' || c<'0')c=getchar();
  while('0'<=c && c<='9'){
    x=x*10+c-'0';
    c=getchar();
  }
}

#define N 1000010
#define MOD 1000000007

int le[N],ev[N],ecnt,pe[N];
void addEdge(int u,int v){
  ecnt++;
  pe[ecnt]=le[u];
  le[u]=ecnt;
  ev[ecnt]=v;
}
int lq[N],qv[N<<1],qcnt,pq[N<<1],qi[N<<1];
void addQuery(int u,int v,int i){
  qcnt++;
  pq[qcnt]=lq[u];
  lq[u]=qcnt;
  qv[qcnt]=v;
  qi[qcnt]=i;
}

int ch[N][26],sz,val[N],id[11000010];
void insert(char *s){
  int u=0,tmp=0;
  while(*s){
    int c=*s-'a';
    tmp=(tmp*26ll+c)%MOD;
    if(!ch[u][c])
      ch[u][c]=++sz;
    u=ch[u][c];
      val[u]=tmp;
    id[s-buff]=u;
    //printf("%c %d\n",*s,u);
    s++;
  }
}
int fail[N],q[N],fr,rr;
void calc_fa(){
  fr=0,rr=-1;
  REP(i,26)if(ch[0][i]){
    q[++rr]=ch[0][i];
    addEdge(0,ch[0][i]);
  }
  while(fr<=rr){
    int &r=q[fr++];
    REP(i,26){
      int &u=ch[r][i];
      if(!u){u=ch[fail[r]][i];continue;}
      fail[u]=ch[fail[r]][i];
      addEdge(fail[u],u);
      q[++rr]=u;
    }
  }
}

int vis[N],pa[N],ans[N];
int findset(int u){
  if(pa[u]!=u)pa[u]=findset(pa[u]);
  return pa[u];
}
void dfs(int s){
  stack<int> st;
  st.push(s);
  while(!st.empty()){
    int u=st.top();
    if(!vis[u]){
      vis[u]=1;
      for(int i=le[u]; i; i=pe[i])
        if(ev[i]!=fail[u])
          st.push(ev[i]);
    }else{
      st.pop();
      for(int i=lq[u]; i; i=pq[i])
        if(vis[qv[i]])
          ans[qi[i]]=findset(qv[i]);
      pa[u]=fail[u];
    }
  }
}

int n,m,a,b,c,d;
char *str[N];
int main(){
#ifdef QWERTIER
  freopen("in","r",stdin);
#endif
  //printf("%lld\n",sizeof(id));
  scanf("%d",&n);
  REP(i,n){
    str[i]=cur;
    readstr(cur);
    insert(str[i]);
  }
  calc_fa();
  scanf("%d",&m);
  REP(i,m){
    readint(a);readint(b);readint(c);readint(d);
    a--,b--,c--,d--;
    addQuery(id[str[a]+b-buff],id[str[c]+d-buff],i);
    addQuery(id[str[c]+d-buff],id[str[a]+b-buff],i);
  }
  REP(i,sz+1)pa[i]=i;
  dfs(0);
  REP(i,m)printf("%d\n",val[ans[i]]);
  return 0;
}
