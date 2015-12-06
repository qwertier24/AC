#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

typedef long long LL;
using namespace std;
#define N 1000010

int ch[N][2],sz;
vector<pair<int,int> > pos[N];
void insert(char *s,int i,int j){
  int u=0;
  while(*s){
    int c=(*s++)-'0';
    if(!ch[u][c]){
      ch[u][c]=++sz;
      pos[sz].clear();
    }
    u=ch[u][c];
  }
  pos[u].push_back(make_pair(i,j));
}

int fa[N];
int q[N],fr,rr;
void calc_fa(){
  rr=-1,fr=0;
  REP(i,0,1)if(ch[0][i])
    q[++rr]=ch[0][i];
  while(fr<=rr){
    int &r=q[fr++];
    REP(i,0,1){
      int &u=ch[r][i];
      if(!u){
        u=ch[fa[r]][i];
        continue;
      }
      fa[u]=ch[fa[r]][i];
      q[++rr]=u;
      REP(i,0,int(pos[fa[u]].size())-1)
        pos[u].push_back(pos[fa[u]][i]);
    }
  }
}


int n,m,r,c,Q,cnt[11][1010][1010];
char S[1010][1010],str[1010];
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  scanf("%d%d%d%d",&n,&m,&r,&c);
  REP(i,0,n-1)
    scanf("%s",S[i]);
  scanf("%d",&Q);
  REP(i,1,Q){
    REP(j,0,r-1){
      scanf("%s",str);
      insert(str,i,j);
    }
  }
  calc_fa();
  REP(x,0,n-1){
    int u=0;
    REP(y,0,m-1){
      u=ch[u][S[x][y]-'0'];
      REP(i,0,int(pos[u].size())-1)
        if(x>=pos[u][i].second)
          cnt[pos[u][i].first][x-pos[u][i].second][y-c+1]++;
    }
  }
  REP(i,1,Q){
    int flag=0;
    REP(j,0,n-1)REP(k,0,m-1)if(cnt[i][j][k]==r)flag=1;
    printf("%d\n",flag);
  }
  return 0;
}
