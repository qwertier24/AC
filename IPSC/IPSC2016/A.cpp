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

const int n = 10;
char s[20][10];
string ans;
vector<int> adj[n];
int vis[n];
bool check(char *s, char *t,int l){
    REP(i,l)
        if(s[i] != t[i])
            return false;
    return true;
}
int main(){
#ifdef QWERTIER
    freopen("a2.in","r",stdin);
    freopen("a2.out","w",stdout);
#endif 
    int T;
    scanf("%d",&T);
    while(T--){
        ans.clear();
        int flag = 0;
        REP(i,n)
            scanf("%s",s[i]);
        REP(i,n){
            REP(j,n){
                REP(k,4)
                    if(i!=j && !flag && check(s[i]+k,s[j],4-k)){
                        s[i][k] = 0;
                        ans+=s[i];
                        s[i][0] = 0;
                        flag = 1;
                        ans+=s[j];
                        s[j][0]=0;
                    }
            }
        }
        if(!flag)
            return -1;
        REP(i,n)
            ans += s[i];
        REP(i,n)
            if(strstr(ans.c_str(), s[i]) == NULL){
                return -1;
            }
        if(ans.size() > 39)
            return -1;
        while(ans.size() < 39)
            ans+='A';
        printf("%s\n", ans.c_str());
    }
    return 0;
}
