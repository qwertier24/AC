#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stack>
#include <list>
using namespace std;
char s[100010];
list<int> ans_a,ans_b;
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	scanf("%s",s);
	int n=strlen(s),t,max_zero=0,cnt[10]={0},cnt_a[10],cnt_b[10]={0};
	for(int i=0; i<n; i++)
		cnt[s[i]-'0']++;
	for(int i=0; i<10; i++)
		cnt_a[i]=cnt_b[i]=cnt[i];
	for(int i=1; i<=9; i++){
		if(cnt_a[i]&&cnt_b[10-i]){
			cnt_a[i]--;
			cnt_b[10-i]--;
			int zero=1;
			for(int i=0; i<10; i++){
				int t=min(cnt_a[i],cnt_b[9-i]);
				cnt_a[i]-=t;
				cnt_b[9-i]-=t;
				zero+=t;
			}
			zero+=min(cnt_a[0],cnt_b[0]);
			max_zero=max(max_zero,zero);
			memcpy(cnt_a,cnt,sizeof(cnt));
			memcpy(cnt_b,cnt,sizeof(cnt));
		}
	}
	for(int i=1; i<=9; i++){
		if(cnt_a[i]&&cnt_b[10-i]){
			cnt_a[i]--;
			cnt_b[10-i]--;
			int zero=1;
			for(int j=0; j<10; j++){
				t=min(cnt_a[j],cnt_b[9-j]);
				cnt_a[j]-=t;
				cnt_b[9-j]-=t;
				zero+=t;
			}
			zero+=min(cnt_a[0],cnt_b[0]);
			memcpy(cnt_a,cnt,sizeof(cnt));
			memcpy(cnt_b,cnt,sizeof(cnt));
			if(zero==max_zero){
				ans_a.push_back(i);
				ans_b.push_back(10-i);
				cnt_a[i]--;
				cnt_b[10-i]--;
				for(int j=0; j<10; j++){
					t=min(cnt_a[j],cnt_b[9-j]);
					for(int k=1; k<=t; k++)
						ans_a.push_front(j),ans_b.push_front(9-j);
					cnt_a[j]-=t;
					cnt_b[9-j]-=t;
				}
				t=min(cnt_a[0],cnt_b[0]);
				for(int j=1; j<=t; j++){
					ans_a.push_back(0);
					ans_b.push_back(0);
				}
				cnt_a[0]-=t;
				cnt_b[0]-=t;
				for(int j=0; j<10; j++){
					for(int k=1; k<=cnt_a[j]; k++)
						ans_a.push_front(j);
					for(int k=1; k<=cnt_b[j]; k++)
						ans_b.push_front(j);
				}
				for(list<int>::iterator it=ans_a.begin(); it!=ans_a.end(); ++it){
					printf("%d",*it);
				}
				printf("\n");
				for(list<int>::iterator it=ans_b.begin(); it!=ans_b.end(); ++it){
					printf("%d",*it);
				}
				return 0;
			}
		}
	}
	for(int i=1; i<10; i++)
		for(int j=1; j<=cnt[i]; j++)
			printf("%d",i);
	for(int i=1; i<=cnt[0]; i++)
		printf("0");
	printf("\n");
	for(int i=1; i<10; i++)
		for(int j=1; j<=cnt[i]; j++)
			printf("%d",i);
	for(int i=1; i<=cnt[0]; i++)
		printf("0\n");
	return 0;
}

