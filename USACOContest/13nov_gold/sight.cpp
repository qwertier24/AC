#include<stdio.h>
#include<algorithm>
#include<queue>
#include<cmath>
#include<vector>
#define Rep(i,n) for(int i=0; i<n; i++)
#define PROB "sight"
using namespace std;

const double PI=3.1415926535897932384626;

typedef pair<double,double> Interval;
vector<Interval> interval;

int n,r;
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d%d",&n,&r);
	
	Rep(i,n){
		int x,y;
		scanf("%d%d",&x,&y);
		double a=atan2(y,x),da=acos(r/sqrt(x*(double)x+y*(double)y));
		a-=da;
		if(a<0)a+=2*PI;
		interval.push_back(make_pair(a,a+2*da));
	}
	
	sort(interval.begin(),interval.end());
	
	priority_queue<double,vector<double>,greater<double> > pq;
	
	int ans=0;
	Rep(loop,2){
		Rep(i,n){
			while(!pq.empty()&&pq.top()<interval[i].first){
				pq.pop();
			}
			if(loop)
				ans+=pq.size();
			pq.push(interval[i].second);
			interval[i].first+=2*PI;
			interval[i].second+=2*PI;
		}
	}
	printf("%d",ans);
	return 0;
}
