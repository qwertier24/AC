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
struct node{
    int d;char c;
}a[1111];
int n;
int cmp(const node & a,const node & b){
    return a.c < b.c || (a.c == b.c && a.d > b.d);
}
int main() {
    scanf("%d",&n);
    for (int i = 1;i <= n;i++){
	scanf("%d%c",&a[i].d,&a[i].c);
    }
    sort(a + 1, a + n + 1,cmp);
    int len = 1;
    while (len < n && a[len + 1].c == a[len].c) len++;
    if (len == n) printf("0\n");
    else {
	int mlen = min(len,n - len);
	int ans = 0;
	for (int i = 1;i <= mlen;i++)
	    ans += a[len + i].d + a[i].d;
	printf("%d\n",ans - mlen * 2);
    }
    return 0;
}