#include<stdio.h>
#include<algorithm>
#include<cstring>
#define PROB "pogocow"
#define For(i,n) for(int i=1; i<=n; i++)
#define x first
#define p second
#define CLR(t) memset(t,0,sizeof(t))
#define dbg if(0)
using namespace std;

typedef pair<int,int> Target;
Target tar[1010];
int d[1010][1010]={0},n;

int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d",&n);
	For(i,n)scanf("%d%d",&tar[i].x,&tar[i].p);
	sort(tar+1,tar+n+1);
	int ans=0;
	for(int l=n; l>=1; l--){
		for(int r=n; r>l; r--){
			int rr=lower_bound(tar+1,tar+n+1,make_pair(tar[r].x-tar[l].x+tar[r].x,-1))-tar;
			d[l][r]=max(d[r][rr]+tar[r].p,d[l][r+1]);
			ans=max(ans,d[l][r]+tar[l].p);
dbg			printf("%d %d %d %d\n",l,r,rr,d[l][r]+tar[l].p);
		}
	}
	CLR(d);
	for(int r=1; r<=n; r++){
		for(int l=1; l<r; l++){
			int ll=upper_bound(tar+1,tar+n+1,make_pair(tar[l].x-tar[r].x+tar[l].x,1<<30))-tar-1;
			d[r][l]=max(d[l][ll]+tar[l].p,d[r][l-1]);
			ans=max(ans,d[r][l]+tar[r].p);
dbg			printf("%d %d %d %d\n",ll,l,r,d[r][l]+tar[r].p);
		}
	}
	printf("%d",ans);
	return 0;
}

