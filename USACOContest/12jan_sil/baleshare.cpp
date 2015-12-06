#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB "baleshare"
#define maxc 2000
#define getd(i,j) (i>=0&&j>=0?d[i][j]:0)
using namespace std;
int n,a[30];
unsigned int d[maxc+10][maxc/32+10]={0};
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d",&n);
	d[0][0]=1;
	int sum=0;
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		for(int j=maxc; j>=0; j--)
			for(int k=maxc/32+1; k>=0; k--){
				d[j][k]=getd(j,k)|getd(j-a[i],k)|(getd(j,k-a[i]/32)<<(a[i]%32));
				if(a[i]%32)
					d[j][k]|=(getd(j,k-a[i]/32-1)>>(32-a[i]%32));
			}
	}
	int ans=1<<30;
	for(int i=0; i<=sum; i++)
		for(int j=0; i+j<=sum; j++)
			if((d[i][j/32]>>(j%32))&1)
				if(i>0&&j>0&&sum-i-j>0)
					ans=min(ans,max(max(i,j),sum-i-j));
	printf("%d",ans);
	return 0;
}

