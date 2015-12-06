#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
#include <iostream>
#define PROB "squares"
using namespace std;

typedef pair<int,int> Point;
#define x first
#define y second
Point points[50010];
int n,k;
long long ans=0;

set<Point> st;
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++){
		scanf("%d%d",&points[i].x,&points[i].y);
	}
	
	sort(points+1,points+n+1);
	int l=1;
	set<Point>::iterator it1,it2;
	for(int i=1; i<=n; i++){
		while(points[l].x+k<=points[i].x){
			st.erase(make_pair(points[l].y,points[l].x));
			l++;
		}
		it1=it2=st.insert(make_pair(points[i].y,points[i].x)).first;
		if(it1--!=st.begin()){
			if(it1->x+k>points[i].y){
				if(ans){ans=-1;break;}
				ans=(k-(points[i].x-it1->y))*((long long)k-(points[i].y-it1->x));
			}
		}
		if(++it2!=st.end()){
			if(it2->x-k<points[i].y){
				if(ans){ans=-1;break;}
				ans=(k-(it2->x-points[i].y))*((long long)k-(points[i].x-it2->y));
			}
		}
	}
	cout<<ans;
	return 0;
}

