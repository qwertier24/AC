#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB "climb"
#define up first
#define down second
using namespace std;

typedef pair<int,int> Cow;
Cow cow[25000];
bool cmp(const Cow& a,const Cow& b){
	return min(b.up,a.down)>min(a.up,b.down);
}
int n;
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d%d",&cow[i].first,&cow[i].second);
	sort(cow,cow+n,cmp);
	int sum1=0,sum2=0;
	for(int i=0; i<n; i++){
		sum1+=cow[i].up;
		sum2=max(sum2,sum1);
		sum2+=cow[i].down;
	}
	printf("%d",sum2);
	return 0;
}

