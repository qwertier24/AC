#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#define PROB "jfecs"
#define val first
#define ord second
using namespace std;
int val[50],d[50][50];
void print_ans(int l,int r){
	if(l>r)return;
	else if(l==r){
		printf("%d ",l);
		return ;
	}
	for(int i=l; i<=r; i++)
		if(d[l][i-1]*d[i+1][r]+val[i]==d[l][r]){
			printf("%d ",i);
			print_ans(l,i-1);
			print_ans(i+1,r);
			return;
		}
}
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&val[i]);
		d[i][i]=val[i];
	}
	for(int i=1; i<=n; i++)
		d[i][i-1]=d[i+1][i]=1;
	for(int i=2; i<=n; i++)
		for(int j=1; j+i-1<=n; j++)
			for(int k=j; k<=j+i-1; k++)
				d[j][j+i-1]=max(d[j][j+i-1],d[j][k-1]*d[k+1][j+i-1]+val[k]);
	printf("%d\n",d[1][n]);
	print_ans(1,n);
	return 0;
}

