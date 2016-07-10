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

int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif 
    int n;
    scanf("%d",&n);
    vector<int> left, right;
    FOR(i,n){
        int x;
        char dir;
        scanf("%d %c", &x, &dir);
        if(dir == '-')
            left.push_back(x);
        else
            right.push_back(x);
    }
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    if(left.size() == 0 || right.size() == 0){
        puts("1");
    }else{
        int ll = *left.begin(), rr = *right.rbegin();
        if(ll >= rr){
            puts("1");
        }else
            puts("2");
    }
    return 0;
}
