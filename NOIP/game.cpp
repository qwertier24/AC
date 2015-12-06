#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
struct Bign{
	int len,num[100];
	Bign(){
		len=0;
		memset(num,0,sizeof(num));
	}
	bool operator<(const Bign& rhs)const{
		if(rhs.len==len){
			int i;
			for(i=len; i>=1&&num[i]==rhs.num[i]; i--){}
			return num[i]<rhs.num[i];
		}else return len<rhs.len;
	}
	Bign operator+(const Bign& t){
		Bign ret;
		ret.len=max(len,t.len);
		int c=0;
		for(int i=1; i<=ret.len||c; i++){
			if(i>ret.len)ret.len=i;
			ret.num[i]=num[i]+t.num[i]+c;
			c=ret.num[i]/10;
			ret.num[i]%=10;
		}
		return ret;
	}
	Bign operator*(const Bign& t){
		Bign ret;
		for(int i=1; i<=len; i++)
			for(int j=1; j<=t.len; j++)
				ret.num[i+j-1]+=num[i]*t.num[j];
		ret.len=t.len+len-1;
		int c=0;
		for(int i=1; i<=ret.len||c; i++){
			ret.len=max(ret.len,i);
			ret.num[i]+=c;
			c=ret.num[i]/10;
			ret.num[i]%=10;
		}
		return ret;
	}
	void Init(int t){
		while(t){
			num[++len]=t%10;
			t/=10;
		}
	}
	void print(){
		for(int i=len; i>=1; i--)
			printf("%d",num[i]);
		printf("\n");
	}
}ans,pow2[100],d[100][100];
int g[100][100]={0};
void Init(){
	pow2[1].Init(2);
	Bign two;
	two.Init(2);
	for(int i=2; i<=80; i++)
		pow2[i]=pow2[i-1]*two;
}
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	Init();
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			scanf("%d",&g[i][j]);
	for(int i=1; i<=n; i++){
		for(int len=1; len<=m; len++)
			for(int j=1; j+len-1<=m; j++){
				int k=j+len-1;
				if(j==k){
					Bign t;
					t.Init(g[i][j]);
					d[j][k]=t*pow2[m];
				}else{
					Bign tl,tr;
					tl.Init(g[i][j]);
					tr.Init(g[i][k]);
					d[j][k]=max(d[j][k-1]+tr*pow2[m-k+j],d[j+1][k]+tl*pow2[m-k+j]);
				}
			}
		ans=ans+d[1][m];
	}
	if(ans.len)
		ans.print();
	else
		printf("0\n");
	return 0;
}
