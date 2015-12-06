#include <stdio.h>
#define maxn 1000010
#define For(i,b,e) for(int i=b; i<=e; i++)
int l[maxn],r[maxn],cap[maxn],dec[maxn],cnt[maxn]={0};
int main(){
	freopen("classrooms.in","r",stdin);
	freopen("classrooms.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	For(i,1,n)
		scanf("%d",&cap[i]);
	For(i,1,m){
		scanf("%d%d%d",&dec[i],&l[i],&r[i]);
		cnt[l[i]]+=dec[i];
		cnt[r[i]+1]-=dec[i];
	}
	int cur=m,a=0;
	For(i,1,n){
		a+=cnt[i];
		//printf(" %d %d %d\n",i,a,cap[i]);
		while(cur>=1&&a>cap[i]){
			if(i>=l[cur]&&i<=r[cur])a-=dec[cur];
			cnt[l[cur]]-=dec[cur];
			cnt[r[cur]+1]+=dec[cur];
			cur--;
		}
		//printf(" %d %d %d %d\n",i,a,cap[i],cur);
	}
	if(cur==m)
		printf("0\n");
	else
		printf("-1\n%d\n",cur+1);
	return 0;
}

