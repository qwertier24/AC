#include<stdio.h>
#include<string.h>
#define REP(i,b,e) for(int i=b; i<=e; i++)
#define RREP(i,b,e) for(int i=b; i>=e; i--)

typedef long long LL;
#define N 210

inline int gcd(int a,int b){
	int c;
	while(a){
		c=a;
		a=b%a;
		b=c;
	}
	return b;
}

int n,m,g,a,b[210];
struct BIGN{
	int num[1010],len;
	void init(){
		RREP(i,len,1)num[i]=0;
		len=1;
		num[1]=1;
	}
	void operator*=(int t){
		int c=0;
		for(int i=1; i<=len||c; i++){
			if(i>len)len=i;
			num[i]*=t;
			num[i]+=c;
			c=num[i]/10;
			num[i]%=10;
		}
	}
	void print(){
		RREP(i,len,1)putchar('0'+num[i]);
	}
}ans;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		if(n>m){
			puts("0 1");
			continue;
		}
		a=m+1-n;
		REP(i,1,n){
			b[i]=m;
			while((g=gcd(b[i],a))>1)
				b[i]/=g,a/=g;
		}
		ans.init();
		REP(i,1,n-1)ans*=m+1;
		ans*=a;
		ans.print();
		putchar(' ');
		ans.init();
		REP(i,1,n)ans*=b[i];
		ans.print();
		putchar('\n');
	}
	return 0;
}

