#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
#define print_ans() printf("%d",ans);return 0;
#define For(i,b,e) for(int i=b; i<=e; i++)
using namespace std;
int cnt[5]={0},n,ans=0;
int main()
{
	scanf("%d",&n);
	For(i,1,n){
		int t;
		scanf("%d",&t);
		cnt[t]++;
	}
	ans+=min(cnt[1],cnt[2]);
	if(cnt[1]==cnt[2]){
		printf("%d",ans);
		return 0;
	}
	else if(cnt[1]>cnt[2]){
		cnt[1]-=cnt[2];
		cnt[3]+=cnt[2];
		ans+=(cnt[1]/3)*2;
		cnt[3]+=cnt[1]/3;
		if(cnt[1]%3==0){
			print_ans()
		}
		else if(cnt[1]%3==1){
			if(cnt[3]){
				ans++;
			}
			else if(cnt[4]>=2){
				ans+=2;
			}
			else
				ans=-1;
		}
		else{
			if(cnt[4])
				ans+=2;
			else if(cnt[3]>=2)
				ans+=2;
			else
				ans=-1;
		}
	}
	else{
		cnt[2]-=cnt[1];
		cnt[3]+=cnt[1];
		ans+=(cnt[2]/3)*2;
		cnt[3]+=cnt[2]/3*2;
		cnt[2]%=3;
		if(cnt[2]){
			if(cnt[2]==1){
				if(cnt[4])
					ans++;
				else if(cnt[3]>=2)
					ans+=2;
				else
					ans=-1;
			}
			else{
				ans+=2;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
