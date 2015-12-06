#include <stdio.h>
#include <algorithm>
#include <map>
#define INF (1<<30)
#define X first
#define Y second
using namespace std;
int n,x[50010],y[50010],addx[4]={0,0,-1,1},addy[4]={1,-1,0,0};
map<pair<int,int>,int> mp;
map<pair<int,int>,int> cow,vis;
int dfs(int xt,int yt){
	int ret=0;
	vis[make_pair(xt,yt)]=1;
	for(int i=0; i<4; i++)
		if(mp.count(make_pair(xt+addx[i],yt+addy[i])))
			if(!vis.count(make_pair(xt+addx[i],yt+addy[i])))
				ret+=dfs(xt+addx[i],yt+addy[i]);
	return ret+1;
}
int main(){
	freopen("perimeter.in","r",stdin);
	//freopen("perimeter.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d%d",&x[i],&y[i]);
		cow[make_pair(x[i],y[i])]=1;
	}
	for(int i=1; i<=n; i++)
		for(int j=0; j<4; j++)
			if(!cow.count(make_pair(x[i]+addx[j],y[i]+addy[j])))
				mp[make_pair(x[i]+addx[j],y[i]+addy[j])]=1;
	int num=dfs((mp.begin()->first).X,(mp.begin()->first).Y);
	printf("%d\n",(int)mp.size());
	return 0;
}
