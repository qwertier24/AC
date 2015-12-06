#include<stdio.h>
#include<math.h>
#include<algorithm>
using std::max;
#define N 2600

struct BIGN{
	int num[N],len;
	BIGN(){num[1]=1,len=1;}
	void operator*=(int x){
		int c=0;
		for(int i=1; i<=len||c; i++){
			len=max(len,i);
			num[i]=num[i]*x+c;
			c=num[i]/10;
			num[i]%=10;
		}
	}
	void operator/=(int x){
		for(int i=len,zero=1; i; i--){
			num[i-1]+=num[i]%x*10;
			num[i]/=x;
			if(zero && !num[i])len--;
			if(num[i])zero=0;
		}
	}
	void operator-=(BIGN& r){
		int zero=-1;
		for(int i=1; i<=len; i++){
			num[i]-=r.num[i];
			if(num[i]<0)num[i]+=10,num[i+1]--;
			if(num[i]==0 && zero==-1)zero=i;
			if(num[i])zero=-1;
		}
		if(zero!=-1)len=zero-1;
	}
	void print(){
		for(int i=len; i; i--)
			printf("%d",num[i]);
		puts("");
	}
}a,b;

int n;
int main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
#endif
	scanf("%d",&n);
	for(int i=2; i<=(n<<1); i++)
		a*=i;
	b=a;
	for(int i=2; i<n; i++){
		a/=i*i;
	}
	b=a;
	a/=n*n;
	b/=n*(n+1);
	a-=b;
	a.print();
	return 0;
}
