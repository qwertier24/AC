#include <stdio.h>
#include <algorithm>
#include <vector>
#define INF 1e8
using namespace std;

double a[1010],b[1010];

typedef pair<double,double> Interval;
vector<Interval> interval;
int n;
int main(){
	double ans=0;
	bool flag=true;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%lf%lf",&a[i],&b[i]);
	double times=0;
	for(int i=1; i<=n; i++){
		times+=b[i];
		if(b[i]==b[i+1]){
			if(a[i]<b[i]){
				printf("-1");
				return 0;
			}else
				interval.push_back(Interval(0,INF));
		}else if(b[i]>b[i+1]){
			interval.push_back(Interval(max(0.0,(a[i+1]-a[i])/(b[i]-b[i+1])),INF));
		}else{
			interval.push_back(Interval(0,(a[i+1]-a[i])/(b[i]-b[i+1])));
		}
	}
	for(int i=0; i<interval.size(); i++)
		if(interval[i].first>interval[i].second){
			printf("-1");
			return 0;
		}
	sort(interval.begin(),interval.end());
	ans=interval[interval.size()-1].first;
	for(int i=0; i<interval.size(); i++){
		if(interval[i].second<ans){
			printf("-1");
			return 0;
		}
	}
	printf("%f",ans*times);
	return 0;
}
