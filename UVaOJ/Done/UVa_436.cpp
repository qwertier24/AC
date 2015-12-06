#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
double dist[201][201];
map<string,int> mp;
int main()
{
	int n,m,kase=1;
	while(scanf("%d",&n)&&n)
    {
		mp.clear();
		memset(dist,0,sizeof(dist));
		for(int i=1; i<=n; i++)
		{
			string s;
			cin>>s;
			mp[s]=i;
			//cout<<s;
		}
		scanf("%d",&m);
		for(int i=1; i<=m; i++)
		{
			string s1,s2;
			double t;
			cin>>s1>>t>>s2;
			dist[mp[s1]][mp[s2]]=t;
			//cout<<s1<<s2;
			//printf("%lf\n",dist[mp[s1]][mp[s2]]);
		}
		//printf("%lf\n",dist[1][2]);
		for(int k=1; k<=n; k++)
			for(int i=1; i<=n; i++)
			{
				for(int j=1; j<=n; j++)
				{
					if(i!=j&&j!=k&&k!=i)
						dist[i][j]=max(dist[i][j],dist[i][k]*dist[k][j]);
					//printf("%d %d: %lf ",i,j,dist[i][j]);
				}
				//printf("\n");
			}
		bool ok=false;
		for(int i=1; i<=n&&!ok; i++)
			for(int j=1; j<=n; j++)
				if(dist[i][j]*dist[j][i]>1)
				{
					//printf("%d %d\n",i,j);
					ok=true;
					break;
				}
		if(ok)
			printf("Case %d: Yes\n",kase++);
		else
			printf("Case %d: No\n",kase++);
	}
	return 0;
}
