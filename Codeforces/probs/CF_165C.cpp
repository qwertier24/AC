#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
char s[1000010];
int cnt=0,k,n;
long long r[1000010]={0},sum[1000010]={0};
void Init(){
	for(int i=1; i<=1000010; i++)
		sum[i]=sum[i-1]+i;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	Init();
	scanf("%d%s",&k,s+1);
	n=strlen(s+1);
	//printf("%d",n);
	s[0]='1';
	int p=0;
	for(int i=0; i<=n; i=p+1){
		p=i;
		while(p<n&&s[p+1]=='0')
			p++;
		//cout<<p;
		r[cnt]=p-i;
		//printf("%d %d %d\n",i,cnt,r[cnt]);
		cnt++;
		if(i>n)break;
	}
	//printf("%d",p);
	long long ans=0;
	if(k==0){
		for(int i=0; i<cnt; i++)
			ans+=sum[r[i]];
		cout<<ans;
	}
	else{
		for(int i=k; i<cnt; i++){
		//printf("%d %d %d\n",i,r[i-k],r[i]);
		ans+=(r[i-k]+1)*(r[i]+1);
		}
		cout<<ans;
	}
	return 0;
}
