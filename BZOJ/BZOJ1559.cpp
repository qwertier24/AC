#include<stdio.h>
#include<string.h>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

typedef long long LL;
#define N 11
const int m=26;

int ch[N*N][m],sz,val[N*N];
void insert(char *s,int i){
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
	val[u]=1<<i;
}

int fa[N*N];
int q[N*N],fr,rr;
void calc_fa(){
	fr=rr=0;
	rr--;
	REP(i,0,m-1)if(ch[0][i])q[++rr]=ch[0][i];
	while(fr<=rr){
		int r=q[fr++];
		REP(i,0,m-1){
			int u=ch[r][i];
			if(!u){
				ch[r][i]=ch[fa[r]][i];
				continue;
			}
			fa[u]=ch[fa[r]][i];
			val[u]|=val[fa[u]];
			q[++rr]=u;
		}
	}
}
int l;

LL d[N*N][1<<N][30],p26[30];
LL dp(int u,int S,int L){
	if(d[u][S][L]!=-1)return d[u][S][L];
	if(!S)return d[u][S][L]=p26[L];
	if(!L)return d[u][S][L]=0;
	d[u][S][L]=0;
	REP(i,0,m-1)d[u][S][L]+=dp(ch[u][i],S^(S&val[ch[u][i]]),L-1);
	return d[u][S][L];
}
char cur[30];
void print(int u,int S,int L){
	if(d[u][S][L]==0)return;
	if(!L){
		puts(cur);
		return;
	}
	REP(i,0,m-1)if(dp(ch[u][i],S^(S&val[ch[u][i]]),L-1)){
		cur[l-L]=i+'a';
		print(ch[u][i],S^(S&(val[ch[u][i]])),L-1);
	}
}

char str[N][N];
int n;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	p26[0]=1;
	REP(i,1,25)p26[i]=p26[i-1]*26;
	int kase=1;
	while(scanf("%d%d",&l,&n)&&(l||n)){
		memset(d,-1,sizeof(d));
		memset(ch[0],0,sizeof(ch[0]));
		memset(fa,0,sizeof(fa));
		memset(val,0,sizeof(val));
		memset(cur,0,sizeof(cur));
		memset(ch,0,sizeof(ch));
		sz=0;
		REP(i,0,n-1){
			scanf("%s",str[i]);
			insert(str[i],i);
		}
		calc_fa();
		LL ans;
		printf("Case %d: %lld suspects\n",kase++,ans=dp(0,(1<<n)-1,l));
		if(ans<=42)print(0,(1<<n)-1,l);
	}
	return 0;
}

