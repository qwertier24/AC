#include<stdio.h>
#include<algorithm>
#include<iostream>
#define N 10010
#define For(i,n) for(int i=1; i<=n; i++)

typedef long long LL;
using namespace std;

int n,m,sum[N];
LL ans;
int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    scanf("%d%d",&n,&m);
    For(i,n){
        scanf("%d",&sum[i]);
        sum[i]<<=1;
    }
    For(i,m){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        sum[u]+=w;
        sum[v]+=w;
    }
    sort(sum+1,sum+n+1);
    reverse(sum+1,sum+n+1);
    For(i,n){
        if(i&1)ans+=sum[i];
        else ans-=sum[i];
    }
    cout<<ans/2;
    return 0;
}
