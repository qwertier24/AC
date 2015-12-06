#include<stdio.h>
#include<algorithm>
using namespace std;

typedef pair<int,int> Cow;

int n,pre[8010],mark[8010]={0},pos[8010];
int main(){
	scanf("%d",&n);
	for(int i=2; i<=n; i++)
		scanf("%d",&pre[i]);
	for(int i=n; i>=1; i--){
		int cnt=0;
		for(int j=1; j<=n; j++){
			if(!mark[j])
				cnt++;
			if(cnt==pre[i]+1){
				pos[i]=j;
				mark[j]++;
				break;
			}
		}
	}
	for(int i=1; i<=n; i++)
		printf("%d\n",pos[i]);
	while(true);
	return 0;
}
