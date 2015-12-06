#include <stdio.h>
#include <algorithm>
#include <stack>
#define PROB "twostack"
using namespace std;
int last_edge[1010]={0},ecnt=0,pre[1000010],edge[1000010],color[1010],vis[1010],n,m,a[1010],min_a[1010];
void addEdge(int u,int v){
	ecnt++;
	edge[ecnt]=v;
	pre[ecnt]=last_edge[u];
	last_edge[u]=ecnt;
}
bool dfs(int u){
	vis[u]=1;
	for(int i=last_edge[u]; i; i=pre[i]){
		int v=edge[i];
		if(vis[v]){
			if(color[v]==color[u])
				return false;
		}else if(!vis[v]){
			color[v]=1^color[u];
			if(!dfs(v))return false;
		}
	}
	return true;
}
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	min_a[n]=a[n];
	for(int i=n-1; i>=1; i--)
		min_a[i]=min(a[i],min_a[i+1]);
	for(int i=1; i<=n; i++)
		for(int j=i+1; j<n; j++)
			if(a[i]<a[j]&&min_a[j+1]<a[i]){
				addEdge(i,j);
				addEdge(j,i);
			}
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			color[i]=0;
			if(!dfs(i)){
				printf("0\n");
				return 0;
			}
		}
	}
	int next_n=1,pa=1;
	stack<int> st1,st2;
	for(int i=1; i<=n*2; i++){
		if(st1.size()&&st1.top()==next_n){
			st1.pop();
			printf("b ");
			next_n++;
		}else if(st2.size()&&st2.top()==next_n){
			st2.pop();
			printf("d ");
			next_n++;
		}else if(color[pa]==0){
			st1.push(a[pa]);
			printf("a ");
			pa++;
		}else{
			st2.push(a[pa]);
			printf("c ");
			pa++;
		}
	}
	return 0;
}
