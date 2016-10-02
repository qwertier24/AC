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
struct edge{
    int u,v,d;
}a[50050];
int minn[55005],mincost;
int ufs[555];
int n,m;
int cmp(const edge & a,const edge & b){
    return a.d < b.d;
}
int findf(int x){
    if (ufs[x] == x) return x;
    else return (ufs[x] = findf(ufs[x]));
}
int check(int x){
    for (int i = 1;i <= n;i++)
	ufs[i] = i;
    int cnt = 0,cost = 0;
    for (int i = 1;i <= m;i++)
	if (i != x){
	    int fu,fv;
	    if ((fu = findf(a[i].u)) != (fv = findf(a[i].v))){
		cnt++;
		cost += a[i].d;
		minn[i] = 1;
		ufs[fu] = fv;
	    }
	}
    if (cnt != n - 1) return 1;
    if (cost == mincost) return 0;
    return 1;
}
int main() {
    //    freopen("in.txt", "r", stdin);
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= m;i++)
	scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].d);
    sort(a + 1,a + m + 1,cmp);
    for (int i = 1;i <= n;i++)
	ufs[i] = i;
    for (int i = 1;i <= m;i++){
	int fu,fv;
	if ((fu = findf(a[i].u)) != (fv = findf(a[i].v))){
	    minn[i] = 1;
	    ufs[fu] = fv;
	    mincost += a[i].d;
	}
    }

    int ans = 0,res = 0;
    for (int i = 1;i <= m;i++)
	if (minn[i] == 1)
	    if (check(i)) ans++ , res += a[i].d;
    printf("%d %d\n",ans,res);
    return 0;
}
close