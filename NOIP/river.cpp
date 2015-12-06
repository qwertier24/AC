#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define gcd __gcd
#define PROB "river"
#define zero 10
#define INF (1<<29)
using namespace std;
int rock_here[30000]={0},d[30000]={0},L,s,t,m,x[110]={0};
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d%d%d%d",&L,&s,&t,&m);
				
	for(int i=1; i<=m; i++)
		scanf("%d",&x[i]);
	if(s==t){
		int cnt=0;
		for(int i=1; i<=m; i++)
			if(x[i]%s==0)
				cnt++;
		printf("%d",cnt);
		return 0;
	}
	m++;
	x[m]=L;
	sort(x+1,x+m+1);
	int p=0;
	for(int i=1; i<=m; i++){
		if(x[i]-x[i-1]>100)p+=100;
		else p+=x[i]-x[i-1];
		rock_here[p]=1;
	}
	rock_here[p]=0;
	
	int ans=INF;
	for(int i=1; i<=p+2520; i++){
		d[i]=INF;
		for(int j=s; j<=t&&j<=i; j++)
			d[i]=min(d[i],d[i-j]+rock_here[i]);
		if(i>=p)ans=min(ans,d[i]);
	}
	printf("%d",ans);
	return 0;
}

