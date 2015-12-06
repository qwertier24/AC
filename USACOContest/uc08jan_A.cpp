#include<stdio.h>
#include<algorithm>
#include<cstring>
#define oo (1<<20)
#define For(i,b,e) for(int i=b; i<=e; i++)
using namespace std;
int g[110][110]={0},rg[110][110],ans=0,n,m,vis[110]={0},mark[110];
void dfs(int u,int G[][110]){
    vis[u]=1;
    mark[u]=1;
    int cnt=0,mark;
    For(i,1,n)
        if(G[u][i]&&!vis[i])
            dfs(i,G);
}
bool check(int u){
    memset(mark,0,sizeof(mark));
    memset(vis,0,sizeof(vis));
    dfs(u,g);
    memset(vis,0,sizeof(vis));
    dfs(u,rg);
    For(i,1,n)
        if(!mark[i])
            return false;
    return true;
}
int main(){
    //freopen("prob.in","r",stdin);
    scanf("%d%d",&n,&m);
    For(i,1,m){
        int f,t;
        scanf("%d%d",&f,&t);
        g[f][t]=1;
        rg[t][f]=1;
    }
    For(i,1,n)
        if(check(i))
            ans++;
    printf("%d",ans);
    return 0;
}
