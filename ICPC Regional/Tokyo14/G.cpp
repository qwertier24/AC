#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, n) for(int i = 1; i <= n; i++)

typedef long long ll;
typedef pair<int,int> pii;
#define first fi
#define second se

#ifdef LOCAL
#define err(x) cerr << #x << ":" << x << endl
#else
#define err(x)
#endif
char s[300300];
int d[303000];
int sum[303000];
int a[2003000];
int add[2003000];
int rt[2003000];
int n,q;
void upd(int o){
    a[o] = min(a[o * 2],a[o * 2 + 1]);
    rt[o] = rt[o * 2 + 1];
}
void build(int o,int l,int r){
    if (l == r){
	a[o] = sum[l];rt[o] = sum[l];return;
    }
    int mid = (l + r) >> 1;
    build(o * 2,l,mid);
    build(o * 2 + 1, mid + 1, r);
    upd(o);
}
void addd(int o,int d){
    rt[o] += d;a[o] += d;add[o] += d;
}
void pd(int o){
    addd(o * 2,add[o]);
    addd(o * 2 + 1,add[o]);
    add[o] = 0;
}
int query(int o, int l, int r){
    if (l == r){
	return l;
    }
    pd(o);
    int mid = (l + r) >> 1;
    if (rt[o * 2] < mid)
	return query(o * 2,l,mid);
    else return query(o * 2 + 1,mid + 1,r);
}
void modify(int o,int l,int r,int ln,int rn,int d){
    if (ln <= l && r <= rn){
	addd(o,d);
	return;
    }
    pd(o);
    int mid = (l + r) >> 1;
    if (ln <= mid)
	modify(o * 2,l,mid,ln,rn,d);
    if (mid < rn)
	modify(o * 2 + 1,mid + 1,r,ln,rn,d);
    upd(o);
}
int que(int o,int l,int r){
    if (l == r) return l;
    pd(o);
    int mid = (l + r) >> 1;
    if (a[o * 2 + 1] >= 2)
	return que(o * 2,l,mid);
    else return que(o * 2 + 1,mid + 1,r);
}
int main() {
    //    freopen("in.txt", "r", stdin);
    scanf("%d%d",&n,&q);
    scanf("%s",s + 1);
    for (int i = 1;i <= n;i++)
	if (s[i] == '(') d[i] = 1;
	else d[i] = -1;
    for (int i = 1;i <= n;i++)
	sum[i] = sum[i - 1] + d[i];
    build(1,1,n);
    for (int i = 1;i <= q;i++){
	int pos,ans;
	scanf("%d",&pos);
	if (d[pos] == 1){
	    d[pos] = -1;
	    modify(1,1,n,pos,n,-2);
	    ans = query(1,1,n);
	    modify(1,1,n,ans,n,2);
	    d[ans] = 1;
	}else {
	    d[pos] = 1;
	    modify(1,1,n,pos,n,2);
	    ans = que(1,1,n);
	    ans++;
	    modify(1,1,n,ans,n,-2);
	    d[ans] = -1;
	}
	printf("%d\n",ans);
    }
    return 0;
}
close