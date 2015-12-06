#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#define PROB
#define fi first
#define se second
using namespace std;
#define N 110
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
#define MP make_pair

int n,m;
typedef pair<int,int> pii;
vector<pii> v;
bool cmp(const pii& a,const pii& b){
	return a.fi*a.se>b.fi*b.se;
}

int a[N][N],b[N][N];
bool check(int r,int c){
	memcpy(b,a,sizeof(a));
	For(i,n)For(j,m)if(b[i][j]){
		for(int k=i+r-1; k>=i; k--)
			for(int l=j+c-1; l>=j; l--){
				if(b[k][l]<b[i][j])return false;
				b[k][l]-=b[i][j];
			}
	}
	return true;
}
int main(){
	int sum=0;
	//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&m);
	For(i,n)For(j,m){
		scanf("%d",&a[i][j]);
		sum+=a[i][j];
	}
	For(i,n)For(j,m)if(sum%(i*j)==0)
		v.push_back(MP(i,j));
	sort(v.begin(),v.end(),cmp);
	Rep(i,v.size())
		if(check(v[i].fi,v[i].se)){
			printf("%d\n",sum/v[i].fi/v[i].se);
			return 0;
		}
	return 0;
}

