#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <algorithm>
#include <queue>
#define INF 1<<30
using namespace std;
struct HeapNode
{
	int u,d;
	bool operator<(const HeapNode& rhs)const
	{
		return d>rhs.d;
	}
};
int idx(char c)
{
	if(isupper(c))
		return c-'A'+26;
	else
		return c-'a';
}
int length[100],done[100];
vector<int> adj[100];
int main()
{
	//freopen("prob.in","r",stdin);
	int n,start,end,p,kase=1;
	char f,t;
	while(scanf("%d",&n)&&n!=-1)
	{
		for(int i=0; i<52; i++)
			adj[i].clear();
		for(int i=1; i<=n; i++)
		{
			getchar();
			scanf("%c %c",&f,&t);
			//printf("%d %d\n",idx(f),idx(t));
			adj[idx(f)].push_back(idx(t));
			adj[idx(t)].push_back(idx(f));
		}
		scanf("%d %c %c",&p,&f,&t);
		start=idx(f),end=idx(t);
		memset(done,0,sizeof(done));
		for(int i=0; i<52; i++)   //begin dijkstra
			length[i]=INF;
		length[end]=p;
		priority_queue<HeapNode> pq;
		pq.push((HeapNode){end,length[end]});
		while(!pq.empty())
		{
			HeapNode t=pq.top();
			pq.pop();
			if(done[t.u])continue;
			done[t.u]=1;
			for(int i=0; i<adj[t.u].size(); i++)
			{
				int to=adj[t.u][i],from=t.u;
				if(length[to]>(from<26?(length[from]+1):((length[from]*20-1)/19+1)))
				{
					length[to]=(from<26?(length[from]+1):((length[from]*20-1)/19+1));
					pq.push((HeapNode){to,length[to]});
				}
			}
		}/*
		for(int i=0; i<52; i++)
			if(length[i]!=INF)
				printf("%d:%d\n",i,length[i]);*/
		printf("Case %d: %d\n",kase++,length[start]);
	}
}
