#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB "jfzp"
using namespace std;
int n,sum=0,a[110],ave,ans=0;
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		//printf("%d %d\n",a[i],sum);
	}
	ave=sum/n;
	sum=0;
	a[0]=ave;
	for(int i=1; i<=n; i++){
		if(a[i-1]!=ave)
			ans++;
		a[i]+=a[i-1]-ave;
	}
	printf("%d",ans);
	return 0;
}

