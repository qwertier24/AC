#include<stdio.h>
#define N 100010

int n,m;
typedef long long LL;
struct BIT{
#define lowbit(x) (x&(-x))
	LL val[N];
	void add(int p,LL v){
		while(p<=n){
			val[p]+=v;
			p+=lowbit(p);
		}
	}
	LL sum(int p){
		LL ret=0;
		while(p){
			ret+=val[p];
			p-=lowbit(p);
		}
		return ret;
	}
}t1,t2;

int a[N];
char op[10];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		t1.add(i,a[i]);
		t2.add(i,(i-1)*(LL)a[i]);
	}
	while(m--){
		int i,v;
		scanf("%s",op);
		if(op[0]=='M'){
			scanf("%d%d",&i,&v);
			t1.add(i,v-a[i]);
			t2.add(i,(i-1)*(LL)(v-a[i]));
			a[i]=v;
		}else{
			scanf("%d",&i);
			printf("%lld\n",i*t1.sum(i)-t2.sum(i));
		}
	}
	return 0;
}
