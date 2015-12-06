#include<stdio.h>
#include<algorithm>
#include<iostream>
#define MOD 100003
using namespace std;

long long m,n;
long long fast_pow(long long a,long long p){
	if(a==0)return 0;
	long long ret=1,t=a%MOD;
	while(p){
		if(p&1)ret=(ret*t)%MOD;
		t=(t*t)%MOD;
		p>>=1;
	}
	return ret;
}
int main(){
	cin>>m>>n;
	cout<<((fast_pow(m,n)-(m%MOD*fast_pow(m-1,n-1))%MOD)%MOD+MOD)%MOD;
	return 0;
}
