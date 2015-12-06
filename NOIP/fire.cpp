#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define maxn 50010
#define PROB "fire" 
using namespace std;
int n,a[50010],b[maxn],pos[maxn],cnt[50010]={0};
bool check(){
	for(int i=1; i<=n; i++)
		if(!(a[a[i]]==i||b[a[i]]==i)||!(a[b[i]]==i||b[b[i]]==i))
			return false;
	return true;
}
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d%d",&a[i],&b[i]);
	if(!check()){printf("-1");return 0;}
	pos[1]=1;
	int p=a[1],last_p=1,cur=1;
	while(p!=1){
		cur++;
		pos[p]=cur;
		if(a[p]==last_p){
			last_p=p;
			p=b[p];
		}else{
			last_p=p;
			p=a[p];
		}
	}
	int ans=0;
	for(int i=1; i<=n; i++)
		cnt[(i-pos[i]+n)%n]++;
	for(int i=0; i<=n; i++)
		ans=max(ans,cnt[i]);
	memset(cnt,0,sizeof(cnt));
	for(int i=1; i<=n; i++)
		cnt[(n-i+1-pos[i]+n)%n]++;
	for(int i=0; i<=n; i++)
		ans=max(ans,cnt[i]);
	printf("%d",n-ans);
	return 0;
}

