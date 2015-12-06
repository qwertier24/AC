#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <iostream>
#define MOD 1000000l
using namespace std;
int defn=0,atkn=0,atk[101],def[101],strength,str[101],ans=0;
long long d[101][101][101];
char s[10];
int main()
{
	int n,m;
//	freopen("prob.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
	{
		scanf("%s%d",s,&strength);
		if(s[0]=='A')
			atk[++atkn]=strength;
		else
			def[++defn]=strength;
	}
	sort(atk+1,atk+atkn+1);
	sort(def+1,def+defn+1);
	for(int i=1; i<=m; i++)
	{
		scanf("%d",&str[i]);
	}
	sort(str+1,str+m+1);
	memset(d,-1,sizeof(d));
	d[0][0][0]=0;
	atk[0]=def[0]=MOD;
	for(int k=1; k<=m; k++)
	{
		for(int i=0; i<=atkn; i++)
			for(int j=0; j<=defn; j++)
			{
				if(d[k-1][i][j]!=-1)
					d[k][i][j]=d[k-1][i][j]+str[k];
				if(str[k]>=atk[i]&&d[k-1][i-1][j]!=-1&&i!=0)
				{
					d[k][i][j]=max(d[k][i][j],d[k-1][i-1][j]+((long long)str[k]-atk[i])*MOD);
				}
				if(str[k]>def[j]&&d[k-1][i][j-1]!=-1&&j!=0)
					d[k][i][j]=max(d[k][i][j],d[k-1][i][j-1]);
				ans=max((long long)ans,d[k][i][j]/MOD);
				//printf("%d %d %d %I64d %d\n",str[k],atk[i],def[j],d[k][i][j],ans);
			}
		if(d[k][atkn][defn]!=-1)
			ans=max((long long)ans,d[k][atkn][defn]/MOD+d[k][atkn][defn]%MOD);
	}
	printf("%d\n",ans);
	return 0;
}
