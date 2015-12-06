#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int n;
double x[20][20],m[20][20]={0};
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%lf",&x[0][i]);
	for(int i=1; i<=n; i++)
		for(int j=0; j<n; j++){
			scanf("%lf",&x[i][j]);
			m[i-1][j]=2*(x[i-1][j]-x[i][j]);
			m[i-1][n]+=x[i-1][j]*x[i-1][j]-x[i][j]*x[i][j];
		}
	for(int i=0; i<n; i++){
		int c=i;
		for(int j=i; j<n; j++)if(fabs(m[j][i])>fabs(m[c][i]))c=j;
		for(int j=0; j<=n; j++)swap(m[i][j],m[c][j]);
		for(int j=i+1; j<n; j++){
			double f=m[j][i]/m[i][i];
			for(int k=i; k<=n; k++)
				m[j][k]-=f*m[i][k];
		}
	}
	for(int i=n-1; i>=0; i--){
		for(int j=i+1; j<n; j++)
			m[i][n]-=m[j][n]*m[i][j];
		m[i][n]/=m[i][i];
	}
	for(int i=0; i<n-1; i++)
		printf("%.3f ",m[i][n]);
	printf("%.3f\n",m[n-1][n]);
	while(true);
	return 0;
}
