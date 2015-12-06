#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB
#define Rep(i,n) for(int i=0; i<n; i++)
#define For(i,n) for(int i=1; i<=n; i++)
using namespace std;

#define N 1010
int mat[N<<1][N/32+10],n,m,type[N];
char s[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	if(m<n){
		puts("Cannot Determine");
		return 0;
	}
	Rep(i,m){
		int t;
		scanf("%s%d",s,&t);
		Rep(j,n)
			mat[i][j/32]|=(s[j]-'0')<<j%32;
		mat[i][n/32]|=t<<n%32;
	}
	int ans=1;
	Rep(i,n){
		int cur=ans;
		for(int j=i; j<ans; j++)
			if(mat[j][i/32]&(1<<i%32)){
				cur=j;
				break;
			}
		if(cur==ans){
			while(cur<m && !(mat[cur][i/32]&(1<<i%32)))
				cur++;
			if(cur==m){
				puts("Cannot Determine");
				return 0;
			}
			ans=cur+1;
		}
		if(i!=cur)
			for(int j=i/32; j<=n/32; j++)
				swap(mat[cur][j],mat[i][j]);
		for(int j=i+1; j<m; j++)
			if(mat[j][i/32]&(1<<i%32))
				for(int k=i/32; k<=n/32; k++)
					mat[j][k]^=mat[i][k];
	}
	printf("%d\n",ans);
	for(int i=n-1; i>=0; i--){
		type[i]=(mat[i][n/32]>>n%32)&1;
		for(int j=i+1; j<n; j++)
			type[i]^=((mat[i][j/32]>>j%32)&1)*type[j];
	}
	Rep(i,n){
		if(type[i])puts("?y7M#");
		else puts("Earth");
	}
	return 0;
}

