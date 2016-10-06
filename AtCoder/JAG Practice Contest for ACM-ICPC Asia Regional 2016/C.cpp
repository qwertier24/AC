#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, n) for(int i = 1; i <= n; i++)

typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pii pair<int, int>
#define piis pair<pii, string>

#ifdef LOCAL
#define err(x) cerr << #x << ":" << x << endl
#else
#define err(x)
#endif
char s[22];
piis a[50500];
int rt;
set <piis> act,iact;
map <string, pii> nm;
int n,m;
int main() {
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d\n",&n);
    for (int i = 1;i <= n;i++){
        int d;
        scanf("%s %d\n",s,&d);
        a[i] = make_pair(make_pair(-d, -i), string(s));
        nm[a[i].se] = a[i].fi;
    }
    rt = (int)(n / 5.0);
    sort(a + 1, a + n + 1);
    /*   for (int i = 1;i <= n;i++)
         cout << a[i].se << endl;*/
    for (int i = 1;i <= rt;i++)
        act.insert(a[i]);
    for (int i = rt + 1;i <= n;i++)
        iact.insert(a[i]);
    scanf("%d\n",&m);
    int nn = n;
    for (int tt = 1;tt <= m;tt++){
        char o;
        scanf("%c",&o);
        if (o == '+'){
            int d;
            scanf(" %s %d\n", s, &d);

            int flag = 1;
            piis person = make_pair(make_pair(-d, -(n + tt)), string(s));
            nm[person.se] = person.fi;
            if (act.size() > 0 && *act.rbegin() > person){
                flag = 0;
                printf("%s is working hard now.\n", s);
                act.insert(person);
            }
            nn++;
            rt = (int)(nn/5.0);
            if ((int)act.size() > rt){
                if (flag){
                    printf("%s is not working now.\n", s);
                    iact.insert(person);
                    flag = 0;
                }
                person = *act.rbegin();
                act.erase(person);
                iact.insert(person);
                printf("%s is not working now.\n",person.se.c_str());
            }else if ((int)act.size() < rt){
                if (flag && *iact.begin() > person){
                    flag = 0;
                    printf("%s is working hard now.\n", s);
                    act.insert(person);
                }else {
                    if (flag){
                        printf("%s is not working now.\n", s);
                        iact.insert(person);
                        flag = 0;
                    }
                    piis per = *iact.begin();
                    iact.erase(per);
                    act.insert(per);
                    printf("%s is working hard now.\n",per.se.c_str());
                }
            }
            if (flag){
                printf("%s is not working now.\n", s);
                iact.insert(person);
            }
            
        }else {
            scanf(" %s\n",s);
            string pnm = string(s);
            piis person = make_pair(nm[pnm], pnm);
            if (act.lower_bound(person) != act.end() &&
                *act.lower_bound(person) == person){
                act.erase(person);
            }else
                iact.erase(person);

            nn--;
            rt = (int)(nn / 5.0);
            if ((int)act.size() < rt){
                piis per = *iact.begin();
                iact.erase(per);
                act.insert(per);
                printf("%s is working hard now.\n",per.se.c_str());
            }else if ((int)act.size() > rt){
                piis per = *act.rbegin();
                act.erase(per);
                iact.insert(per);
                printf("%s is not working now.\n",per.se.c_str());
            }
        }
        
    }
    return 0;
}
