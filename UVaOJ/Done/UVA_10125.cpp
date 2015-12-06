#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#define INF (1<<31)
using namespace std;
struct AB
{
	int a,b;
	AB(){}
	AB(int x,int y):a(x),b(y){}
};
map <int,vector<AB> > mp;
int num[1001],ans,n;
int main()
{
	while(scanf("%d",&n)&&n)
	{
		ans=INF;
		mp.clear();
		for(int i=1; i<=n; i++)
			scanf("%d",&num[i]);
		for(int i=1; i<=n;i++ )
		{
			for (int j=i+1; j<=n; j++)
			{
				vector<AB> &t=mp[num[i]+num[j]];
				if(t.size()<5)
				{
					bool push_able=true;
					for(int k=0; k<t.size(); k++)
						if(i==t[k].a||j==t[k].b)
						{push_able=false;break;}
					if(push_able)
						t.push_back(AB(i,j));
				}
			}
		}
		for (int i=1; i<=n; i++)
			if(num[i]>ans)
				for(int j=1; j<=n; j++)
					if(i!=j)
					{
						vector<AB> t=mp[num[i]-num[j]];
						for(int k=0; k<t.size(); k++)
							if(t[k].a!=i&&t[k].b!=i&&t[k].a!=j&&t[k].b!=j)
								ans=num[i];
					}
		if(ans==INF)
			printf("no solution\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
