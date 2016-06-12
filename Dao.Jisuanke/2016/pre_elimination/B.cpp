#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

#define N 1010

int n, m[N], atk[N][N],tmp[N], def[N];
int id[N];
bool cmp(int i,int j){
    return def[i] < def[j];
}
int get_def(){
    FOR(i,n)id[i]=i;
    sort(id+1, id+n+1, cmp);
    int ret = 0;
    int sum = 0;
    FOR(j,n){
        int i = id[j];
        ret = max(ret, def[i] - sum);
        sum += m[i];
    }
    return ret;
}
void get_min_def(int i){
    def[i] = 0;
    FOR(j,m[i]){
        def[i] = max(def[i], atk[i][j] - j + 1);
    }
}
void print(int x){
    FOR(i,m[x])
        printf("%d%s",atk[x][i],i==m[x]?"\n":" ");
}

int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif 
    scanf("%d",&n);
    FOR(i,n){
        scanf("%d",&m[i]);
        FOR(j,m[i]){
            scanf("%d",&atk[i][j]);
        }
    }
    FOR(i,n){
        get_min_def(i);
    }
    int Q;
    scanf("%d",&Q);
    FOR(i,Q){
        int x,a,b,y;
        scanf("%d%d%d%d",&x,&a,&y,&b);
        memcpy(tmp+1, atk[x]+1, sizeof(atk[x]));
        memcpy(atk[x]+a+1, atk[y]+b+1, sizeof(int)*(m[y] - b));
        memcpy(atk[y]+b+1, tmp+a+1, sizeof(int)*(m[x] - a));
        m[x] = m[x] - a + b;
        m[y] = m[y] - b + a;
        memcpy(tmp, atk[x], sizeof(atk[x]));
        memcpy(atk[x], atk[y], sizeof(atk[x]));
        memcpy(atk[y], tmp, sizeof(tmp));
        get_min_def(x);
        get_min_def(y);
        //print(x);
        //print(y);
        printf("%d\n", get_def());
    }
    return 0;
}
