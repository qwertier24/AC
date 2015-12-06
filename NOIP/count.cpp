#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
map<int,int> mp;
int main(){
//#ifndef ONLINE_JUDGE
	freopen("pcount.in","r",stdin);
	freopen("pcount.out","w",stdout);
//#endif
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		int a;
		scanf("%d",&a);
		mp[a]++;
	}
	for(map<int,int>::iterator it=mp.begin(); it!=mp.end(); it++)
		printf("%d %d\n",it->first,it->second);
	return 0;
}
