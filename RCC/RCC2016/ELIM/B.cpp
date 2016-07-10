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

int n,m,T;
int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif 
    int T;
    scanf("%d", &T);
    while(T--){
        map<int,vector<int> > xc;
        scanf("%d%d",&m,&n);
        int cur = 0;
        FOR(i,n){
            int x,y;
            scanf("%d%d",&x,&y);
            xc[x].push_back(y);
        }
        int ans= 0 ,ax=1,ay=m-1;
        priority_queue<int> pq;
        for(auto it = xc.begin(); it!=xc.end(); ++it){
            for(auto &y : it->second){
                pq.push(y);
            }
            while(!pq.empty() && pq.top() > m - it->first)
                pq.pop();
            if(pq.size() > ans){
                ax = it->first;
                ay = m - it->first;
                ans = pq.size();
            }
        }
        printf("%d %d\n", ax, ay);
    }
    return 0;
}
