#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <queue>
#define PROB "invite"
#define dbg if(0)
using namespace std;

typedef pair<int,int> Node;
#define cnt first
#define gord second

vector<int> group[250010],inside[1000010];
int cur_cnt[250010],cn,gn,done[1000010]={0};
priority_queue<Node> pq;
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d%d",&cn,&gn);
	for(int i=1; i<=gn; i++){
		int t,t1;
		scanf("%d",&t);
		bool flag=false;
		while(t--){
			scanf("%d",&t1);
			if(t1==1)flag=true;
			group[i].push_back(t1);
			inside[t1].push_back(i);
		}
		if(!flag)
			cur_cnt[i]=-(int)group[i].size()+1;
		else
			cur_cnt[i]=-(int)group[i].size()+2;
		pq.push(Node(cur_cnt[i],i));
dbg		printf("%d %d\n",i,cur_cnt[i]);
	}
	int ans=1;
	done[1]=1;
	while(!pq.empty()&&pq.top().cnt>=0){
		Node t=pq.top();
		pq.pop();
dbg		printf("%d %d\n",t.gord,t.cnt);
		int cur_g=t.gord;
		for(int i=0; i<group[cur_g].size(); i++){
			int cur_cow=group[cur_g][i];
			if(!done[cur_cow]){
				done[cur_cow]=1;
				ans++;
dbg				printf("%d\n",cur_cow);
				for(int j=0; j<inside[cur_cow].size(); j++)
					if(cur_cnt[inside[cur_cow][j]]<0){
						cur_cnt[inside[cur_cow][j]]++;
						pq.push(make_pair(cur_cnt[inside[cur_cow][j]],inside[cur_cow][j]));
					}
			}
		}
	}
	printf("%d",ans);
	return 0;
}

