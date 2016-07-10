#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<map>
#include<set>
#include<vector>
#include<string>
#include<iostream>
#define REP(i,n) for(int i=0; i<n; i++)
#define FOR(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

typedef pair<int,int> pii;
#define MP make_pair


char c0;
LL ran(){
    LL ret = 0;
    FOR(i,4)
        ret = ret * RAND_MAX + rand();
    if(ret < 0)
        ret *= -1;
    return ret;
}
LL getRand(int len){
    return rand() % len;
}
char get(LL x){
    cout<<x<<endl<<flush;
    char c;
    cin>>c;
    return c;
}
#define SZ 300
bool check(LL L,LL R, char c){
    LL len = R - L + 1;
    //cout<<'L'<<L<<'R'<<R<<endl;
    if(len <= SZ){
        for(LL i = L; i <= R; i++)
            if(get(i) != c)
                return false;
    }else{
        FOR(i,SZ){
            int x = getRand(len) + L;
            if(get(x) != c)
                return false;
        }
    }
    //cout<<"true"<<endl;
    return true;
}
LL findL(){
    LL lo = -100000000000000007ll, hi = 0;
    while(lo < hi){
        LL mi = (lo + hi) >> 1;
        //cout<<lo<<' '<<mi<<' '<<hi<<endl;
        if(check(mi, -1, c0))
            hi = mi;
        else
            lo = mi + 1;
    }
    return lo;
}
LL findR(){
    LL hi = 100000000000000007ll, lo = 0;
    while(lo < hi){
        LL mi = (lo + hi + 1)>> 1;
        if(check(1, mi, c0))
            lo = mi;
        else
            hi = mi - 1;
    }
    return lo;
}
int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif 
    c0 = get(0);
    cout<<"! "<<findR()-findL()+1<<endl<<flush;
    return 0;
}
