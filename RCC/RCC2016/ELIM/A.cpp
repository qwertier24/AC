#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<queue>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair


#define N 110
int n,T,t0;
int t[N],m[N];
int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif 
    scanf("%d%d%d",&n,&T,&t0);
    FOR(i,n){
        scanf("%d",&m[i]);
        priority_queue<int> pq;
        int sum = 0, ans = 0;
        FOR(j,m[i]){
            scanf("%d",&t[j]);
            pq.push(t[j]);
            sum += t[j];
            if(sum - pq.top() + t0 <= T || sum <= T) 
               ans = j;
        }
        printf("%d\n", ans);
    }
    return 0;
}
