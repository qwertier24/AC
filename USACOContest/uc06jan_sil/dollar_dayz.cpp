#include <stdio.h>
#include <algorithm>
using namespace std;
struct BIGN{
	int len,num[200];
	void operator+=(const BIGN& t){
		len=max(len,t.len);
		int c=0;
		for(int i=1; i<=len||c; i++){
			if(len<i)len=i;
			num[i]+=t.num[i]+c;
			c=num[i]/10;
			num[i]%=10;
		}
	}
	void print(){
		for(int i=len; i>=1; i--)
			printf("%d",num[i]);
	}
}d[1010]={0};
int main(){
#ifndef ONLINE_JUDGE
	freopen("prob.in","r",stdin);
#endif
	int n,k;
	d[0].len=1;
	d[0].num[1]=1;
	scanf("%d%d",&n,&k);
	for(int i=1; i<=k; i++)
		for(int j=i; j<=n; j++){
			if(d[j-i].len)
				d[j]+=d[j-i];
			//if(d[j])
				//printf("%d %d %d\n",i,j,d[j]);
		}
	d[n].print();
	return 0;
}
