#include <stdio.h>
#include <algorithm>
#include <string.h>
#define PROB "spy" 
using namespace std;
int idx(char t){
	return t-'A';
}
int key[26];
char s1[110],s2[110],s3[110],mark[26]={0};
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	memset(key,-1,sizeof(key));
	scanf("%s%s%s",s1,s2,s3);
	bool flag=true;
	int l1=strlen(s1),cnt=0;
	for(int i=0; i<l1; i++){
		if(key[idx(s1[i])]!=-1){
			if(key[idx(s1[i])]!=idx(s2[i])){
				flag=false;
				//printf("%d %d\n",i,idx(s1[i]));
				break;
			}
		}else{
			if(mark[idx(s2[i])]){
				flag=false;
				break;
			}
			mark[idx(s2[i])]=1;
			cnt++;
			key[idx(s1[i])]=idx(s2[i]);
		}
	}
	if(!flag||cnt<26){
		printf("Failed\n");
		return 0;
	}
	int l3=strlen(s3);
	for(int i=0; i<l3; i++)
		printf("%c",key[idx(s3[i])]+'A');
	return 0;
}

