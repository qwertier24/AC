#include<stdio.h>
#include<algorithm>
#include<set>
#include<map>
#include<queue>

#define FOR(i,n) for(int i=1; i<=n; i++)
#define REP(i,n) for(int i=0; i<n; i++)

using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

typedef long long LL;

char str[4][10]={"Lord","Rebel","Loyal","Traitor"};
int n,hp[110],att[110],id[110];
int find_p(int i,int d){
    int j=i;
    while(d>0){
        j=(j-1+n)%n;
        while(hp[j]==0)
            j=(j-1+n)%n;
        d--;
        //printf("j:%d %d\n",j,hp[j]);
    }
    return j;
}

int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(id,-1,sizeof(id));
        id[0]=0;
        REP(i,n)
            scanf("%d",&hp[i]);
        REP(i,n){
            scanf("%d",&att[i]);
            int j=find_p(i,att[i]);
            //printf("%d %d %d\n",i,att[i],j);
            hp[j]--;
            if(id[j]!=-1 && i!=0 && id[j]!=3)
                id[i]=(id[j]+1)%4;
        }
        REP(i,n)
            if(id[i]==-1)
                puts("Uncertainty");
            else
                printf("%s\n",str[id[i]]);
        puts("");
    }

    return 0;
}
 