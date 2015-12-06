#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
#define PROB "landscape"
using namespace std;
int n,l,r,a[1010],b[1010],an=0,bn=0,d[1010][1010],X,Y,Z;
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	scanf("%d%d%d%d",&n,&X,&Y,&Z);
	for(int i=1; i<=n; i++){
		scanf("%d%d",&l,&r);
		while(l)
			l--,a[++an]=i;
		while(r)
			r--,b[++bn]=i;
	}
	for(int i=1; i<=an; i++)
		d[i][0]=Y*i;
	for(int i=1; i<=bn; i++)
		d[0][i]=X*i;
	for(int i=1; i<=an; i++)
		for(int j=1; j<=bn; j++)
			d[i][j]=min( d[i-1][j-1]+Z*abs(a[i]-b[j]) , min(d[i-1][j]+Y,d[i][j-1]+X) );
	printf("%d",d[an][bn]);
	return 0;
}

