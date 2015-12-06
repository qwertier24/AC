#include <stdio.h>
#include <algorithm>
#include <cstring>
#define idx(t) (t-'a')
using namespace std;
char word[110];
int cnt[26];
int main(){
	freopen("word.in","r",stdin);
	freopen("word.out","w",stdout);
	int max_cnt=0,min_cnt=1<<30;
	scanf("%s",word);
	int len=strlen(word);
	for(int i=0; i<len; i++)
		cnt[idx(word[i])]++;
	for(int i=0; i<26; i++)
		max_cnt=max(max_cnt,cnt[i]);
	for(int i=0; i<26; i++)
		if(cnt[i])
			min_cnt=min(min_cnt,cnt[i]);
	int t=max_cnt-min_cnt;
	if(t==1||t==0){
		printf("No Answer\n0\n");
		return 0;
	}
	for(int i=2; i*i<=t; i++)
		if(t%i==0){
			printf("No Answer\n0\n");
			return 0;
		}
	printf("Lucky Word\n%d\n",t);
	return 0;
}
