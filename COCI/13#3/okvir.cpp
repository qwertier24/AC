#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m,u,l,r,d;
char ans[110][110],s[110][110];
int main(){
	scanf("%d%d%d%d%d%d",&n,&m,&u,&l,&r,&d);
	for(int i=0; i<n; i++)
		scanf("%s",s[i]);
	int width=l+m+r,height=u+n+d;
	for(int i=0; i<height; i++)
		for(int j=0; j<width; j++){
			if((i+j)%2)
				ans[i][j]='.';
			else
				ans[i][j]='#';
		}
	for(int i=u; i<u+n; i++)
		for(int j=l; j<l+m; j++)
			ans[i][j]=s[i-u][j-l];
	for(int i=0; i<height; i++)
		printf("%s\n",ans[i]);
	return 0;
}
