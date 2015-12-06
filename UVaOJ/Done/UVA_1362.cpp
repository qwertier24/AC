#include <stdio.h>
#include <string.h>
#define MOD 1000000000
int d[400][400];
char S[400];
int dp(int l,int r)
{
	if(l==r)return 1;
	if(S[l]!=S[r])return 0;
	if(d[l][r]>=0)return d[l][r];
	d[l][r]=0;
	for(int k=l+2; k<=r; k++)
		if(S[k]==S[l])
			d[l][r]=(d[l][r]+((long long)dp(l+1,k-1)*(long long)dp(k,r)))%MOD;
	//printf("%d %d\n",l,r);
	return d[l][r];
}
int main()
{
	while(scanf("%s",S)==1)
	{
		memset(d,-1,sizeof(d));
		printf("%d\n",dp(0,strlen(S)-1));
	}
	return 0;
}
