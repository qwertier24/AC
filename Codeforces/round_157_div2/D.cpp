#include <stdio.h>
#include <algorithm>
#include <cmath>
#define MOD 1000000007
using namespace std;
int d[20][20][10]={0};
long long fact[20],pow_10[20],sum[20]={0},cnt[20]={0}; //1.digit_cnt; 2.number of lucky numbers; 3.first_digit.
void Init(){
	fact[0]=1;
	for(int i=1; i<=10; i++)
		fact[i]=(fact[i-1]*i)%MOD;
	pow_10[0]=1;
	for(int i=1; i<10; i++)
		pow_10[i]=pow_10[i-1]*10;
}
int check(int k){
	return k==4||k==7;
}
int count(int m){
	int ret=0;
	while(m){
		ret+=check(m%10);
		m/=10;
	}
	return ret;
}
void dp(int m){
	int n=(int)log10(m)+1;
	d[0][0][0]=1;
	for(int i=1; i<=n; i++)
		for(int j=0; j<=i; j++)
			for(int k=0; k<10; k++){
				for(int l=0; l<10; l++)
					if(j-check(k)>=0)
						d[i][j][k]=(d[i][j][k]+d[i-1][j-check(k)][l])%MOD;
				//printf("%d %d %d %d\n",i,j,k,d[i][j][k]);
			}
	for(int i=0; i<=n; i++){
		int t=i,tm=m;
		for(int j=n; j>=1; j--){
			int num=tm/pow_10[j-1];
			tm%=pow_10[j-1];
			for(int k=0; k<num; ++k)
				if(t>=0){
					sum[i]=(sum[i]+d[j][t][k])%MOD;
					//printf("%d %lld %d %d %d %d\n",i,sum[i],j,num,k,d[j][t][k]);
				}
			t-=check(num);
		}
		//printf("%d %lld\n",i,sum[i]);
	}
	sum[0]--;
	sum[count(m)]++;
}
long long search(int pos,int rem_sum){
	long long ret=0;
	if(pos==7)
		return 1;
	for(int i=0; i<=rem_sum; i++)
		if(sum[i]>cnt[i]){
			cnt[i]++;
			ret=(ret+(sum[i]-cnt[i]+1)*(search(pos+1,rem_sum-i))%MOD)%MOD;
			cnt[i]--;
		}
	return ret;
}
int solve(int ele_num){
	return (sum[ele_num]*search(1,ele_num-1))%MOD;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	//printf("OK");
	Init();
	int m;
	scanf("%d",&m);
	dp(m);
	int len=(int)log10(m)+1;
	int ans=0;
	for(int i=1; i<=len; i++)
		ans=(ans+solve(i))%MOD;
	printf("%d",ans);
	return 0;
}
