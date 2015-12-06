#include<stdio.h>
#include<string.h>
#include<algorithm>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)
using std::reverse;

typedef long long LL;
#define N 210
const int m=26;

int ch[N][m],sz,val[N];
void insert(char *s){
	int u=0;
	while(*s){
		int c=(*s)-'a';
		s++;
		if(!ch[u][c]){
			ch[u][c]=++sz;
			memset(ch[sz],0,sizeof(ch[sz]));
		}
		u=ch[u][c];
	}
	val[u]=1;
}

int d[1000010];
char s[1000010];
int dp(int cur){
	int u=0,ret=0;
	while(cur){
		u=ch[u][s[cur--]-'a'];
		if(!u)break;
		if(val[u] && d[cur])return 1;
	}
	return 0;
}

char str[30][11];
int n,q;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&q);
	REP(i,1,n){
		scanf("%s",&str[i]);
		reverse(str[i],str[i]+strlen(str[i]));
		insert(str[i]);
	}
	d[0]=1;
	while(q--){
		scanf("%s",s+1);
		int l=strlen(s+1);
		int ans=0;
		REP(i,1,l){
			d[i]=dp(i);
			//printf("%d %d\n",i,d[i]);
			if(d[i])ans=i;
		}
		printf("%d\n",ans);
	}
	return 0;
}

