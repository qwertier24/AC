#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <string.h>
#include <string>
#include <math.h>
using namespace std;
int T,n,f[201],d[201],t[201];
struct HeapNode
{
	int p,ft;
	bool operator<(const HeapNode& rhs)const
	{
		return (ft<rhs.ft||(ft==rhs.ft&&p>rhs.p));
	}
};
int main()
{
	bool first_case=true;
	while(scanf("%d",&n)&&n)
	{
		int max_f_num=-1,ans[201]={0};
		scanf("%d",&T);
		T*=12;
		for(int i=1; i<=n; i++)
			scanf("%d",&f[i]);
		for(int i=1; i<=n; i++)
			scanf("%d",&d[i]);
		for(int i=1; i<n; i++)
			scanf("%d",&t[i]);
		for(int i=1; i<=n; i++)
		{
			int stay_t[201]={0},f_num=0;
			priority_queue<HeapNode> pq;
			int t0=0;
			for(int j=1; j<i; j++)
				t0+=t[j];
			t0=T-t0;
			for(int j=1; j<=i; j++)
				pq.push((HeapNode){j,f[j]});
			while(t0>0)
			{
				HeapNode pool=pq.top();
				pq.pop();
				//printf("i:%d t0:%d top:%d\n",i,t0,pool.ft);
				f_num+=pool.ft;
				stay_t[pool.p]++;
				if(pool.ft>=d[pool.p])
					pool.ft-=d[pool.p];
				else
					pool.ft=0;
				pq.push(pool);
				t0--;
			}
			if(f_num>max_f_num)
			{
				max_f_num=f_num;
				for(int j=1; j<=n; j++)
					ans[j]=stay_t[j];
			}
		}
		if(!first_case)
			printf("\n");
		else
			first_case=false;
		for(int i=1; i<n; i++)
			printf("%d, ",ans[i]*5);
		printf("%d\n",ans[n]*5);
		printf("Number of fish expected: %d\n",max_f_num);
	}
	return 0;
}
