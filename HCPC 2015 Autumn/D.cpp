#include<stdio.h>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<iostream>

#define FOR(i,n) for(int i=1; i<=n; i++)
#define REP(i,n) for(int i=0; i<n; i++)
#define MOD 1000000007

using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

typedef long long LL;

LL f[10010];
int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    f[1]=0;
    f[2]=1;
    for(int i=3; i<=10000; i++)
        f[i]=(f[i-1]*(i-1)%MOD+f[i-2]*(i-1)%MOD)%MOD;
    while(T--){
        int n;
        scanf("%d",&n);
        cout<<f[n]<<endl;
    }
    return 0;
}