#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB
using namespace std;

#define N 100010
long long ans;
int n,b,p,a[N];
map<int,int> mp1,mp2;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&b);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		if(a[i]==b)p=i;
	}
	int minus=0;
	for(int i=p-1; i; i--){
		if(a[i]<b)minus--;
		else minus++;
		mp1[minus]++;
	}
	minus=0;
	for(int i=p+1; i<=n; i++){
		if(a[i]<b)minus--;
		else minus++;
		mp2[minus]++;
	}
	for(map<int,int>::iterator it=mp1.begin(); it!=mp1.end(); ++it){
		//printf("%d %d %d\n",it->first,it->second,mp2[it->first]);
		ans+=it->second*(long long)mp2[-it->first];
	}
	printf("%lld\n",ans+mp1[0]+mp2[0]+1);
	return 0;
}

