#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB "photo"

using namespace std;


int n,p[5][20000],id[20000],ord[20000];

bool cmp(const int& a,const int& b){
	int t=0;
	for(int i=0; i<5; i++)
		t+=(p[i][a]<p[i][b]);
	return t>2;
}
map<int,int> mp;
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&id[i]);
		mp[id[i]]=(int)mp.size()-1;
		p[0][mp[id[i]]]=i;
	}
	for(int i=1; i<5; i++)
		for(int j=0; j<n; j++){
			int t;
			scanf("%d",&t);
			p[i][mp[t]]=j;
		}
	for(int i=0; i<n; i++)
		ord[i]=i;
	sort(ord,ord+n,cmp);
	for(int i=0; i<n; i++)
		printf("%d\n",id[ord[i]]);
	return 0;
}

