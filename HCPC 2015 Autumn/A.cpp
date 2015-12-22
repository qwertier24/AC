#include<stdio.h>
#include<algorithm>
#include<set>
#include<map>
#include<queue>

#define FOR(i,n) for(int i=1; i<=n; i++)
#define REP(i,n) for(int i=0; i<n; i++)

using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

typedef long long LL;
#define N 30

int a[N][N],b[N][N];
int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m,p;
        scanf("%d%d%d",&n,&m,&p);
        REP(i,n)REP(j,m)scanf("%d",&a[i][j]);
        REP(i,m)REP(j,p)scanf("%d",&b[i][j]);
        REP(i,n)REP(j,p){
            int t=0;
            REP(k,m)
                t+=a[i][k]*b[k][j];
            printf("%d%s",t,j==p-1&&i==n-1?"":" ");
        }
        puts("");
    }

    return 0;
}