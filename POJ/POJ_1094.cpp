#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
vector<int> adj[26];
int visiting[26],visited[26];
inline int idx(char t)
{
	return t-'A';
}
bool dfs(int u)
{
	visiting[u]=1;
	for(int i=0; i<adj[u].size(); i++)
		if(visiting[adj[u][i]]||(!visited[adj[u][i]]&&!dfs(adj[u][i])))
			return false;
	visited[u]=1;
	visiting[u]=0;
	return true;
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)&&n)
	{
		bool end=false;
		for(int i=0; i<n; i++)
			adj[i].clear();
		for(int i=1; i<=m; i++)
		{
			char relation[10];
			scanf("%s",relation);
			if(!end)
			{
				adj[idx(relation[0])].push_back(idx(relation[2]));
				memset(visiting,0,sizeof(visiting));
				memset(visited,0,sizeof(visited));
				for(int j=0; j<26; j++)
				{
					if(!dfs(j))
					{
						printf("Inconsistency found after %d relations.\n",i);
						end=true;
						break;
					}
				}
			}                   //find the conflict by searching the round
			if(!end)
			{
				int d[26]={0},inq[26]={0};
				queue<int> q;
				for(int j=0; j<n; j++)
					q.push(j),inq[j]=1;
				while(!q.empty())
				{
					int u=q.front();
					q.pop();
					inq[u]=0;
					//printf("%d %d\n",u,d[u]);
					for(int j=0; j<adj[u].size(); j++)
						if(d[adj[u][j]]<d[u]+1)
						{
							d[adj[u][j]]=d[u]+1;
							if(!inq[adj[u][j]])
							{
								q.push(adj[u][j]);
								inq[adj[u][j]]=1;
							}
						}
				}
				int order[26];
				memset(order,-1,sizeof(order));
				for(int j=0; j<n; j++)
					order[d[j]]=j;
				if(order[n-1]!=-1)
				{
					printf("Sorted sequence determined after %d relations: ",i);
					for(int j=0; j<n; j++)
						printf("%c",order[j]+'A');
					printf(".\n");
					end=true;
				}
			}                  //find the order by sorting topologically
		}
		if(!end)
			printf("Sorted sequence cannot be determined.\n");
	}
	return 0;
}
