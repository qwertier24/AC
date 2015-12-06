#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <iostream>
#define PROB "son"
#define MAXN 2000000000
using namespace std;
struct Fact{
	int f,c;
}facta[200000],factb[200000],factl[200000],factg[200000];
int is_prime[200000],primes[200000],pri_cnt=0;
void Init(){
	int maxn=sqrt(MAXN)+1;
	memset(is_prime,-1,sizeof(is_prime));
	for(int i=2; i*i<=maxn; i++)
		if(is_prime[i])
			for(int j=i*i; j<=maxn; j+=i)
				is_prime[j]=0;
	for(int i=2; i<=maxn; i++)
		if(is_prime[i])
			primes[++pri_cnt]=i;
}
int main(){
	freopen(PROB".in","r",stdin);
	freopen(PROB".out","w",stdout);
	Init();
	int T;
	scanf("%d",&T);
	while(T--){
		int a,g,b,l;
		scanf("%d%d%d%d",&a,&g,&b,&l);
		int lcnt=0,bcnt=0,gcnt=0,acnt=0;
		for(int i=1; primes[i]*primes[i]<=a; i++)
			if(a%primes[i]==0){
				facta[++acnt].f=primes[i];
				facta[acnt].c=0;
				while(a%primes[i]==0){
					a/=primes[i];
					facta[acnt].c++;
				}
			}
		if(a!=1){
			facta[++acnt].f=a;
			facta[acnt].c=1;
		}
		for(int i=1; primes[i]*primes[i]<=g; i++)
			if(g%primes[i]==0){
				factg[++gcnt].f=primes[i];
				factg[gcnt].c=0;
				while(g%primes[i]==0){
					g/=primes[i];
					factg[gcnt].c++;
				}
			}
		if(g!=1){
			factg[++gcnt].f=g;
			factg[gcnt].c=1;
		}
		for(int i=1; primes[i]*primes[i]<=b; i++)
			if(b%primes[i]==0){
				factb[++bcnt].f=primes[i];
				factb[bcnt].c=0;
				while(b%primes[i]==0){
					b/=primes[i];
					factb[bcnt].c++;
				}
			}
		if(b!=1){
			factb[++bcnt].f=b;
			factb[bcnt].c=1;
		}
		for(int i=1; primes[i]*primes[i]<=l; i++){
			if(l%primes[i]==0){
				factl[++lcnt].f=primes[i];
				factl[lcnt].c=0;
				while(l%primes[i]==0){
					l/=primes[i];
					factl[lcnt].c++;
				}
			}
		}
		if(l!=1){
			factl[++lcnt].f=l;
			factl[lcnt].c=1;
		}
		long long ans=1;
		int pa=1,pb=1,pg=1,pl=1;
		for(int i=1; i<=gcnt; i++){
			while(pl<=lcnt&&factl[pl].f<factg[i].f)pl++;
			if(pl>lcnt||factl[pl].f!=factg[i].f){
				ans=0;
			}else if(factl[pl].c<factg[i].c)
				ans=0;
		}
		pl=1;
		int gtimes,ltimes,atimes,btimes;
		for(int i=1; i<=lcnt; i++){
			while(pg<=gcnt&&factg[pg].f<factl[i].f)pg++;
			if(pg>gcnt||factg[pg].f!=factl[i].f)gtimes=0;
			else gtimes=factg[pg].c;
			while(pa<=acnt&&facta[pa].f<factl[i].f)pa++;
			if(pa>acnt||facta[pa].f!=factl[i].f)atimes=0;
			else atimes=facta[pa].c;
			while(pb<=bcnt&&factb[pb].f<factl[i].f)pb++;
			if(pb>bcnt||factb[pb].f!=factl[i].f)btimes=0;
			else btimes=factb[pb].c;
			ltimes=factl[i].c;
			//printf("%d %d %d %d %d\n",factl[i].f,atimes,gtimes,btimes,ltimes);
			if(ltimes>btimes){
				if(min(atimes,ltimes)!=gtimes){
					ans=0;
				}
			}else{
				int cnt=0;
				for(int j=0; j<=ltimes; j++)
					if(min(j,atimes)==gtimes)
						cnt++;
				ans*=cnt;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

