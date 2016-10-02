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
int n,m;
struct seg{
    int l,r;
}a[555],b[555];
int del[555],cnt;
int cmp(const seg & a,const seg & b){
    return a.l < b.l || (a.l == b.l && a.r < b.r);
}
stack <seg> S;
int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= m;i++)
	scanf("%d%d",&a[i].l,&a[i].r);
    for (int i = 1;i <= m;i++)
	for (int j = i + 1;j <= m;j++)
	    if (!del[i] && !del[j]){
		if (a[i].l <= a[j].l && a[i].r >= a[j].r)
		    del[j] = 1;
		if (a[j].l <= a[i].l && a[j].r >= a[i].r)
		    del[i] = 1;
	    }
    cnt = 0;
    for (int i = 1;i <= m;i++)
	if (!del[i])
	    b[++cnt] = a[i];
    sort(b + 1,b + cnt + 1,cmp);
    int ans = n + 1;
    for (int i = 1;i <= cnt;i++)
	if (S.empty()){
	    S.push(b[i]);
	}else {
	    seg u;
	    while (true){
		if (S.empty()) {S.push(b[i]);break;}
		u = S.top();
		if (u.r >= b[i].l){
		    b[i].l = min(b[i].l,u.l);
		    S.pop();
		}else {S.push(b[i]);break;}
	    }
	}
    while (!S.empty()){
	seg u = S.top();
	ans += 2 * (u.r - u.l);
	S.pop();
    }
    printf("%d\n",ans);
    return 0;
}