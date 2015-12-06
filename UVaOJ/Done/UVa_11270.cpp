#include<stdio.h>
#include<algorithm>
#include<cstring>
#define dbg if(1)
using namespace std;
long long d[100][1<<11];
int n,m;
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	while(scanf("%d%d",&n,&m)!=EOF){
		memset(d,0,sizeof(d));
		if(n<m)swap(n,m);
		d[1][(1<<m)-1]=1;
		int ALL=(1<<m)-1;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				long long *cur=d[(i*m+j)&1],*last=d[(i*m+j+1)&1];
				memset(cur,0,sizeof(d[0]));
				for(int k=0; k<=ALL; k++){
					if(k&(1<<(m-1)))cur[(k<<1)&ALL]+=last[k];
					if(i&&!(k&(1<<(m-1))))cur[k<<1|1]+=last[k];
					if(j&&!(k&1)&&(k&(1<<(m-1))))cur[((k<<1)&ALL)|3]+=last[k];
				}
			}
		}
		printf("%lld\n",d[(n*m-1)&1][(1<<m)-1]);
	}
	return 0;
}
