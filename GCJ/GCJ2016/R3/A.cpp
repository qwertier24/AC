#include <bits/stdc++.h>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;
typedef pair<int,int> pii;
#define MP make_pair

char s[100010];
int main(){
#ifdef QWERTIER
    freopen("A_l.in","r",stdin);
    freopen("A_l.out","w",stdout);
#endif 
    int T;
    scanf("%d",&T);
    FOR(kase,T){
        printf("Case #%d: ", kase);
        scanf("%s",s);
        int n = strlen(s);
        char lst = -1;
        vector<pii> v;
        REP(i,n){
            if(lst == s[i])
                v.rbegin()->first ++;
            else{
                lst = s[i];
                v.push_back(MP(1,s[i]=='C'));
            }
        }
        int ans = 0;
        while(true){
            vector<pii> t;
            REP(i, (int)v.size()){
                ans += v[i].first / 2 * 10;
                if(v[i].first % 2 == 0){
                    continue;
                }else{
                    t.push_back(MP(v[i].first % 2, v[i].second));
                }
            }
            int lst = -1;
            v.clear();
            REP(i,(int)t.size()){
                if(lst == t[i].second){
                    v.rbegin()->first ++;
                }else{
                    lst = t[i].second;
                    v.push_back(MP(t[i].first,lst));
                }
            }
            bool flag = false;
            REP(i,(int)v.size()){
                //printf("%d %d\n",v[i].first,v[i].second);
                if(v[i].first > 1)
                    flag = true;
            }
            if(!flag)
                break;
        }
        printf("%d\n",ans + (int)v.size() / 2 * 5);
    }
    return 0;
}
