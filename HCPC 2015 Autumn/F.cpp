#include<stdio.h>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<iostream>

#define FOR(i,n) for(int i=1; i<=n; i++)
#define REP(i,n) for(int i=0; i<n; i++)

using namespace std;

typedef pair<int,int> pii;
#define MP make_pair

typedef long long LL;

char str1[8][20]={"Killing spree!","Dominating!","Mega kill!","Unstoppable!" ,"Wicked sick!","Monster kill!","God like!" ,"Holy shit!" };
char str2[5][20]={"First blood!" ,"Double kill!" ,"Triple kill!","Ultra kill!","Rampage!"};

struct Event{
    string p1,p2;
    int vali,ti;
}event[1010];

int main(){
#ifdef QWERTIER
    freopen("in.txt","r",stdin);
#endif
    int T,n,m;
    scanf("%d",&T);
    while(T--){
        map<string,int> cnt1;
        map<string,int> id;
        scanf("%d%d",&n,&m);
        string name;
        REP(i,n){
            cin>>name;
            id[name]=0;
        }
        REP(i,n){
            cin>>name;
            id[name]=1;
        }
        bool fb=true;
        REP(i,m){
            cin>>event[i].ti>>event[i].p1>>event[i].p2;
            if(id[event[i].p1]==id[event[i].p2]){
                event[i].vali=0;
                continue;
            }
            event[i].vali=1;
            cnt1[event[i].p1]++;
            cnt1[event[i].p2]=0;
            if(cnt1[event[i].p1] > 2){
                printf("%d ",event[i].ti);
                puts(str1[min(7,cnt1[event[i].p1]-3)]);
            }

            map<string,int> cnt2;
            cnt2.clear();
            cnt2[event[i].p1]++;
            int lst=event[i].ti;
            for(int j=i-1; j>max(-1,i-5); j--)
                if(event[j].p1==event[i].p1 && event[j].ti>=lst-12 && event[j].vali){
                    //printf("%d %d %d\n",i,j,cnt2[event[j].p1]);
                    lst=event[j].ti;
                    cnt2[event[j].p1]++;
                }
            //printf("cnt2:%d\n",cnt2[event[i].p1]);
            if(cnt2[event[i].p1]>1){
                printf("%d ",event[i].ti);
                puts(str2[min(4,cnt2[event[i].p1]-1)]);
            }
            if(fb){
                printf("%d ",event[i].ti);
                puts(str2[0]);
                fb=false;
            }
        }
        puts("");
    }
    return 0;
}
 