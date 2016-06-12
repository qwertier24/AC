#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<math.h>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif 
    int n,k;
    double l;
    scanf("%d%d%lf",&n,&k,&l);
    double ans = 0;
    double deg = acos(-1.0) * (n-2) / n;
    REP(i,k+1){
        ans += (n-1)*l + l/2;
        if(i == k)
            ans -= l/2;
        l = l / 2 * sin(deg / 2) * 2;
    }
    printf("%.10f\n",ans);
    return 0;
}
