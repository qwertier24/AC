#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <ctype.h>
#define For(i,n) for(int i=1; i<=n; i++)
#define Rep(i,n) for(int i=0; i<n; i++)
using namespace std;
int pass;

void readint(int &x){
	x=0;
	char c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
}
#define N 100010
int n;

int val[N];
#define lowbit(x) (x&(-x))
void add(int p,unsigned int v){
	while(p<=n){
		val[p]+=v;
		p+=lowbit(p);
	}
}
int getsum(int p){
	int ret=0;
	while(p){
		ret+=val[p];
		p-=lowbit(p);
	}
	return ret;
}

int X[N],Y[N],xc[N],yc[N],mx,my,k;
vector<int> line[N];
int sum[N],a[N];
int c[N][20],C[N],ans;
int main(){
	freopen("in.txt","r",stdin);
	readint(pass);readint(pass);
	readint(n);
	For(i,n){
		readint(X[i]);readint(Y[i]);
		xc[++mx]=X[i];
		yc[++my]=Y[i];
	}
	readint(k);
	for(int i=0; i<=n; i++){
		c[i][0]=1;
		for(int j=1; j<=k; j++)
			c[i][j]=c[i-1][j-1]+c[i-1][j];
		C[i]=c[i][k];
	}
	sort(xc+1,xc+mx+1);
	mx=unique(xc+1,xc+mx+1)-xc-1;
	sort(yc+1,yc+my+1);
	my=unique(yc+1,yc+my+1)-yc-1;
	For(i,n){
		X[i]=lower_bound(xc+1,xc+mx+1,X[i])-xc;
		Y[i]=lower_bound(yc+1,yc+my+1,Y[i])-yc;
		line[X[i]].push_back(Y[i]);
		sum[Y[i]]++;
	}
	For(x,mx){
		sort(line[x].begin(),line[x].end());
		Rep(j,line[x].size()){
			int &y=line[x][j];
			if(a[y]>=k && sum[y]-a[y]>=k)
				add(y,C[a[y]]*-C[sum[y]-a[y]]);
		}
		for(int j=k-1; j<=int(line[x].size())-k-1; j++){
			int y1=line[x][j]+1,y2=line[x][j+1]-1;
			if(y1>y2)continue;
			ans+=(getsum(y2)-getsum(y1-1))*C[j+1]*C[line[x].size()-j-1];
		}
		Rep(j,line[x].size()){
			int &y=line[x][j];
			a[y]++;
			if(a[y]>=k && sum[y]-a[y]>=k)
				add(y,C[a[y]]*C[sum[y]-a[y]]);
		}
	}
	if(ans<0)ans+=1<<31;
	printf("%d\n",ans);
	return 0;
}

