#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <set>
using namespace std;
struct P
{
	int x,y;
	bool operator<(const P& rhs)const
	{
		return x<rhs.x||(x==rhs.x&&y<rhs.y);
	}
};
multiset<P>::iterator it;
multiset<P> st;
int main()
{
	int T;
	scanf("%d",&T);
	for(int kase=1; kase<=T; kase++)
	{
		st.clear();
		int n;
		scanf("%d",&n);
		printf("Case #%d:\n",kase);
		while(n--)
		{
			P t;
			scanf("%d%d",&t.x,&t.y);
			it=st.lower_bound(t);
			if(it==st.begin()||(--it)->y>t.y)
			{
			//printf("OK");
				st.insert(t);
				it=st.upper_bound(t);
				while(it!=st.end()&&it->y>=t.y)
				{
					//printf("%d %d\n",it->x,it->y);
					st.erase(it++);
				}
			}
			printf("%d\n",st.size());
		}
		if(kase!=T)
			printf("\n");
	}
	return 0;
}
