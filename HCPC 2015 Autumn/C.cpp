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

int n=4;
char g[5][5];
bool check(){
    REP(i,n-1)REP(j,n-1)
        if(g[i][j]==g[i+1][j+1] && g[i][j]==g[i+1][j] &&g[i][j]==g[i][j+1])
                return true;
    return false;
}
int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--){
        REP(i,n)scanf("%s",g[i]);
        bool flag=false;
        if(check())
            flag=true;
        else{
            REP(i,n)REP(j,n){
                g[i][j]=g[i][j]=='#'?'.':'#';
                if(check())
                    flag=true;
                g[i][j]=g[i][j]=='#'?'.':'#';
            }
        }
        if(flag)puts("YES");
        else puts("NO");
    }

    return 0;
}