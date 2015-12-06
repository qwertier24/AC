#include <stdio.h>
#include <map>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
struct BLOCK
{
	int a,b,h;
	bool operator<(const BLOCK& rhs) const
	{
		return a>rhs.a||(a==rhs.a&&b>rhs.b);
	}
};
map<int,int> mp;
vector<int> lengths;
vector<BLOCK> blocks;
int d[100][100],n;
int main()
{
	int kase=1;
	while(scanf("%d",&n)&&n)
	{
		mp.clear();
		lengths.clear();
		blocks.clear();
		memset(d,0,sizeof(d));
		int max_length=0;
		for(int i=1; i<=n; i++)
		{
			int xt,yt,zt;
			scanf("%d%d%d",&xt,&yt,&zt);
			lengths.push_back(xt);
			lengths.push_back(yt);
			lengths.push_back(zt);
			blocks.push_back((BLOCK){min(xt,yt),max(xt,yt),zt});
			blocks.push_back((BLOCK){min(xt,zt),max(xt,zt),yt});
			blocks.push_back((BLOCK){min(yt,zt),max(yt,zt),xt});
		}
		sort(lengths.begin(),lengths.end());
		sort(blocks.begin(),blocks.end());
		for(int i=0; i<lengths.size(); i++)
			if(!mp.count(lengths[i]))
				mp[lengths[i]]=++max_length;
		for(int i=0; i<blocks.size(); i++)
		{
			blocks[i].a=mp[blocks[i].a];
			blocks[i].b=mp[blocks[i].b];
		}
		//printf("%d\n",max_length);
		int ans=0;
		for(int i=0; i<blocks.size(); i++)
		{
			//printf("blocks[%d]:%d %d %d\n",i,blocks[i].a,blocks[i].b,blocks[i].h);
			for(int a=blocks[i].a; a<=max_length; a++)
				for(int b=blocks[i].b; b<=max_length; b++)
				{
					d[blocks[i].a-1][blocks[i].b-1]=max(d[blocks[i].a-1][blocks[i].b-1],d[a][b]+blocks[i].h);
					ans=max(ans,d[blocks[i].a-1][blocks[i].b-1]);
				}
		}
		printf("Case %d: maximum height = %d\n",kase++,ans);
	}
	return 0;
}
