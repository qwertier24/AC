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
    int d,ord;
}a[606000];
int in[606000];

int cmp(const node & a,const node & b){
    return a.d < b.d;
}
int n,K;
int main() {
    scanf("%d%d",&n,&K);
    for (int i = 1;i <= K;i++)
	scanf("%d",&a[i].d),a[i].ord = i;
    
    sort(a + 1,a + K + 1,cmp);
    for (int i = 1;i <= K;i++)
	in[a[i].d] = a[i].ord;


    int o = 0,ans1,ans2;
    for (int i = 1;i <= K;i++){
	for (int j = 2;j * a[i].d <= n;j++)
	    if (in[j * a[i].d]){
		ans1 = a[i].ord,ans2 = in[j * a[i].d];
		o = 1;break;
	    }
	if (o) break;
    }
    if (o)
	printf("%d %d\n",ans2,ans1);
    else printf("0 0\n");
    return 0;
}
close