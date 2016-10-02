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

char ex[10010];
int main(){
#ifdef QWERTIER
    freopen("g2.in","r",stdin);
    freopen("g2.out","w",stdout);
#endif 
    int T;
    scanf("%d",&T);
    while(T--){
        string ans;
        scanf("%s", ex);
        int n = strlen(ex);
        REP(i,n){
            if(ex[i] <= '9' && ex[i] >= '0'){
                //printf("%c",ex[i]);
                ans += ex[i];
            }
        }
        int p = 0;
        while(p + 1 < ans.size() && ans[p] == '0')
            p++;
        printf("%s\n",ans.c_str() + p);
    }
    return 0;
}
