#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

const int n=131072;

#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
int setv[n<<4],revv[n<<4],L,R,sett;
void pushdown(int o){
	if(setv[o]!=-1){
		setv[lc]=setv[rc]=setv[o];
		revv[lc]=revv[rc]=0;
		setv[o]=-1;
	}
	if(revv[o]){
		revv[lc]^=1;
		revv[rc]^=1;
		revv[o]=0;
	}
}
void set(int o,int l=0,int r=n-1){
	if(L<=l&&r<=R){
		revv[o]=0;
		setv[o]=sett;
		return;
	}
	pushdown(o);
	if(L<=mid)set(lc,l,mid);
	if(R>mid)set(rc,mid+1,r);
}
void Set(int l,int r,int v){
	if(l>r)return;
	L=l,R=r,sett=v;
	set(1);
}
void rev(int o,int l=0,int r=n-1){
	if(L<=l&&r<=R){
		revv[o]^=1;
		return;
	}
	pushdown(o);
	if(L<=mid)rev(lc,l,mid);
	if(R>mid)rev(rc,mid+1,r);
}
void Rev(int l,int r){
	if(l>r)return;
	L=l,R=r;
	rev(1);
}
int P;
int query(int o,int l=0,int r=n-1){
	if(l==r)
		return setv[o]^revv[o];
	pushdown(o);
	if(P<=mid)return query(lc,l,mid);
	else return query(rc,mid+1,r);
}
int Query(int p){
	P=p;
	return query(1);
}
void print(int l,int r){
	if(l&1)putchar('(');
	else putchar('[');
	printf("%d,%d",l/2,r/2+r%2);
	if(r&1)putchar(')');
	else putchar(']');
}
char op[10],interval[100];
int l,r,ans[n];
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	memset(setv,-1,sizeof(setv));
	setv[1]=0;
	while(scanf("%s%s",op,interval)!=EOF){
		int sz=strlen(interval);
		sscanf(interval+1,"%d,%d",&l,&r);
		l<<=1;r<<=1;
		if(interval[0]=='(')l++;
		if(interval[sz-1]==')')r--;
		if(op[0]=='U'){
			Set(l,r,1);
		}else if(op[0]=='I'){
			if(l>r){
				Set(0,n-1,0);
			}else{
				Set(0,l-1,0);
				Set(r+1,n-1,0);
			}
		}else if(op[0]=='D'){
			Set(l,r,0);
		}else if(op[0]=='C'){
			Set(0,l-1,0);
			Set(r+1,n-1,0);
			Rev(l,r);
		}else{
			Rev(l,r);
		}
	}
	for(int i=0; i<n; i++)
		ans[i]=Query(i);
	int lpos=-1,flag=0;
	for(int i=0; i<n; i++){
		if(ans[i]){
			if(lpos==-1)lpos=i;
			if(i+1==n || !ans[i+1]){
				if(!flag)flag=1;
				else putchar(' ');
				print(lpos,i);
				lpos=-1;
			}
		}
	}
	if(!flag)printf("empty set");
	return 0;
}

