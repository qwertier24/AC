#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 510
#define M 500010

int le[N],pe[M], ev[M], et[M], ew[M],ecnt;
void addEdge(int u, int v, int w, int t){
    ecnt++;
    pe[ecnt] = le[u];
    le[u] = ecnt;
    ev[ecnt] = v;
    ew[ecnt] = w;
    et[ecnt] = t;
}

int inq[N], fr, rr, pre[N];
pii dis[N];
vector<int> getans(int s, int t){
    memset(dis, 0x3f, sizeof(dis));
    memset(inq, 0, sizeof(inq));
    queue<int> q;
    q.push(s);
    dis[s] = MP(0,0);
    pre[s] = -1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        //printf("%d\n",u);
        inq[u] = 0;
        for(int i = le[u]; i; i=pe[i]){
            int &v = ev[i];
            if(dis[v] > MP(dis[u].first+et[i], dis[u].second+ew[i])){
                dis[v] = MP(dis[u].first+et[i], dis[u].second+ew[i]);
                pre[v] = u;
                if(!inq[v]){
                    inq[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    int u = t;
    vector<int> ret;
    ret.push_back(dis[u].first);
    while(u>=0){
        ret.push_back(u);
        u = pre[u];
    }
    reverse(ret.begin()+1, ret.end());
    return ret;
}
bool eqaul(vector<int> &v1, vector<int> &v2){
    if(v1.size() != v2.size())
        return false;
    FOR(i, v1.size()-1)
        if(v1[i] != v2[i])
            return false;
    return true;
}
int main(){
#ifdef QWERTIER
  freopen("in.txt","r",stdin);
#endif 
  int n, m;
  scanf("%d%d",&n,&m);
  FOR(i,m){
      int u,v,one,w1,w2;
      scanf("%d%d%d%d%d",&u,&v,&one,&w1,&w2);
      addEdge(u,v,w1,w2);
      if(!one){
          addEdge(v,u,w1,w2);
      }
  }
  int s,t;

  scanf("%d%d",&s,&t);
  vector<int> ans1 = getans(s,t);

  FOR(i,ecnt){
      swap(ew[i], et[i]);
      ew[i] = 1;
  }
  vector<int> ans2 = getans(s,t);

  if(eqaul(ans1,ans2)){
      printf("Time = %d; Distance = %d: ", ans1[0], ans2[0]);
      FOR(i,ans1.size()-1)
          printf("%s%d",i==1?"":" => ",ans1[i]);
  }else{
      printf("Time = %d: ", ans1[0]);
      FOR(i,ans1.size()-1)
          printf("%s%d",i==1?"":" => ",ans1[i]);
      puts("");
      printf("Distance = %d: ", ans2[0]);
      FOR(i,ans2.size()-1)
          printf("%s%d",i==1?"":" => ",ans2[i]);
  }
  return 0;
}
