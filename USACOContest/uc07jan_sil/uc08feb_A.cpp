#include <stdio.h>
#include <algorithm>
#include <map>
#define For(i,b,e) for(int i=b; i<=e; ++i)
#define gcd __gcd
using namespace std;
struct P{
	int x,y;
	pair<int,int> get_slope(const P& t){
		pair<int,int> ret;
		ret.first=y-t.y;
		ret.second=x-t.x;
		if(ret.first<0){
			ret.first*=-1;
			ret.second*=-1;
		}
		int g=gcd(abs(ret.first),abs(ret.second));
		ret.first/=g;
		ret.second/=g;
		if(ret.first==0)
			ret.second=1;
		else if(ret.second==0)
			ret.first=1;
		return ret;
	}
}points[210];
int n;
map<pair<int,int>,int> mp;
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d %d",&points[i].x,&points[i].y);
		For(j,1,i-1){
			pair<int,int> t=points[i].get_slope(points[j]);
			if(!mp.count(t)){
				if(t.first==0)
					cnt_x0++;
				if(t.second==0)
					cnt_y0++;
				mp[t]=1;
			}
			//printf("%d %d %d %d\n",i,j,t.first,t.second);
		}
	}
	printf("%d",(int)mp.size());
	return 0;
}
