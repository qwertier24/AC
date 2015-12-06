#include <stdio.h>
#include <string.h>
int K,d[11][100][100];
long long pow[11]={1,1E1,1E2,1E3,1E4,1E5,1E6,1E7,1E8,1E9,1E10};
int mod(int a)
{
	return (a%K+K)%K;
}
int calc(int m)
{
	int t=m;
	if(m==0)return 0;
	int n=0,a[11],ans=0;
	memset(d,0,sizeof(d));
	d[0][0][0]=1;
	while(m>0)
	{
		a[++n]=m%10;
		m/=10;
	}
	for(int i=0; i<=n-1; i++)
		for(int j=0; j<K; j++)
			for(int k=0; k<K; k++)
				for(int l=0; l<10; l++)
					d[i+1][(j+l)%K][(k+l*pow[i])%K]+=d[i][j][k];
	int s1=0,s2;
	for(int i=n; i>=1; i--)
	{
		for(int j=0; j<a[i]; j++)
		{
			s2=t/pow[i]*pow[i]+pow[i-1]*j;
			ans+=d[i-1][mod(-s1)][mod(-s2)];
			//printf("d[%d][%d][%d]=%d\n",i-1,-s1,-s2,d[i-1][mod(-s1)][mod(-s2)]);
				//printf("d[n][%d][%d]=%d d[n-1][%d][%d]%d\n",(i+k)%K,(i+k*pow[n-1])%K,d[n][(i+k)%K][(i+k*pow[n-1])%K],i,j,d[n-1][i][j]);
			s1++;
		}
	}
	ans--;
	if(t%K==0 && s1%K==0)ans++;
	return ans;
}
int main()
{
	int T,a;
	scanf("%d",&T);
	//T=0;
	//scanf("%d%d",&a,&K);
	//printf("%d\n",calc(a));
	while(T--)
	{
		int a,b;
		scanf("%d%d%d",&a,&b,&K);
		if(K>85)
			printf("0\n");
		else
		{
			printf("%d\n",calc(b)-calc(a-1));
		}
	}
	return 0;
}
