#include<stdio.h>
#include<algorithm>
#define PROB "empty"
#define For(i,n) for(int i=1; i<=n; i++)
using namespace std;

int cnt[3000000]={0};
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	For(i,k){
		int x,y,a,b;
		scanf("%d%d%d%d",&x,&y,&a,&b);
		For(j,y){
			cnt[(a*(long long)j+b)%n]+=x;
		}
	}
	
	int sum=0;
	for(int i=0; i<n; i++){
		if(cnt[i]==0){
			cnt[i]+=min(sum,1);
			sum-=min(sum,1);
		}else{
			sum+=cnt[i]-1;
			cnt[i]=1;
		}
	}
	for(int i=0; i<n; i++){
		if(cnt[i]==0){
			cnt[i]+=min(sum,1);
			sum-=min(sum,1);
		}else{
			sum+=cnt[i]-1;
			cnt[i]=1;
		}
	}
	int ans=0;
	while(cnt[ans])
		ans++;
	printf("%d",ans);
	return 0;
}
