#include<stdio.h>
#include<algorithm>
#define maxn 200000

using namespace std;

int maxv[400000]={0},sett,L,R,P,_max;
void set(int o,int l,int r){
	if(l==r){
		maxv[o]=sett;
		return;
	}
	int m=(l+r)>>1;
	if(P<=m)set(o<<1,l,m);
	else set(o<<1|1,m+1,r);
	maxv[o]=max(maxv[o<<1],maxv[o<<1|1]);
}
void Set(int p,int val){
	P=p;
	sett=val;
	set(1,1,maxn);
}
void query(int o,int l,int r){
	if(L<=l&&R>=r){
		_max=max(_max,maxv[o]);
		return;
	}
	int m=(l+r)>>1;
	if(L<=m)query(o<<1,l,m);
	if(R>m)query(o<<1|1,m+1,r);
}
int Query(int l,int r){
	_max=0;
	L=l,R=r;
	query(1,1,maxn);
	return _max;
}
int main(){
	int n=0,mod,t=0,num,opt_n;
	char opt[10];
	scanf("%d%d",&opt_n,&mod);
	for(int i=1; i<=opt_n; i++){
		scanf("%s%d",opt,&num);
		if(opt[0]=='A'){
			n++;
			num=(num+t)%mod;
			Set(n,num);
		}else{
			t=Query(n-num+1,n);
			printf("%d\n",t);
		}
	}
} 
