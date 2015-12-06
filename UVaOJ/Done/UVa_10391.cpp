#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,n) for(int i=1; i<=n; i++)
typedef unsigned int uint;
typedef unsigned long long ull;
using namespace std;

uint hash(const char* s){
	uint ret=1;
	while(*s)ret*=(uint)*(s++);
	return ret&0x7fffffff;
}

int last_pos[120010],hash_cnt=0,pre_pos[120010],pos[120010];
void add_hash(int val,int p){
	hash_cnt++;
	pre_pos[hash_cnt]=last_pos[val];
	last_pos[val]=hash_cnt;
	pos[hash_cnt]=p;
}

char s[120010][100];

uint hash_val[120010],hash_val2[120010];
int n=0,len[120010];
bool check(int i,int j,int k){
	if(len[j]+len[k]!=len[i])return false;
	for(int l=0; l<len[j]; l++)
		if(s[i][l]!=s[j][l])
			return false;
	for(int l=len[j]; l<len[j]+len[k]; l++)
		if(s[i][l]!=s[k][l-len[j]])
			return false;
	return true;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	while(scanf("%s",s[n+1])!=EOF){
		n++;
		hash_val[n]=hash(s[n]);
		int len=strlen(s[n]);
		for(int i=0; i<len; i++)
			if(fhash(s[n],s[n]+i)
	}
	for(int i=0; i<351; i++)
		for(int j=0; j<351; j++)
			if(last_pos[i]&&last_pos[j])
				add_hash2((i*j)%351,i,j);
	For(i,n){
		int h=hash_val2[i];
		for(int i=last_pos2[h]; i; i=pre_pos2[i]){
			int p1=pos2[i].first,p2=pos2[i].second;
			printf("%d %d %d2\n",i,p1,p2);
			if(hash_val[i]==hash_val[p1]*hash_val[p2]){
				if(check(i,p1,p2)){
					printf("%s\n",s[i]);
					break;
				}
			}
		}
	}
	while(true);
	return 0;	
}
