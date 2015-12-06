#include<stdio.h>
#include<algorithm>
#include<cstring>
#define For(i,n) for(int i=1; i<=n; i++)
#define getd(i,j,k) (((i)>=0&&(j)>=0&&(k)>=0)?d[(i)][(j)][(k)]:0)
#define CLR(a) memset(a,0,sizeof(a));
using namespace std;

int r,b,g,MOD,m;
int mark[70],a[70],cnt[70],p=1,n,d[70][70][70]={0};
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
#endif
	scanf("%d%d%d%d%d",&r,&b,&g,&m,&MOD);
	cnt[1]=n=r+g+b;
	m++;
	int ans=0;
	For(t,m){
		For(i,n){
			if(t==1)a[i]=i;
			else scanf("%d",&a[i]);
		}
		CLR(cnt);CLR(d);CLR(mark);
		For(i,n){
			if(mark[i])continue;
			cnt[0]++;
			mark[i]=cnt[cnt[0]]=1;
			int j=a[i];
			while(j!=i){
				mark[j]=1;
				cnt[cnt[0]]++;
				j=a[j];
			}
		}
		d[0][0][0]=1;
		For(cur,n)
			for(int i=r; i>=0; i--)
				for(int j=g; j>=0; j--)
					for(int k=b; k>=0; k--)
						d[i][j][k]=(getd(i-cnt[cur],j,k)+getd(i,j-cnt[cur],k)+getd(i,j,k-cnt[cur]))%MOD;
		ans=(ans+d[r][g][b])%MOD;
	}
	For(i,MOD-2)
		ans=(ans*m)%MOD;
	printf("%d",ans);
	return 0;
}
