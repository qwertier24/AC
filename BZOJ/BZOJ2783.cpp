#include<stdio.h>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define N 100010

int le[N],ev[N<<1],pe[N<<1],ecnt;
void addEdge(int u,int v){
	ecnt++;
	pe[ecnt]=le[u];
	le[u]=ecnt;
	ev[ecnt]=v;
}

int root,mark[N];
#define LOG 17
int top[N][LOG],sum[N][LOG];
int n,s,a[N],q[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&s);
	REP(i,1,n)scanf("%d",&a[i]);
	REP(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u,v);
		mark[v]=1;
	}
	REP(i,1,n)if(!mark[i])root=i;
	
	int fr=0,rr=-1;
	q[++rr]=root;
	int ans=0;
	while(fr<=rr){
		int &u=q[fr++];
		sum[u][0]=a[u];
		for(int i=1; i<LOG; i++){
			top[u][i]=top[top[u][i-1]][i-1];
			sum[u][i]=sum[u][i-1]+sum[top[u][i-1]][i-1];
			//printf("%d %d %d\n",u,i,sum[u][i]);
		}
		for(int i=le[u]; i; i=pe[i]){
			int &v=ev[i];
			//printf("%d %d\n",u,v);
			q[++rr]=v;
			top[v][0]=u;
		}
		int pre=0;
		for(int i=LOG-1; i>=0; i--)
			if(pre+sum[u][i]<=s){
				pre+=sum[u][i];
				u=top[u][i];
			}
		ans+=pre==s;
	}
	printf("%d\n",ans);
	return 0;
}
