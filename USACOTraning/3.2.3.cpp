/*
ID: mayukun3
PROG: kimbits
LANG: C++
*/
#include <stdio.h>
long long I,L,N,d[100][100]={0},ans=0,cnt[100][100]={0};
int main()
{
	freopen("kimbits.in","r",stdin);freopen("kimbits.out","w",stdout);
	scanf("%lld%lld%lld",&N,&L,&I);
	int b=2;
	d[0][0]=1;
	for(int i=0; i<=L; i++)
		cnt[0][i]=1;
	for(int i=1; i<=N; i++)
	{
		d[i][0]=1;
		cnt[i][0]=1;
		for(int j=1; j<=i; j++)
			d[i][j]+=d[i-1][j-1]+d[i-1][j];
		for(int j=1; j<=L; j++)
			cnt[i][j]=d[i][j]+cnt[i][j-1];
	}
	for(int i=1; i<=N; i++)
		for(int j=0; j<=L; j++)
		{
			//printf("cnt[%d][%d]=%d\n",i,j,cnt[i][j]);
		}
	//printf("%lld\n",I);
	for(int i=N; i>=1; i--)
		if(cnt[i][L]>=I && cnt[i-1][L]<I)
		{
			I-=cnt[i-1][L];
			L--;
			ans|=1<<(i-1);
		//	printf("%d\n",ans);
		}
	if(b==1)
	{
		for(int i=1; i<=N; i++)
			printf("0");
		printf("\n");
	}
	else
	{
		for(int i=N; i>=1; i--)
			printf("%d",(ans>>(i-1))&1);
		printf("\n");
	}
	return 0;
}