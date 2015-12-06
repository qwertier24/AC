#include <stdio.h>
#include <algorithm>
#define For(i,b,e) for(int i=b; i<=e; i++)
#define oo 1<<30
using namespace std;
int d[110][110];
int main(){
	int n,m,T;
	freopen("prob.in","r",stdin);
	scanf("%d%d%d",&n,&m,&T);
	For(i,1,n)
		For(j,1,n)
			d[i][j]=oo;
	while(m--){
		int f,t,dt;
		scanf("%d%d%d",&f,&t,&dt);
		d[f][t]=dt;
	}
	For(k,1,n)
	For(i,1,n)
		For(j,1,n)
			d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));
	while(T--){
		int f,t;
		scanf("%d%d",&f,&t);
		printf("%d\n",d[f][t]);
	}
	return 0;
}
