#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#define PROB "epidemic"
using namespace std;
int n,ans=1<<30,rem=1,e[310][310],d[310];
void dfs(int u,int f){
	for(int i=1; i<=e[u][0]; i++){
		if(e[u][i]==f)
			e[u][i]=0;
		else
			dfs(e[u][i],u);
	}
}
void search(int depth){
	//printf("%d %d\n",depth,e[1][0]);
	if(rem>=ans)return;
	bool found=false;
	int t=rem;
	for(int i=1; i<=n; i++)
		if(d[i]==depth)
			for(int j=1; j<=e[i][0]; j++)
				if(e[i][j])
					d[e[i][j]]=depth+1,rem++,found=true;
	if(!found){ans=rem;return;}
	rem--;
	for(int i=1; i<=n; i++)
		if(d[i]==depth+1){
			d[i]=-1;
			search(depth+1);
			d[i]=depth+1;
		}
	for(int i=1; i<=n; i++)
		if(d[i]==depth+1)
			d[i]=-1;
	rem=t;
}
int main(){
	freopen(PROB".in","r",stdin);
	//freopen(PROB".out","w",stdout);
	int u,v,p;
	scanf("%d%d",&n,&p);
	for(int i=1; i<=p; i++){
		scanf("%d%d",&u,&v);
		e[u][++e[u][0]]=v;
		e[v][++e[v][0]]=u;;
	}
	memset(d,-1,sizeof(d));
	d[1]=0;
	dfs(1,0);
	search(0);
	printf("%d",ans);
	return 0;
}

