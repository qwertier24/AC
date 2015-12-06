/*
ID: mayukun3
PROG: comehome
LANG: C++
*/
#include <stdio.h>
#include <algorithm>
#include <ctype.h>
#define Z 25
#define n 52
#define INF 200000
using namespace std;
int G[70][70];
int trans(char x)
{
	if(isupper(x))
		return x-'A';
	else
		return x-'a'+26;
}
int main()
{
	freopen("comehome.in","r",stdin);
	freopen("comehome.out","w",stdout);
	int q,l,ans=INF;
	char f,t,ans_c;
	scanf("%d",&q);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			G[i][j]=INF;
	for(int i=1; i<=q; i++)
	{
		char s[10];
		scanf("%s",s);
		f=s[0];
		scanf("%s",s);
		t=s[0];
		scanf("%d",&l);
		G[trans(f)][trans(t)]=min(G[trans(f)][trans(t)],l);
		G[trans(t)][trans(f)]=min(G[trans(t)][trans(f)],l);
	}
	for(int i=0; i<n; i++)
		G[i][i]=0;
	for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
	for(int i=0; i<Z; i++)
		if(ans>G[i][Z])
		{
			ans_c=i+'A';
			ans=min(ans,G[i][Z]);
		}
	printf("%c %d\n",ans_c,ans);
	return 0;
}