#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <iostream>
#define For(i,b,e) for(int i=b; i<=e; i++)
using namespace std;
int n;
char s[110];
int g[110][110];
int get_digit(char t){
	if(t=='B')
		return -10;
	else if(t=='J')
		return 1;
	else
		return 0;
}
int get_g(int x,int y){
	if(x<1||y<1||x>n||y>n)
		return -10;
	else
		return g[x][y];	
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	int ans=0;
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%s",s+1);
		for(int j=1; j<=n; j++){
			g[i][j]=get_digit(s[j]);
			//printf("%d ",g[i][j]);
		}
		//printf("\n");
	}
	for(int x=2; x<=n; ++x)
		for(int y=2; y<=n; ++y)
			if(g[x][y]>=0)
				for(int x2=1; x2<=x; ++x2)
					for(int y2=1; y2<y; ++y2){
						//if(x==100&&y==100&&x2==100&&y2==1)
							//printf("%d %d %d %d\n",g[x][y],g[x2][y2],g[x+y-y2][y-x+x2],g[x2+y-y2][y2-2+x2]);
						if(g[x][y]+g[x2][y2]+get_g(x-y+y2,y+x-x2)+get_g(x2-y+y2,y2+x-x2)>=3)
							ans=max(ans,(x-x2)*(x-x2)+(y-y2)*(y-y2));
					}
	printf("%d",ans);
	return 0;
}

