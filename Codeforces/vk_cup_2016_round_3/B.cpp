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
int a,b,c,d,mark[N],n,k;
int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif 
    scanf("%d%d%d%d%d%d",&n,&k,&a,&b,&c,&d);
    if(n==4){
        puts("-1");
        return 0;
    }
    if(k<n+1){
        puts("-1");
        return 0;
    }
    mark[a]=mark[b]=mark[c]=mark[d]=1;
    vector<int> e;
    FOR(i,n)if(!mark[i]){
        e.push_back(i);
    }

    printf("%d %d ",a,c);
    for(auto &u : e){
        printf("%d ",u);
    }
    printf("%d %d\n",d,b);
    
    printf("%d %d ",c,a);
    for(auto &u : e){
        printf("%d ",u);
    }
    printf("%d %d\n",b,d);
    return 0;
}
