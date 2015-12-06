#include <stdio.h>
#include <algorithm>
using namespace std;
int cnt[10010]={0},match[10]={6,2,5,5,4,5,6,3,7,6};
int main(){
	freopen("matches.in","r",stdin);
	freopen("matches.out","w",stdout);
	int n;
	scanf("%d",&n);
	cnt[0]=6;
	for(int i=1; i<=10000; i++){
		int t=i;
		while(t){
			cnt[i]+=match[t%10];
			t/=10;
		}
	}
	int ans=0;
	for(int i=0; i<=4000; i++)
		for(int j=0; j<=4000; j++)
			if(cnt[i]+cnt[j]+cnt[i+j]==n-4){
				//printf("%d %d %d\n",i,j,i+j);
				ans++;
			}
	printf("%d",ans);
	return 0;
}
