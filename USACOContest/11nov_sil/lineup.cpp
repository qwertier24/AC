#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
#define PROB "lineup"
#define id second
#define x first
using namespace std;

typedef pair<int,int> Cow;
Cow cow[50000];
int n;
map<int,int> cnt;
set<int> st;
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d%d",&cow[i].x,&cow[i].id);
		cnt[cow[i].id]=0;
	}
	sort(cow,cow+n);
	int l=0,ans=1<<30;
	for(int i=0; i<n; i++){
		cnt[cow[i].id]++;
		st.insert(cow[i].id);
		if(st.size()==cnt.size()){
			while(cnt[cow[l].id]>1){
				cnt[cow[l].id]--;
				l++;
			}
			ans=min(ans,cow[i].x-cow[l].x);
		}
	}
	printf("%d",ans);
	return 0;
}

