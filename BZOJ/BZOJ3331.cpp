#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<stack>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define MP make_pair
#define fi first
#define se second

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define N 200010 

int n,m;

vector<int> bcc[N];
int bcc_cnt;

int le[N],ev[N<<1],pe[N<<1],ecnt;
void addEdge(int u,int v){
	ecnt++;
	pe[ecnt]=le[u];
	le[u]=ecnt;
	ev[ecnt]=v;
}


int iscut[N],bccno[N],pre[N],low[N],dfs_clock;
stack<pii> st;
void find_bcc(int u,int fa){
	low[u]=pre[u]=++dfs_clock;
	int child=0;
	for(int i=le[u]; i; i=pe[i]){
		int &v=ev[i];
		if(!pre[v]){
			child++;
			st.push(MP(u,v));
			find_bcc(v,u);
			low[u]=min(low[u],low[v]);
			if(low[v]>=pre[u]){
				iscut[u]=1;
				bcc_cnt++;
				while(true){
					pii cur=st.top();st.pop();
					if(bccno[cur.fi]!=bcc_cnt){
						bccno[cur.fi]=bcc_cnt;
						bcc[bcc_cnt].push_back(cur.fi);
					}
					if(bccno[cur.se]!=bcc_cnt){
						bccno[cur.se]=bcc_cnt;
						bcc[bcc_cnt].push_back(cur.se);
					}
					if(cur.fi==u && cur.se==v)break;
				}
			}
		}else if(pre[v]<pre[u] && v!=fa){
			st.push(MP(u,v));
			low[u]=min(low[u],pre[v]);
		}
	}
	if(!fa && child==1)iscut[u]=0;
}

#define LOG 18
int tp[N][LOG],fa[N],dep[N];
void dfs(int u){
	pre[u]=1;
	tp[u][0]=fa[u];
	for(int i=1; i<LOG; i++)
		tp[u][i]=tp[tp[u][i-1]][i-1];
	for(int i=le[u]; i; i=pe[i]){
		int &v=ev[i];
		if(v==fa[u])continue;
		fa[v]=u;
		dep[v]=dep[u]+1;
		dfs(v);
	}
}
int lca(int u,int v){
	int ut=u,vt=v;
	if(dep[u]<dep[v])swap(u,v);
	int gap=dep[u]-dep[v];
	for(int i=0; i<LOG; i++){
		if(gap&1)
			u=tp[u][i];
		gap>>=1;
	}
	if(u==v)return u;
	for(int i=LOG-1; i>=0; i--){
		if(tp[u][i]!=tp[v][i])
			u=tp[u][i],v=tp[v][i];
	}
	return fa[u];
}

int ans[N];
void calc_ans(int u){
	pre[u]=1;
	for(int i=le[u]; i; i=pe[i]){
		int &v=ev[i];
		if(v==fa[u])continue;
		calc_ans(v);
		ans[u]+=ans[v];
	}
}

int q;
int main(){
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
#endif 
  scanf("%d%d%d",&n,&m,&q);
  while(m--){
  	int u,v;
  	scanf("%d%d",&u,&v);
  	addEdge(u,v);
  	addEdge(v,u);
  }
  For(i,n)if(!pre[i]){
  	find_bcc(i,0);
  }
  ecnt=0;
  memset(le,0,sizeof(le));
  For(i,bcc_cnt){
  	Rep(j,bcc[i].size())
  		if(iscut[bcc[i][j]]){
  			addEdge(i+n,bcc[i][j]);
  			addEdge(bcc[i][j],i+n);
  		}
  }
  memset(pre,0,sizeof(pre));
  For(i,n)if(iscut[i] && !pre[i])dfs(i);
  For(i,bcc_cnt)if(!pre[n+i])dfs(n+i);
  while(q--){
  	int u,v;
  	scanf("%d%d",&u,&v);
  	if(!iscut[u]){
  		ans[u]++;
  		u=bccno[u]+n;
  	}
  	if(!iscut[v]){
  		ans[v]++;
  		v=bccno[v]+n;
  	}
  	int a=lca(u,v);
  	ans[u]++;
  	ans[v]++;
  	ans[a]--;
  	ans[fa[a]]--;
  }
  memset(pre,0,sizeof(pre));
  For(i,n)if(iscut[i] && !pre[i])calc_ans(i);
  For(i,n)printf("%d\n",ans[i]);
  return 0;
}
