#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
typedef long long ULL;
using namespace std;
const int maxn=12;
int cnt[12];
ULL fact[maxn+5],pow10[maxn+5],one[maxn+5];
void Init()
{
	fact[0]=1;
	for(int i=1; i<=maxn; i++)
		fact[i]=fact[i-1]*i;
	pow10[0]=1;
	for(int i=1; i<=maxn; i++)
		pow10[i]=pow10[i-1]*10;
	one[0]=0;
	for(int i=1; i<=maxn; i++)
		one[i]=one[i-1]+pow10[i-1];
}
int main()
{
	Init();
	int n;
	//cout<<' '<<one[10];
	while(scanf("%d",&n)&&n)
	{
		memset(cnt,0,sizeof(cnt));
		ULL sum=0;
		for(int i=1; i<=n; i++)
		{
			int nt;
			scanf("%d",&nt);
			cnt[nt]++;
			sum+=nt;
		}
		ULL total_cnt=fact[n-1]*sum;
		for(int i=0; i<=9; i++)
			total_cnt/=fact[cnt[i]];
		cout<<total_cnt*one[n]<<endl;
	}
	return 0;
}
