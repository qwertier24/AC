#include<stdio.h>
#include<algorithm>
#define PROB "combo"
#define For(i,n) for(int i=1; i<=n; i++)
using namespace std;

int n;
int dist(int a,int b){
	if(a<=b)return min(b-a,n+a-b);
	else return min(a-b,n+b-a);
}
bool check(int a,int b,int c,int d,int e,int f){
	return dist(a,d)<=2&&dist(b,e)<=2&&dist(c,f)<=2;
}
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	int a,b,c,d,e,f;
	scanf("%d",&n); 
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	int ans=0;
	For(i,n)
		For(j,n)
			For(k,n){
				if(check(i,j,k,a,b,c)||check(i,j,k,d,e,f))
					ans++;
			}
	printf("%d",ans);
	return 0;
}

