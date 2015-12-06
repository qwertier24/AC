#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB "paint"
using namespace std;
int cnt[100010]={0},n,k,points[100010];
map<int,int> mp;
typedef pair<int,int> Interval;
Interval interval[100010];
#define left first
#define right second
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d%d",&n,&k);
	mp[0];
	int cur=0;
	for(int i=1; i<=n; i++){
		int steps;
		char t[10];
		scanf("%d%s",&steps,t);
		if(t[0]=='L'){
			interval[i].right=cur;
			interval[i].left=(cur-=steps);
		}else{
			interval[i].left=cur;
			interval[i].right=(cur+=steps);
		}
		mp[cur];
	}
	int p_cnt=1;
	for(map<int,int>::iterator it=mp.begin(); it!=mp.end(); ++it,++p_cnt){
		it->second=p_cnt;
		points[p_cnt]=it->first;
	}
	points[p_cnt]=points[p_cnt-1]+1;
	int sum=0,ans=0;
	for(int i=1; i<=n; i++){
		cnt[mp[interval[i].left]]++;
		cnt[mp[interval[i].right]]--;
	}
	for(int i=1; i<=p_cnt; i++){
		sum+=cnt[i];
		if(sum>=k)
			ans+=points[i+1]-points[i];
	}
	printf("%d",ans);
	return 0;
}

