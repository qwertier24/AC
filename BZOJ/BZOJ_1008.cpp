#include<stdio.h>
#include<algorithm>
#define N 50000
#define For(i,n) for(int i=1; i<=n; i++)
using namespace std;

struct Line{
	int k,b,ord;
	bool operator<(const Line& rhs)const{
		return k<rhs.k||(k==rhs.k&&b>rhs.b);
	}
}l[N+10];

int st[N+10],top=0;

bool check(const Line& l1,const Line& l2,const Line& l0){
	return (l1.b-l0.b)*((long long)l0.k-l2.k)<=(l2.b-l0.b)*((long long)l0.k-l1.k);
}
bool cmp(const int& a,const int& b){
	return l[a].ord<l[b].ord;
}
int n;
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.txt","r",stdin);
#endif
	scanf("%d",&n);
	For(i,n){
		l[i].ord=i;
		scanf("%d%d",&l[i].k,&l[i].b);
	}
	sort(l+1,l+n+1);
	For(i,n){
		while(top>1&&check(l[i],l[st[top]],l[st[top-1]]))
			top--;
		st[++top]=i;
	}
	sort(st+1,st+top+1,cmp);
	For(i,top)
		printf("%d ",l[st[i]].ord);
	return 0;
}
